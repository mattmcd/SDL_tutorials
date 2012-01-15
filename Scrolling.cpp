// ==============================================================
// 
//       Filename:  Scrolling.cpp
// 
//    Description:  See
//    http://lazyfoo.net/SDL_tutorials/lesson21/index.php
// 
//        Version:  1.0
//        Created:  02/01/12 19:53:09
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Matt McDonnell (MMcD), matt@matt-mcdonnell.com
//        Company:  
// 
// ==============================================================

#include "SDLImage.hpp"
#include "SDL_Wrapper.hpp"
#include "Camera.hpp"
#include <SDL/SDL.h>
#include <iostream>
#include <math.h>

int main_loop(const std::string fileName, SDL_Wrapper &sdl)
{
  // Screen dimensions
  typedef struct {
  int w;
  int h;
  } ScreenDim;

  ScreenDim s;
  s.w = 480;
  s.h = 320;

  // Level dimensions
  ScreenDim level;
  level.w = 640;
  level.h = 480;

  // Camera position
  int camLimitX = floor( (level.w - s.w)/2);
  int camLimitY = floor( (level.h - s.h)/2);

  // Define camera
  Camera theCamera( camLimitX, camLimitY );
  t_camPos camPos;

  // Create the screen
  sdl.init_screen( s.w, s.h );
  
  // Background image
  SDLImage bg( "tile100x100v03glide.jpg" );

  // Image with color keyed transparency
  SDLImage theImage( fileName );
  theImage.setTransparent( 68, 68, 68);

  // Image without transparency
  // TODO: Copy method for underlying surface
  SDLImage nonTransImage( fileName );

  // Display until window exit has been clicked
  bool done( false );
  // Structure to hold the event
  SDL_Event event;

  while( !done )
  {
    // Draw background and images
    camPos = theCamera.get_position();

    for (int x=0; x<level.w; x += 100 )
      for (int y=0; y<level.h; y+=100 )
        sdl.blit_surface( bg, x-camPos.X, y-camPos.Y );
    // Offset for edge of screen
    int imHalfWidth = floor(theImage.get_width()/2);

    // Non-transparent image
    sdl.blit_surface( nonTransImage, 
      floor(level.w/4) - imHalfWidth - camPos.X,
      floor(level.h/2) - floor(theImage.get_height() / 2) - camPos.Y);
    
    // Transparent image
    sdl.blit_surface( theImage, 
      3*floor(level.w/4) - imHalfWidth - camPos.X,
      floor(level.h/2) - floor(theImage.get_height() / 2) - camPos.Y);

    sdl.flip( );
    // While there is an event to handle, process events
    while( SDL_PollEvent( &event ) )
    {
      if( event.type == SDL_QUIT )
      {
        // Quit the program
        done = true;
      }
      if ( event.type == SDL_KEYDOWN )
      {
        done = theCamera.handle_event( event );
      }
    }
  }

  return 0;
}

int main( int argc, char* argv[])
{
  SDL_Wrapper sdl;

  if ( sdl.get_init_success() < 0 )
  {
    // Early exit
    std::cout << "SDL initialisation failed.  Exiting." << std::endl;
    return -1;
  }

  sdl.set_title( "Image Transparency and Background" );

  std::string fileName("smiley_col_thumb.png");

  return main_loop( fileName, sdl );
}
