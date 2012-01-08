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

class SDL_Wrapper {
public:
  SDL_Wrapper();
  ~SDL_Wrapper();
  int get_init_success();
private:
  int init_success;
};


#endif
