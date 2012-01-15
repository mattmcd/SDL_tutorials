// ==============================================================
// 
//       Filename:  ScrollCamera.hpp
// 
//    Description:  Camera defining view of level with scroll movement
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

#ifndef SCROLLCAMERA_HPP
#define SCROLLCAMERA_HPP

#include "Camera.hpp"

class ScrollCamera : public Camera {
public:
  ScrollCamera( int, int );
  virtual bool handle_event( SDL_Event event );
  virtual t_camPos get_position(void);
  virtual ~ScrollCamera() {};
private:
  int camLimitX;
  int camLimitY;
  int camPosX;
  int camPosY;
  int camVelX;
  int camVelY;
};

#endif
