// ==============================================================
// 
//       Filename:  Lesson01_Image.cpp
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

#include "SDLImage.h"
#include <SDL/SDL.h>
#include <iostream>

void main_loop(const std::string fileName)
{

  SDLImage theImage( fileName );

  SDL_Delay( 100 );

  SDLImage screen( 
    SDL_SetVideoMode( theImage.get_width(), theImage.get_height(), 
    32, SDL_SWSURFACE ) );

  SDL_BlitSurface( theImage.getPtr(), NULL, screen.getPtr(), NULL);

  SDL_Flip( screen.getPtr() );

  SDL_Delay( 2000 );

}

int main( int argc, char* argv[])
{
  SDL_Init( SDL_INIT_EVERYTHING );

  std::string fileName;

  if ( argc < 2 )
    fileName = "mattmcd_sketch.bmp";
  else
    fileName = argv[1];

  main_loop( fileName );

  SDL_Quit();

  return 0;
}
