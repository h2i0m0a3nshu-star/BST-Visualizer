#pragma once
#include "textbox.h"
#include <raylib.h>
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
	int MAX_ELEMENT;
	int array[200];
	int delay;
	int selector_x, selector_y;
	int curr_element_num;

	const char* errmsg;

	bool error, init, show_textbox;

	textbox number;

	// Initialization methods
	void draw_init();
	void update_init();

	// Error handling methods
	void draw_error();
	void update_error();

	bool isFULL();
	bool isEMPTY();

	void delay_handler();
};

class theory_screen :public screen {
public:
	void draw_screen() override;
	screen* update_screen() override;
private:

};