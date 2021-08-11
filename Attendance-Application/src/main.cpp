#include "menu.h"

int main(void) {
	Menu start(MAIN_FILENAME, COURSE_FILENAME);
	
	start.run_app();


	return 0;
}