all: ShowImage 

ShowImage: ShowImage.cpp SDLImage.hpp SDLImage.cpp SDL_Wrapper.hpp SDL_Wrapper.hpp
	g++ -o ShowImage SDLImage.cpp ShowImage.cpp SDL_Wrapper.cpp -lSDL -lSDL_image
