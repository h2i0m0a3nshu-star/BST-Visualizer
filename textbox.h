#pragma once
#include <raylib.h>
using namespace std;

class textbox
{
public:
	textbox();
	void draw_textbox(int pos_x,int pos_y,int width,int height,int font_size);
	void update_textbox();
	int get_stored_number();
	void reset_textbox();
	~textbox();
private:
	static const int MAX = 10;
	char number[MAX];
	int num,curr;
};