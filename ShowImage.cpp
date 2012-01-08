// ==============================================================
// 
//       Filename:  ShowImage.cpp
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

void main_loop(const std::string fileName, SDL_Wrapper &sdl)
{

  SDLImage theImage( fileName );

  sdl.init_screen( theImage.get_width(), theImage.get_height() );

  sdl.blit_surface( theImage.getPtr() );

  sdl.flip( );

  SDL_Delay( 2000 );

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

  std::string fileName;

  if ( argc < 2 )
    fileName = "mattmcd_sketch.bmp";
  else
    fileName = argv[1];

  main_loop( fileName, sdl );

  return 0;
}
