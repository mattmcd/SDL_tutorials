// ==============================================================
// 
//       Filename:  StepCamera.hpp
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

#ifndef STEPCAMERA_HPP
#define STEPCAMERA_HPP

#include "Camera.hpp"

class StepCamera : public Camera {
public:
  StepCamera(int camLimitX_, int camLimitY_ );
  virtual bool handle_event( SDL_Event event );
  virtual t_camPos get_position(void);
  virtual ~StepCamera() {};
private:
  int camPosX;
  int camPosY;
  int camLimitX;
  int camLimitY;
  int camStep;
};

#endif
