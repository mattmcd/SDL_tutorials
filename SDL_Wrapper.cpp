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
