// ==============================================================
// 
//       Filename:  SDLImage.cpp
// 
//    Description:  Implementation of SDLImage wrapper
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
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

SDLImage::SDLImage( const std::string &fileName )
{
  surf = IMG_Load( fileName.c_str() );
  /* 
  SDL_Surface* loadedImage = IMG_Load( fileName.c_str() );
  if ( loadedImage != NULL )
  {
    // Create and optimzed image
    surf = SDL_DisplayFormat( loadedImage );
    // Free the temporary loaded image
    SDL_FreeSurface( loadedImage );
  }
  */
  // surf = SDL_LoadBMP( fileName );
}

SDLImage::SDLImage( SDL_Surface* surf_ ): surf(surf_) {}

SDLImage::~SDLImage()
{
  if ( surf != NULL )
  {
    // Free the surface
    SDL_FreeSurface( surf );
    std::cout << "Freed the SDL surface" << std::endl;
  }
}

SDL_Surface* SDLImage::getPtr()
{
  return surf;
}


int SDLImage::get_width ( )
{
  return surf->w;
}		// -----  end of method SDLImage::get_width  -----

int SDLImage::get_height ( )
{
  return surf->h;
}		// -----  end of method SDLImage::get_height  -----

