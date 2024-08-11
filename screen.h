#pragma once
#include "BST.h"
#include "textbox.h"
#include <iostream>
#include <raylib.h>
#include <math.h>
using namespace std;

class screen {
public:
	virtual void draw_screen() = 0;
	virtual screen *update_screen() = 0;
private:

};

class practical_screen :public screen {
public:
	practical_screen();
	void draw_screen() override;
	screen* update_screen() override;
private:
	BST binary_search_tree;

	int delay;
	int selector_x, selector_y;

	const char* errmsg;

	bool error, show_textbox;

	textbox number;

	// Error handling methods
	void draw_error();
	void update_error();

	void delay_handler();
};

class theory_screen :public screen {
public:
	void draw_screen() override;
	screen* update_screen() override;
private:

};