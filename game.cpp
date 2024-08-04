#include "game.h"

game::game(const int width, const int height)
{
	this->width = width;
	this->height = height;
	curr_screen = new theory_screen();
	next_screen = new theory_screen();

	InitWindow(width,height,"BINARY SEARCH TREE VISUALIZER");
	SetTargetFPS(60);

}

void game::tick() {
	draw();
	update();
}

bool game::should_close() {
	return WindowShouldClose();
}

void game::draw() {
	BeginDrawing();
	
	ClearBackground(BLACK);
	// Screen Logo & instruction
	DrawText("BST VISUALIZER", GetScreenWidth() / 20, GetScreenHeight() / 20 - 20, 30, GREEN);
	DrawLine(0, GetScreenHeight() / 20 + 15, GetScreenWidth(), GetScreenHeight() / 20 + 15, GREEN);
	DrawText("Press F to toggle fullscreen", 10, GetScreenHeight() - 25, 20, GREEN);

	curr_screen->draw_screen();
	EndDrawing();
}

void game::update() {
	if (IsKeyPressed(KEY_F)) {
		if (IsWindowFullscreen()) {
			ToggleFullscreen();
			SetWindowSize(width, height);
		}
		else {
			ToggleFullscreen();
		}
	}

	next_screen = next_screen->update_screen();
	if (next_screen != curr_screen) {
		delete curr_screen;
		curr_screen = next_screen;
	}

}

game::~game() {
	CloseWindow();
}