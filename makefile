all: ShowImage ShowBackground Scrolling ContinueScrolling

ShowImage: ShowImage.cpp SDLImage.hpp SDLImage.cpp SDL_Wrapper.hpp SDL_Wrapper.cpp
	g++ -o ShowImage SDLImage.cpp ShowImage.cpp SDL_Wrapper.cpp -lSDL -lSDL_image

ShowBackground: ShowBackground.cpp SDLImage.hpp SDLImage.cpp SDL_Wrapper.hpp SDL_Wrapper.cpp
	g++ -o ShowBackground SDLImage.cpp ShowBackground.cpp SDL_Wrapper.cpp -lSDL -lSDL_image

Scrolling: Scrolling.cpp SDLImage.hpp SDLImage.cpp SDL_Wrapper.hpp SDL_Wrapper.cpp Camera.hpp StepCamera.hpp StepCamera.cpp CameraFactory.hpp CameraFactory.cpp
	g++ -o Scrolling SDLImage.cpp Scrolling.cpp CameraFactory.cpp SDL_Wrapper.cpp StepCamera.cpp ScrollCamera.cpp -lSDL -lSDL_image

ContinueScrolling: ContinueScrolling.cpp SDLImage.hpp SDLImage.cpp SDL_Wrapper.hpp SDL_Wrapper.cpp Camera.hpp ScrollCamera.hpp ScrollCamera.cpp
	g++ -o ContinueScrolling SDLImage.cpp ContinueScrolling.cpp SDL_Wrapper.cpp ScrollCamera.cpp -lSDL -lSDL_image
