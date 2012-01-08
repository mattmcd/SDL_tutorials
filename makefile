all: ShowImage 

ShowImage: ShowImage.cpp SDLImage.h SDLImage.cpp
	g++ -o ShowImage SDLImage.cpp ShowImage.cpp -lSDL -lSDL_image
