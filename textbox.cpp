#include "textbox.h"

textbox::textbox()
{
	for (int i = 0; i < 10; i++) {
		number[i] = '\0';
	}
	curr = -1;
	num = 0;
}

void textbox::draw_textbox(int pos_x, int pos_y, int width, int height, int font_size)
{
	DrawText(number, pos_x + 5, pos_y + 5, font_size, GREEN);
	DrawRectangleLines(pos_x, pos_y, width, height, GREEN);
}

void textbox::update_textbox()
{
	if (IsKeyPressed(KEY_BACKSPACE) && curr > -1) {
		number[curr] = '\0';
		curr--;
		num /= 10;
	}
	if (curr < MAX - 2) {
		int key = GetKeyPressed();
		
		switch (key)
		{
		case KEY_ZERO:
			number[++curr] = '0';
			num = num * 10 + 0;
			break;
		case KEY_ONE:
			number[++curr] = '1';
			num = num * 10 + 1;
			break;
		case KEY_TWO:
			number[++curr] = '2';
			num = num * 10 + 2;
			break;
		case KEY_THREE:
			number[++curr] = '3';
			num = num * 10 + 3;
			break;
		case KEY_FOUR:
			number[++curr] = '4';
			num = num * 10 + 4;
			break;
		case KEY_FIVE:
			number[++curr] = '5';
			num = num * 10 + 5;
			break;
		case KEY_SIX:
			number[++curr] = '6';
			num = num * 10 + 6;
			break;
		case KEY_SEVEN:
			number[++curr] = '7';
			num = num * 10 + 7;
			break;
		case KEY_EIGHT:
			number[++curr] = '8';
			num = num * 10 + 8;
			break;
		case KEY_NINE:
			number[++curr] = '9';
			num = num * 10 + 9;
			break;
		}
	}
}

int textbox::get_stored_number()
{
	return num;
}

void textbox::reset_textbox()
{
	num = 0;
	for (int i = 0; i < MAX; i++) {
		number[i] = '\0';
	}
}


