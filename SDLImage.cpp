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
  surf_ptr loadedImage( IMG_Load( fileName.c_str() ), SDL_FreeSurface);
  if ( loadedImage != NULL )
  {
    // Create an optimzed image
    surf = surf_ptr(SDL_DisplayFormat( loadedImage.get() ), SDL_FreeSurface);
    if ( surf == NULL )
    {
      // Conversion can fail, for example if the primary screen has not yet
      // been initialized.  In this case reuse the original image.
      surf = loadedImage;
    } 
  }
}

SDLImage::SDLImage( SDL_Surface* surf_ ): surf(surf_, SDL_FreeSurface) {}

SDLImage::~SDLImage() {}
/* 
{
  if ( surf != NULL )
  {
    // Free the surface
    //SDL_FreeSurface( surf.get() );
    std::cout << "Destroyed SDL Image" << std::endl;
  }
}
*/

SDL_Surface* SDLImage::getPtr() const
{
  return surf.get();
}


int SDLImage::get_width ( ) const
{
  return surf->w;
}		// -----  end of method SDLImage::get_width  -----

int SDLImage::get_height ( ) const
{
  return surf->h;
}		// -----  end of method SDLImage::get_height  -----

