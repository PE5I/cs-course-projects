#pragma once

#include "pa7.h"
#include "List.h"
#include "ListNode.h"

class Menu {
private:
	string master_filename;
	string course_list_filename;
public:
	// constructor
	Menu(string new_master_filename, string new_course_list_filename);

	// getters
	string get_master_filename() { return master_filename; }
	string get_course_list_filename() { return course_list_filename; }
	
	// setters
	void set_master_filename(string new_filename = "unnamed_master.txt") {
		master_filename = new_filename;
	}
	void set_course_list_filename(string new_filename = "unnamed_course.csv") { 
		course_list_filename = new_filename; 
	}
	

	// functions
	// (1) Import course list, populates the master list with items from .csv
	void import_course(List &master_list, string filename);

	// (2) Load master list
	// populates master list with nodes from master.txt
	void load_master();

	// (3) Store master list
	// Stores contents of master list nodes to master.txt
	void save_master(List master_list);

	// (4) Mark absences
	// runs through master list, displays student's name, and prompts if s/he was abset
	// the data is then pushed to the stack that is contained within the node representative of the student
	void roll_call(List &master);

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

	void generate_report_all(List master);

	void generate_report_by_num_absence(List master,  int num_absence);

	void search_student_name(List master_record, string search_pattern);
	void search_student_id(List master_record, unsigned long int search_pattern);
};
