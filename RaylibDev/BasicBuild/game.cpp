#include "raylib.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;



void initGame(void); // init the entities before each draw
void updateGame(void); // update game entities during each frame
void drawGame(void); // draw the current entities
void releaseMemory(void); // endgame cleanup
void updateDrawFrame(void); // updateGame + drawGame


