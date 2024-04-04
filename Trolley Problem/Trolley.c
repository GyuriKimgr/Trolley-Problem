#include "mainFunc.h"

int main(void) {
	system("mode con:cols=80 lines=30");
	hideCursor();

	while (1){
	system("cls");
	int menuCode = drawMenu();
	if (menuCode == 0) {
		playGame();
	}
	else if (menuCode == 1) {
		HowtoPlay();
	}
	else if (menuCode == 2) {
		return 0;
	}
	}

}