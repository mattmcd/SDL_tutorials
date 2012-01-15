// ==============================================================
// 
//       Filename:  ShowBackground.cpp
// 
//    Description:  See
//    http://lazyfoo.net/SDL_tutorials/lesson01/index2.php
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
  s.w = 400;
  s.h = 300;

  sdl.init_screen( s.w, s.h );
  
  // Background image
  SDLImage bg( "tile100x100v03glide.jpg" );

  for (int x=0; x<s.w; x += 100 )
    for (int y=0; y<s.h; y+=100 )
      sdl.blit_surface( bg, x, y );

  // Image with color keyed transparency
  SDLImage theImage( fileName );
  theImage.setTransparent( 68, 68, 68);

  // Image without transparency
  // TODO: Copy method for underlying surface
  SDLImage nonTransImage( fileName );

  // Offset for edge of screen
  int imHalfWidth = floor(theImage.get_width()/2);

  // Non-transparent image
  sdl.blit_surface( nonTransImage, floor(s.w/4) - imHalfWidth,
    floor(s.h/2) - floor(theImage.get_height() / 2));
  
  // Transparent image
  sdl.blit_surface( theImage, 3*floor(s.w/4) - imHalfWidth,
    floor(s.h/2) - floor(theImage.get_height() / 2));

  sdl.flip( );

  // Display until window exit has been clicked
  bool done( false );
  // Structure to hold the event
  SDL_Event event;

  while( !done )
  {
    // While there is an event to handle, process events
    while( SDL_PollEvent( &event ) )
    {
      if( event.type == SDL_QUIT )
      {
        // Quit the program
        done = true;
      }
    }
  }

  return 0;
}

int main( int argc, char* argv[])
{
  SDL_Wrapper& sdl = SDL_Wrapper::Instance();

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
