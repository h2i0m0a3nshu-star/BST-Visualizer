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
	error = false;
	show_textbox = false;
	
	errmsg = "";
	
	selector_x = GetScreenWidth()/20 - 5;
	selector_y = GetScreenHeight()/20 - 5 + 40;
	delay = 5;
}

void practical_screen::draw_screen()
{

	if (error) {
		draw_error();
	}
	if (!error ) {
		
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

	}
}

screen* practical_screen::update_screen()
{
	
	if (error) {
			update_error();
	}
	else if (!error) {
		delay_handler();
		number.update_textbox();

		if (show_textbox == true) {

			if (IsKeyPressed(KEY_ENTER) && delay >= 5) {
				show_textbox = false;
				if (selector_y == GetScreenHeight() / 20 + 40 - 5) {
					
					int new_number = number.get_stored_number();
					error = !binary_search_tree.INSERT(new_number);
					errmsg = "FULL";
				}
				else if (selector_y == GetScreenHeight() / 20 + 40 * 2 - 5) {
					int target = number.get_stored_number();
					error = !binary_search_tree.DELETE(target);
					errmsg = "NUMBER NOT FOUND";
				}
				binary_search_tree.PRINT_ARRAY();
				number.reset_textbox();
				delay = 0;
			}
		}
		else if (show_textbox == false) {
			if (IsKeyPressed(KEY_ENTER) && delay >= 5) {
				show_textbox = true;
				delay = 0;
			}
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

void practical_screen::draw_error()
{
	DrawPolyLines({ float(GetScreenWidth() / 2),float(GetScreenHeight() / 2) }, 3, 200, 0, { 255,0,0,150 });
	DrawText("!", GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 50,200, { 255,0,0,150 });
	DrawText(errmsg, GetScreenWidth() / 6, GetScreenHeight() / 2, 30, RED);
	DrawText("Press SPACE to continue", 10, GetScreenHeight() - 45, 20, RED);
}

void practical_screen::update_error()
{
	if (IsKeyPressed(KEY_SPACE)) {
		number.reset_textbox();
		error = false;
	}
}

void practical_screen::delay_handler()
{
	if (delay >= 0 && delay <= 5) {
		delay++;
	}
}
