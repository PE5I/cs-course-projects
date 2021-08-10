#include "pa7.h"
#include "attendance.h"
#include "menu.h"
#include "ListNode.h"
#include "List.h"

int main(void) {
	Menu start(MASTER_FILENAME, COURSE_FILENAME);
	
	start.run_app();


	return 0;
}