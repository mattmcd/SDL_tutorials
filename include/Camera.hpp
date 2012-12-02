// ==============================================================
// 
//       Filename:  Camera.hpp
// 
//    Description:  Camera defining view of level
// 
//        Version:  1.0
//        Created:  15/01/12 16:42:21
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Matt McDonnell (MMcD), matt@matt-mcdonnell.com
//        Company:  
// 
// ==============================================================

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SDL.h>
#include <algorithm>

typedef struct {
  int X;
  int Y;
} t_camPos;

class Camera {
public:
  Camera() {};
  virtual bool handle_event( SDL_Event event ) =0;
  virtual t_camPos get_position(void) =0;
  virtual ~Camera() {};
private:
};

#endif
