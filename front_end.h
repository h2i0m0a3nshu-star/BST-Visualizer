#pragma once
#include <raylib.h>

class front_end {
private:
	int scale;
	

public:
	front_end(){
		scale = 1;
	}
	void draw_node(int pos_x, int pos_y, int element) {
		DrawCircleLines(float(pos_x), float(pos_y), 50 * scale, GREEN);
		DrawText(TextFormat("%i", element), pos_x - 20 * scale, pos_y - 25 * scale, 50 * scale, GREEN);
	}

	void scaleup() { (scale <= 5)? scale++:scale += 0; };
	void scaledown() { (scale >= 2) ? scale--:scale += 0; };
};