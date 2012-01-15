// ==============================================================
// 
//       Filename:  ScrollCamera.cpp
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

#include "ScrollCamera.hpp"
#include <math.h>

ScrollCamera::ScrollCamera( int limX_, int limY_) :
  camLimitX( limX_), camLimitY( limY_ ) 
{
  camPosX = 0;
  camPosY = 0;
  camVelX = 0;
  camVelY = 0;
};

bool ScrollCamera::handle_event( SDL_Event event )
{
  bool done = false;
  if ( event.type == SDL_KEYDOWN )
  {
        switch( event.key.keysym.sym )
        {
          case SDLK_UP:
            camVelY = -1;
            break;
          case SDLK_DOWN:
            camVelY = +1;
            break;
          case SDLK_LEFT:
            camVelX = -1;
            break;
          case SDLK_RIGHT:
            camVelX = +1;
            break;
          case SDLK_q:
            done = true;
            break;
        }        
  }
  if ( event.type == SDL_KEYUP )
  {
    // Stop scrolling
    camVelX = 0;
    camVelY = 0;
  }
  return done;
}

t_camPos ScrollCamera::get_position()
{
  camPosX = std::min( std::max(camPosX + camVelX, 0), camLimitX);
  camPosY = std::min( std::max(camPosY + camVelY, 0), camLimitY);
  t_camPos pos;
  pos.X = camPosX;
  pos.Y = camPosY;
  return pos;
}
