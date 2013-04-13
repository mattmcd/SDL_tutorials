all: ShowImage

ShowImage: ShowImage.cpp include/SDLImage.hpp SDLImage.cpp include/SDL_Wrapper.hpp SDL_Wrapper.cpp
	${CXX} ${CC_SDL} -Iinclude SDLImage.cpp ShowImage.cpp SDL_Wrapper.cpp -lSDL -lSDL_image 

ShowBackground: ShowBackground.cpp include/SDLImage.hpp SDLImage.cpp include/SDL_Wrapper.hpp SDL_Wrapper.cpp
	${CXX} -o ShowBackground -Iinclude SDLImage.cpp ShowBackground.cpp SDL_Wrapper.cpp -lSDL -lSDL_image

Scrolling: Scrolling.cpp include/SDLImage.hpp SDLImage.cpp include/SDL_Wrapper.hpp SDL_Wrapper.cpp include/Camera.hpp include/StepCamera.hpp StepCamera.cpp include/CameraFactory.hpp CameraFactory.cpp
	${CXX} -o Scrolling -Iinclude SDLImage.cpp Scrolling.cpp CameraFactory.cpp SDL_Wrapper.cpp StepCamera.cpp ScrollCamera.cpp -lSDL -lSDL_image