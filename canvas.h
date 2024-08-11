#pragma once
#include "screen.h"
#include "front_end.h"
#include <raylib.h>
using namespace std;

class canvas:public practical_screen
{
public:
	canvas();
	void draw_canvas();
	~canvas();

private:

};