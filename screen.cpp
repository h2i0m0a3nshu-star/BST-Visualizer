#include "screen.h"

void theory_screen::draw_screen()
{
	DrawText("Theory To be Loaded", GetScreenWidth() / 2, GetScreenHeight() / 2, 40, GREEN);
	DrawText("Press SPACE to continue", 10, GetScreenHeight() - 45, 20, GREEN);

}

screen* theory_screen::update_screen()
{
	if (IsKeyPressed(KEY_SPACE)) {
		return new practical_screen();
	}
	return this;
}

practical_screen::practical_screen()
{
	init = true;
	error = false;
	MAX_ELEMENT = 100;
	for (int i = 0; i < 100; i++)
		array[i] = 0;
	errmsg = "";
}

void practical_screen::draw_screen()
{
	if (init) {
		draw_init();
		number.draw_textbox(GetScreenWidth() / 6, GetScreenHeight() / 2 + 40, GetScreenWidth() / 3, 40 , 30);
	}
	if (error) {
		draw_error();
	}
	if (!error && !init) {

		DrawText("Insert", GetScreenWidth() / 20, GetScreenHeight() / 20 + 40, 30, GREEN);
		DrawText("Delete", GetScreenWidth() / 20, GetScreenHeight() / 20 + 40 * 2, 30, GREEN);
		DrawText("Find", GetScreenWidth() / 20, GetScreenHeight() / 20 + 40 * 3, 30, GREEN);
		DrawText("Size Reset", GetScreenWidth() / 20, GetScreenHeight() / 20 + 40 * 4, 30, GREEN);
	}
}

screen* practical_screen::update_screen()
{
	if (init) {
		update_init();
		number.update_textbox();
		}
	if (error) {
			update_error();
		}
	return this;
}

void practical_screen::draw_init()
{
	DrawText("Enter the number of elements you want ", GetScreenWidth() / 6, GetScreenHeight() / 2, 35, GREEN);

}

void practical_screen::update_init()
{
	if (IsKeyPressed(KEY_ENTER)) {
		MAX_ELEMENT = number.get_stored_number();
		if (MAX_ELEMENT == 0) {
			errmsg = "YOU HAVE ENTERED A 0 FOR THE NUMBER\nOF ELEMENTS.SO THE PROGRAM WILL\nCONSIDER IT AS 10.";
			error = true;
		}
		init = false;
	}
}

void practical_screen::draw_error()
{
	DrawPolyLines({ float(GetScreenWidth() / 2),float(GetScreenHeight() / 2) }, 3, 200, 0, { 255,0,0,50 });
	DrawText("!", GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 50,200, { 255,0,0,50 });
	DrawText(errmsg, GetScreenWidth() / 6, GetScreenHeight() / 2, 30, RED);
	DrawText("Press SPACE to continue", 10, GetScreenHeight() - 45, 20, RED);
}

void practical_screen::update_error()
{
	if (IsKeyPressed(KEY_SPACE)) {
		MAX_ELEMENT = 12;
		errmsg = "";
		error = false;
	}
}
