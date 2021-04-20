#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_


 #include<Windows.h>
#include<SDL.h>
#include<SDL_image.h>
#include<string>
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
const int NUM_CHICKEN = 3;
const int NUM_BOSS = 2;
static SDL_Surface *g_screen = NULL;
static SDL_Surface *g_bkground = NULL;
static SDL_Surface *g_object;   
static SDL_Event g_even;
namespace SDL_CF
{ SDL_Surface* LoadImage(std::string file_path);
 void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
void CleanUp();
bool checkcollision(const SDL_Rect& object1,const SDL_Rect& object2);
}
#endif