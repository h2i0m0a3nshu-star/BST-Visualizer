#pragma once
#include "screen.h"
#include <raylib.h>
using namespace std;

class game
{
public:
	game() = delete;
	game(const int width, const int height);
	game(game &other) = delete;
	void tick();
	bool should_close();
	~game() noexcept;

private:
	int width, height;

	screen* curr_screen, * next_screen;

	void draw();
	void update();
};
