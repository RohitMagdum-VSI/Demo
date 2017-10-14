#pragma once
#define RAINDROPS 1000

typedef struct
{
	float x;
	float y;
	float z;
	float speed;
	float scope;
	float scopeLife;

}RAINDROP;

extern RAINDROP raindrops[RAINDROPS];

extern float gzDepth;
extern float gGravity;

void initraindrops(int pos);
