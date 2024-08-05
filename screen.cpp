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
	show_textbox = false;
	
	MAX_ELEMENT = 0;
	for (int i = 0; i < 100; i++)
		array[i] = 0;
	
	errmsg = "";
	
	selector_x = GetScreenWidth()/20 - 5;
	selector_y = GetScreenHeight()/20 - 5 + 40;
	curr_element_num = 0;
	delay = 5;
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
		
		DrawText("Press ENTER to select the option", 10, GetScreenHeight() - 45, 20, GREEN);

		DrawRectangle(selector_x, selector_y, 200, 40, GREEN);
		
		if (show_textbox) {
			number.draw_textbox(selector_x + 220, selector_y, 100, 40, 30);
		}

		if (selector_y == GetScreenHeight() / 20 + 40 - 5) {
			DrawText("Insert", GetScreenWidth() / 20, GetScreenHeight() / 20 + 40, 30, BLACK);
		}
		else{
			DrawText("Insert", GetScreenWidth() / 20, GetScreenHeight() / 20 + 40, 30, GREEN);
		}
		
		if (selector_y == GetScreenHeight() / 20 + 40 * 2 - 5) {
			DrawText("Delete", GetScreenWidth() / 20, GetScreenHeight() / 20 + 40 * 2, 30, BLACK);
		}
		else {
			DrawText("Delete", GetScreenWidth() / 20, GetScreenHeight() / 20 + 40 * 2, 30, GREEN);
		}

		if (selector_y == GetScreenHeight() / 20 + 40 * 3 - 5) {
			DrawText("Find", GetScreenWidth() / 20, GetScreenHeight() / 20 + 40 * 3, 30, BLACK);
		}
		else
		{
			DrawText("Find", GetScreenWidth() / 20, GetScreenHeight() / 20 + 40 * 3, 30, GREEN);
		}

		if (selector_y == GetScreenHeight() / 20 + 40 * 4 - 5) {
			DrawText("Size Reset", GetScreenWidth() / 20, GetScreenHeight() / 20 + 40 * 4, 30, BLACK);
		}
		else
		{
			DrawText("Size Reset", GetScreenWidth() / 20, GetScreenHeight() / 20 + 40 * 4, 30, GREEN);
		}
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
	if (!error && !init) {
		delay_handler();
		number.update_textbox();

		if (IsKeyPressed(KEY_ENTER) && delay >= 5) {
			if (show_textbox == false) {
				show_textbox = true;
			}
			else if(show_textbox == true){
				if (selector_y == GetScreenHeight() / 20 + 40 - 5) {
					error = INSERT(0);
					errmsg = "FULL";
				}
				show_textbox = false;
			}
			delay = 0;
		}

		if (IsKeyPressed(KEY_DOWN) && delay >= 5 && !show_textbox) {
			if (selector_y == GetScreenHeight() / 20 + 40 - 5) {
				selector_y = GetScreenHeight() / 20 + 40 * 2 - 5;
			}
			else if (selector_y == GetScreenHeight() / 20 + 40 * 2 - 5) {
				selector_y = GetScreenHeight() / 20 + 40 * 3 - 5;
			}
			else if (selector_y == GetScreenHeight() / 20 + 40 * 3 - 5) {
				selector_y = GetScreenHeight() / 20 + 40 * 4 - 5;
			}
			delay = 0;
		}
		
		if (IsKeyPressed(KEY_UP) && delay >= 5 && !show_textbox) {
			if (selector_y == GetScreenHeight() / 20 + 40 * 2 - 5) {
				selector_y = GetScreenHeight() / 20 + 40 - 5;
			}
			else if (selector_y == GetScreenHeight() / 20 + 40 * 3 - 5) {
				selector_y = GetScreenHeight() / 20 + 40 * 2 - 5;
			}
			else if (selector_y == GetScreenHeight() / 20 + 40 * 4 - 5) {
				selector_y = GetScreenHeight() / 20 + 40 * 3 - 5;
			}
			delay = 0;
		}
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
		
		if (number.get_stored_number() <= 0) {
			errmsg = "YOU HAVE ENTERED A 0 FOR THE NUMBER\nOF ELEMENTS.SO THE PROGRAM WILL\nCONSIDER IT AS 10.";
			error = true;
		}
		MAX_ELEMENT = MAX_finder(number.get_stored_number());
		number.reset_textbox();
		delay = 0;
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
		MAX_ELEMENT = 1022;
		number.reset_textbox();
		errmsg = "";
		error = false;
	}
}

int practical_screen::MAX_finder(int num)
{
	return (pow(2,num) - 2);
}

bool practical_screen::isFULL()
{
	return curr_element_num == MAX_ELEMENT || MAX_ELEMENT >= 10000;
}

bool practical_screen::isEMPTY()
{
	return curr_element_num == 0;
}

bool practical_screen::INSERT(int new_num)
{
	if (isFULL()) {
		return true;
	}

	return false;
}

void practical_screen::delay_handler()
{
	if (delay >= 0 && delay <= 5) {
		delay++;
	}
}
