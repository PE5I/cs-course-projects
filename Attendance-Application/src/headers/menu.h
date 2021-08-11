#pragma once

//#include "pa7.h"
#include "List.h"
#include "ListNode.h"

#define IMPORT 1
#define LOAD 2
#define STORE 3
#define ROLLCALL 4
#define EDIT 5
#define REPORT 6
#define EXIT 7

class Menu {
private:
	string main_filename;
	string course_list_filename;
public:
	// constructor
	Menu(string new_main_filename, string new_course_list_filename);

	// getters
	string get_main_filename() { return main_filename; }
	string get_course_list_filename() { return course_list_filename; }
	
	// setters
	void set_main_filename(string new_filename = "unnamed_main.txt") {
		main_filename = new_filename;
	}
	void set_course_list_filename(string new_filename = "unnamed_course.csv") { 
		course_list_filename = new_filename; 
	}
	

	// functions
	// (1) Import course list, populates the main list with items from .csv
	void import_course(List &main_list, string filename);

	// (2) Load main list
	// populates main list with nodes from main.txt
	void load_main(List &main_list);

	// (3) Store main list
	// Stores contents of main list nodes to main.txt
	void save_main(List main_list);

	// (4) Mark absences
	// runs through main list, displays student's name, and prompts if s/he was abset
	// the data is then pushed to the stack that is contained within the node representative of the student
	void roll_call(List &main);

	// (5) BONUS: Edit absences
	// prompt for an ID number OR name of student to edit, 
	// then it prompts for the date of absence to edit
	void edit_roll_call();

	// (6) Generate report
	// Leads to submenus:
	//		1. Generate report for all students; showing the most recent absence, peek()
	//		2. generate report for students with absences that match or exceed a number entered by user
	void generate_report();

	// (7) Exit
	void exit();

	// display 
	void display_menu(); 

	void run_app();

	void generate_report_all(List main);
	void generate_report_by_num_absence(List main,  int num_absence);

	void search_student_name(List main_record, string search_pattern);
	void search_student_id(List main_record, unsigned long int search_pattern);

	string get_date(void);
};
