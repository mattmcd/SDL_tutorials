// ==============================================================
// 
//       Filename:  SDLImage.h
// 
//    Description:  Wrapper for SDL_surface
// 
//        Version:  1.0
//        Created:  02/01/12 19:50:05
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Matt McDonnell (MMcD), matt@matt-mcdonnell.com
//        Company:  
// 
// ==============================================================

#ifndef SDLIMAGE_H
#define SDLIMAGE_H

#include <SDL/SDL.h>
#include <tr1/memory>
#include <string>

typedef std::tr1::shared_ptr<SDL_Surface> surf_ptr;

class SDLImage {
  public:
    SDLImage(const std::string &fileName);
    SDLImage(SDL_Surface* surf_);
    ~SDLImage();
    SDL_Surface* getPtr();
    int get_width();
    int get_height();
  private:
    surf_ptr surf;
};

#endif
