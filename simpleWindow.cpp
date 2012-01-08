// See:
// http://pbeblog.wordpress.com/2008/06/25/how-to-make-a-simple-window-in-sdl/
#include "SDL/SDL.h"

SDL_Surface* screen;
SDL_Event event;

int main( int argc, char* argv[])
{
  SDL_Init( SDL_INIT_VIDEO );
  screen = SDL_SetVideoMode( 640, 480, 16, SDL_SWSURFACE);
  SDL_WM_SetCaption("Simple Window", "Simple Window");
  bool done = false;

  while ( !done ) 
  {
    while( SDL_PollEvent( &event ) )
    {
      if( event.type == SDL_QUIT )
      {
        done = true;
      }
    }
    // Fill the screen with black
    SDL_FillRect( screen, &screen->clip_rect, 
      SDL_MapRGB( screen->format, 0, 0, 0));
    // update the screen buffer
    SDL_Flip( screen );
  }

  SDL_Quit();

  return 0;
}
