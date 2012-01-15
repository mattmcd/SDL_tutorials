// ==============================================================
// 
//       Filename:  CameraFactory.hpp
// 
//    Description:  Factory for camera objects
// 
//        Version:  1.0
//        Created:  15/01/12 18:26:49
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Matt McDonnell (MMcD), matt@matt-mcdonnell.com
//        Company:  
// 
// ==============================================================

#ifndef CAMERAFACTORY_H
#define CAMERAFACTORY_H

#include "Camera.hpp"
#include <iostream>
#include <tr1/memory>

typedef std::tr1::shared_ptr<Camera> cam_ptr;

class CameraFactory {
public:
  cam_ptr getCamera( std::string cam_type, int x, int y );
  static CameraFactory& Instance();
  ~CameraFactory() {};
private:
  CameraFactory() {};
};

#endif
