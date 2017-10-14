#include <Windows.h>
#include <stdio.h>
#include "Raindrop.h"


void initraindrops(int pos) {
	
	raindrops[pos].x = (float)(rand() % 41) - 10;
	raindrops[pos].y = 10.0;
	raindrops[pos].z = (float)(rand() % 41) - 10;

	raindrops[pos].speed = -10.0f;

	raindrops[pos].scope = 1.0f;
	raindrops[pos].scopeLife = (float)(rand() % 100)/100 +0.003;
}


//function prototype