#include "mainFunc.h"

int main(void) {
	system("mode con:cols=80 lines=30");
	hideCursor();
	srand(GetTickCount());
	int menuCode = drawMenu();
	system("cls");

}