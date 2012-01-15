all: ShowImage ShowBackground Scrolling

ShowImage: ShowImage.cpp SDLImage.hpp SDLImage.cpp SDL_Wrapper.hpp SDL_Wrapper.cpp
	g++ -o ShowImage SDLImage.cpp ShowImage.cpp SDL_Wrapper.cpp -lSDL -lSDL_image

ShowBackground: ShowBackground.cpp SDLImage.hpp SDLImage.cpp SDL_Wrapper.hpp SDL_Wrapper.cpp
	g++ -o ShowBackground SDLImage.cpp ShowBackground.cpp SDL_Wrapper.cpp -lSDL -lSDL_image

Scrolling: Scrolling.cpp SDLImage.hpp SDLImage.cpp SDL_Wrapper.hpp SDL_Wrapper.cpp Camera.hpp Camera.cpp
	g++ -o Scrolling SDLImage.cpp Scrolling.cpp SDL_Wrapper.cpp Camera.cpp -lSDL -lSDL_image
