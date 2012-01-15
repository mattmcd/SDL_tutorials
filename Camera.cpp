// ==============================================================
// 
//       Filename:  Camera.cpp
// 
//    Description:  Camera class representing view of current level 
// 
//        Version:  1.0
//        Created:  15/01/12 16:31:11
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Matt McDonnell (MMcD), matt@matt-mcdonnell.com
//        Company:  
// 
// ==============================================================

#include "Camera.hpp"
#include <math.h>

Camera::Camera( int camLimitX_, int camLimitY_ ) :
  camLimitX( camLimitX_ ), camLimitY( camLimitY_ ) 
{
  camPosX = 0;
  camPosY = 0;
  camStep = 10;
};

bool Camera::handle_event( SDL_Event event )
{
  bool done = false;
  if ( event.type == SDL_KEYDOWN )
  {
        switch( event.key.keysym.sym )
        {
          case SDLK_UP:
            camPosY = std::max(0, camPosY - camStep);
            break;
          case SDLK_DOWN:
            camPosY = std::min(camLimitY, camPosY + camStep);
            break;
          case SDLK_LEFT:
            camPosX = std::max(0, camPosX - camStep);
            break;
          case SDLK_RIGHT:
            camPosX = std::min(camLimitX, camPosX + camStep);
            break;
          case SDLK_q:
            done = true;
            break;
        }        
  }
  return done;
}

t_camPos Camera::get_position()
{
  t_camPos pos;
  pos.X = camPosX;
  pos.Y = camPosY;
  return pos;
}
