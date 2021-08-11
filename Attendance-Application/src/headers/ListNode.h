#pragma once

#include "Stack.h"

typedef struct data {
	unsigned int record_number;
	unsigned long int student_id;
	string student_name;
	string student_email;
	string class_credits;
	string student_major;
	string student_level; // freshman, sophomore, ...
	
	// need a stack/array that represents date in which the student is absent
	unsigned short int student_absences;
} StudentData;

class ListNode {
private:
	ListNode *next;
	StudentData student_record;
	Stack<string> date_absence;
public:
	ListNode() {
		
	}

	// getters
	string get_date_absent() { string date; date_absence.peek(date); return date;}
	unsigned int get_record_number() { return student_record.record_number; }
	unsigned long int get_student_id() { return student_record.student_id; }
	string get_student_name() { return student_record.student_name; }
	string get_student_email() { return student_record.student_email; }
	string get_class_credits() { return student_record.class_credits; }
	string get_student_major() { return student_record.student_major; }
	string get_student_level() { return student_record.student_level; }
	unsigned short int get_student_absences() { return student_record.student_absences; }

	ListNode *getNext() { return next; }

	// setters
	void set_next(ListNode *new_next) {
		next = new_next;
	}
	void set_record_number(unsigned int new_num = 0) {
		student_record.record_number = new_num;
	}
	void set_student_id(unsigned long int new_id = 0) {
		student_record.student_id = new_id;
	}
	void set_student_name(string new_name = "N/A") {
		student_record.student_name = new_name;
	}
	void set_student_email(string new_email = "N/A") {
		student_record.student_email = new_email;
	}
	void set_class_credits(string new_credits = "N/A") {
		student_record.class_credits = new_credits;
	}
	void set_student_major(string new_major = "N/A") {
		student_record.student_major = new_major;
	}
	void set_level(string new_level = "N/A") {
		student_record.student_level = new_level;
	}
	void set_absences(unsigned int new_absence = 0) {
		student_record.student_absences = new_absence;
	}
	void set_date_absence(string new_date = "No Absences") {
		// format: yyyy-mm-dd
		date_absence.push(new_date);
	}
};