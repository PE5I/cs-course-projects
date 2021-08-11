#include "menu.h"
#include "List.h"
#include "main.h"

Menu::Menu(string new_main_filename, string new_course_list_filename) {
	main_filename = new_main_filename;
	course_list_filename = new_course_list_filename;
}


// functions
// (1) Import course list, populates the main list with items from .csv
void Menu::import_course(List &main_list, string filename) {
	StudentData new_data;
	ifstream infile;
	infile.open(course_list_filename);


	char input[100];
	infile.getline(input, 100);
	//cout << input << endl;
	
	while(infile.getline(input, 100)) {
		unsigned long int temp = 0;
		char * token;

		token = strtok(input, ",");
		temp = atol(token);
		//cout <<  temp << "\n";
		new_data.record_number = temp;

		token = strtok(NULL, ",");
		temp = atol(token);
		//cout << temp << "\n";
		new_data.student_id = temp;

		char *first, *last;
		last = strtok(NULL, ","); // last name
		first = strtok(NULL, ","); // first name
		char concat[100];
		strcpy(concat, last); // insert last name
		strcpy(concat+strlen(last), ","); // insert comma
		strcpy(concat+strlen(last)+1, first); // insert first name
		new_data.student_name = concat; // this assumes name convention follows "Last,First"

		token = strtok(NULL, ",");
		//cout << token << "\n";
		new_data.student_email = token;

		token = strtok(NULL, ",");
		//cout << token << "\n";
		new_data.class_credits = token;
		
		token = strtok(NULL, ",");
		//cout << token << "\n";
		new_data.student_major = token;
		
		token = strtok(NULL, ",");
		//cout << token << "\n";
		new_data.student_level = token;
		
		main_list.insertFront(main_list, new_data);
	}

	infile.close();
}

// (2) Load main list
// populates main list with nodes from main.txt
void Menu::load_main(List &main_list) {
	ifstream infile; // read from main file
	infile.open(course_list_filename);

	ofstream outfile; // write to main file
	outfile.open(MAIN_FILENAME);

	outfile << "Field,ID,Name,Email,Units,Program,Level" << "\n";

	ListNode *traversal = main_list.getHead();

	while(traversal) {
		outfile << traversal->get_record_number()
				<< ","
				<< traversal->get_student_id()
				<< ","
				<< traversal->get_student_name()
				<< ","
				<< traversal->get_student_email()
				<< ","
				<< traversal->get_class_credits()
				<< ","
				<< traversal->get_student_major()
				<< ","
				<< traversal->get_student_level()
				<< endl;
		traversal = traversal->getNext();
	}

	outfile.close();
}

// (3) Store main list
// Stores contents of main list nodes to main.txt
void Menu::save_main(List main_list) {
	ofstream outfile; // write to main file
	outfile.open(MAIN_FILENAME);

	outfile << "Field,ID,Name,Email,Units,Program,Level" << "\n";

	ListNode *traversal = main_list.getHead();

	while(traversal) {
		outfile << traversal->get_record_number()
				<< ","
				<< traversal->get_student_id()
				<< ","
				<< traversal->get_student_name()
				<< ","
				<< traversal->get_student_email()
				<< ","
				<< traversal->get_class_credits()
				<< ","
				<< traversal->get_student_major()
				<< ","
				<< traversal->get_student_level()
				<< endl;
		traversal = traversal->getNext();
	}

	outfile.close();
}

// (4) Mark absences
// runs through main list, displays student's name, and prompts if s/he was abset
// the data is then pushed to the stack that is contained within the node representative of the student
void Menu::roll_call(List &main) {
	ListNode *traverse = main.getHead();
	string date_today = "0000-00-00";
	date_today = get_date();

	cout << "Roll Call for: " << date_today << endl;
	
	while(traverse) {
		cout << "is " << traverse->get_student_name() << " present today? (y/n)" << endl;
		cout << ">>> ";
		char is_present = 'n';
		cin >> is_present;

		if(is_present == 'n') {
			int current_num_absence = traverse->get_student_absences(); // get current absence count
			traverse->set_absences(current_num_absence+1); // add one for today!
			traverse->set_date_absence(date_today);
		}

		traverse = traverse->getNext();
	}
}

// ============================ These have not been implemented ========================//
// (5) BONUS: Edit absences
// prompt for an ID number OR name of student to edit, 
// then it prompts for the date of absence to edit
void Menu::edit_roll_call() {

}

// (6) Generate report
// Leads to submenus:
//		1. Generate report for all students; showing the most recent absence, peek()
//		2. generate report for students with absences that match or exceed a number entered by user
void Menu::generate_report() {

}
// ====================================================================================//

void Menu::generate_report_all(List main) {
	ListNode *traversal = main.getHead();

	while(traversal) {
		cout << traversal->get_student_name()
			<< "\tlast absent: "
			<< traversal->get_date_absent()
			<< endl;
		traversal = traversal->getNext();
	}
}

