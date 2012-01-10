// ==============================================================
// 
//       Filename:  SDL_Wrapper.hpp
// 
//    Description:  Wrapper to SDL interface
// 
//        Version:  1.0
//        Created:  08/01/12 18:18:48
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Matt McDonnell (MMcD), matt@matt-mcdonnell.com
//        Company:  
// 
// ==============================================================

#ifndef SDL_WRAPPER_HPP
#define SDL_WRAPPER_HPP

#include <SDL/SDL.h>
#include "SDLImage.hpp"

class SDL_Wrapper {
public:
  SDL_Wrapper();
  ~SDL_Wrapper();
  int get_init_success();
  void init_screen( int width, int height );
  void blit_surface( const SDLImage &img) const;
  void blit_surface( const SDLImage &img, int x, int y) const;
  void set_title( const std::string title ) const;
  void flip();
private:
  int init_success;
  SDL_Surface* screen;
};


#endif
