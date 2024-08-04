#include "game.h"
using namespace std;

int main() {
	const int width = 1080, height = 720;
	game BST(width, height);
	while (!BST.should_close())
	{
		BST.tick();
	}
	return 0;
}