void Menu::generate_report_by_num_absence(List main, int num_absence) {
	ListNode *traversal = main.getHead();

	while(traversal) {
		if(traversal->get_student_absences() >= num_absence) {
			cout << traversal->get_student_name() 
				<< "\thas "
				<< traversal->get_student_absences()
				<< " absence."
				<< endl;
		}

		traversal = traversal->getNext();
	}
}

void Menu::search_student_name(List main_record, string search_pattern) {
	ListNode *traversal = main_record.getHead();

	while(traversal) {
		if(search_pattern == traversal->get_student_name()) {
			cout << "Found a match!\n";
			// now do some stuff about the students' absence
			if (traversal->get_student_absences() == 0) {
				cout << "This student has never been absent!\n";
			} else {
				cout << "This student has: "
					<< traversal->get_student_absences()
					<< " absence(s) on "
					<< traversal->get_date_absent()
					<< endl;
				cout << "Which absence would you like to edit? >> ";
			}
		}
		traversal = traversal->getNext();
	}
}

void Menu::search_student_id(List main_record, unsigned long int search_pattern) {
	ListNode *traversal = main_record.getHead();

	while(traversal) {
		if(search_pattern == traversal->get_student_id()) {
			cout << "Found a match!\n";
			// now do some stuff about the students' absence
			if (traversal->get_student_absences() == 0) {
				cout << "This student has never been absent!\n";
			} else {
				cout << "This student has: "
					<< traversal->get_student_absences()
					<< " absence(s) on "
					<< traversal->get_date_absent()
					<< endl;
				cout << "Which absence would you like to edit? >> ";
				
			}
		}
		traversal = traversal->getNext();
	}
}

void Menu::display_menu() {
	cout << "\n***** Main Menu *****\n";
	cout << "1. Import Course List (csv)\n";
	cout << "2. Load main List (main.txt)\n";
	cout << "3. Store main List\n";
	cout << "4. Roll Call (Mark Absences)\n";
	cout << "5. Edit Absences\n";
	cout << "6. Generate Report\n";
	cout << "7. Terminate Program\n";
	cout << " >> ";
}

void Menu::run_app() {
	
	StudentData new_data;
	List main;
	int choice = 0;
	int report_choice = 0;
	// ListNode *traversal = main.getHead();

	//main.printList();
	//start.save_main(main);
	//roll_call(main);

	do {
		display_menu();

		cin >> choice;
		switch(choice) {
			case IMPORT:
				if (main.getHead()) { 
					main.list_destruct(); // destructs the previous main list so it can be overwritten
				}
				import_course(main, COURSE_FILENAME);
				break;
			case LOAD:
				// I'm using the same function because they essentially does the same thing
				// however, I am changing the filename passed in
				if (main.getHead()) {
					main.list_destruct();
				}
				import_course(main, MAIN_FILENAME); // loads main list from main.txt
				break;
			case STORE:
				save_main(main);
				break;
			case ROLLCALL:
				roll_call(main);
				break;
			case EDIT:
				cout << "** Student Absence Editor **\n";
				cout << "\t1. Search by name (last,first)\n";
				cout << "\t2. Search by student ID\n";
				cin >> choice;

				if(choice == 1) {
					string input_student_name = "last,first";
					cout << "Enter student name following the format: \"last,first\"\n";
					cout << ">> ";
					cin >> input_student_name;

					search_student_name(main,input_student_name);
				} else if (choice == 2) {
					unsigned long int input_student_id = 0;
					cout << "Enter student ID Number\n";
					cout << ">> ";
					cin >> input_student_id;

					search_student_id(main, input_student_id);
				}

				break;
			case REPORT:
				cout << "*** Student Absence Report Module ***\n";
				cout << "\t1. Generate absence report for all students\n";
				cout << "\t2. Generate report for students based on number of absences\n";
				cout << ">> ";
				report_choice = 0;
				cin >> report_choice;

				if(report_choice == 1) {
					generate_report_all(main);
				} else if (report_choice == 2) {
					int num_absence = 0;
					cout << "Print students with N or more absences." << endl;
					cout << "Enter a value for N: ";
					cin >> num_absence;

					generate_report_by_num_absence(main, num_absence);
				} else {
					cout << "Invalid input..." << endl;
				}

				break;
			case EXIT:
				cout << "Exiting" << endl;
				main.list_destruct();
				break;

			default:
				cout << "Bad entry" << endl;
		}
	
	} while (choice != 7 || (choice < 1) || (choice > 7));
}

string Menu::get_date(void) {
	// retrieved from stackoverflow
	time_t t = time(0); // get current time
	struct tm * now = localtime(&t);

	string date_now;

	int year = 0, month = 0, day = 0;
	year = (now->tm_year + 1900);
	month = (now->tm_mon + 1);
	day = (now->tm_mday);

	date_now = to_string(year) + '-' + to_string(month) + '-' + to_string(day);
	
	return date_now;
}