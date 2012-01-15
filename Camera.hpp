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

#include <SDL/SDL.h>
#include <algorithm>

typedef struct {
  int X;
  int Y;
} t_camPos;

class Camera {
public:
  Camera(int camLimitX_, int camLimitY_ );
  bool handle_event( SDL_Event event );
  t_camPos get_position(void);
private:
  int camPosX;
  int camPosY;
  int camLimitX;
  int camLimitY;
  int camStep;
};

#endif
