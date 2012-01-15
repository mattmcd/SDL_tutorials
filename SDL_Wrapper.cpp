// ==============================================================
// 
//       Filename:  SDL_Wrapper.cpp
// 
//    Description:  Wrapper object for the interface to SDL.  This class is
//                  responsible for initialising and destroying the
//                  interface.
// 
//        Version:  1.0
//        Created:  08/01/12 18:17:56
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Matt McDonnell (MMcD), matt@matt-mcdonnell.com
//        Company:  
// 
// ==============================================================

#include "SDL_Wrapper.hpp"

SDL_Wrapper& SDL_Wrapper::Instance() 
{
  static SDL_Wrapper theWrapper;
  return theWrapper;
}

SDL_Wrapper::SDL_Wrapper()
{
  init_success = SDL_Init( SDL_INIT_EVERYTHING );
}

SDL_Wrapper::~SDL_Wrapper()
{
  SDL_Quit();
}

int SDL_Wrapper::get_init_success()
{
  return init_success;
}

void SDL_Wrapper::init_screen( int width, int height)
{
  screen = SDL_SetVideoMode( width, height, 32, SDL_SWSURFACE );
}

void SDL_Wrapper::blit_surface( const SDLImage &img) const
{
  SDL_BlitSurface( img.getPtr(), NULL, screen, NULL );
}

void SDL_Wrapper::blit_surface( const SDLImage &img, int x, int y) const
{
  // Blit with offset
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  SDL_BlitSurface( img.getPtr(), NULL, screen, &offset );
}

void SDL_Wrapper::set_title( const std::string title ) const 
{
  SDL_WM_SetCaption( title.c_str(), NULL);
}

void SDL_Wrapper::flip() 
{
  SDL_Flip( screen );
}
