// ==============================================================
// 
//       Filename:  CameraFactory.cpp
// 
//    Description:  Camera factory implementation
// 
//        Version:  1.0
//        Created:  15/01/12 18:29:38
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Matt McDonnell (MMcD), matt@matt-mcdonnell.com
//        Company:  
// 
// ==============================================================

#include "CameraFactory.hpp"
#include "StepCamera.hpp"
#include "ScrollCamera.hpp"

cam_ptr CameraFactory::getCamera(std::string name, int x, int y)
{
  if (name == "step" )
    return cam_ptr( new StepCamera(x, y));
  
  return cam_ptr( new ScrollCamera(x, y));
}

CameraFactory& CameraFactory::Instance()
{
  static CameraFactory theFactory;
  return theFactory;
}
