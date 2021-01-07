#include "ExercisePlan.h"

void ExercisePlan::set_goal(int goal) {
	goal_steps = goal;
}

void ExercisePlan::set_name(string name) {
	plan_name = name;
}

void ExercisePlan::set_date(string date) {
	completion_date = date;
}

void ExercisePlan::edit_goal() {
	int user_input = 0;
	cout << "Enter a new steps goal: ";
	cin >> user_input;
	
	set_goal(user_input);

}


// Overloading << (stream insertion/output)
ostream &operator<< (ostream &os, ExercisePlan &data) {
	os << data.get_name() << endl
		<< data.get_date() << endl
		<< data.get_goal() << endl;
	
	return os;
}

// Overloading << (stream insertion/output)
ofstream &operator<< (ofstream &os, ExercisePlan &data) {
	os << data.get_name() << endl
		<< data.get_date() << endl
		<< data.get_goal() << endl;
	
	return os;
}


// Overloading >> input stream
ifstream &operator>> (ifstream &in, ExercisePlan &data) 
{
	string name;
	in >> name;
	data.set_name(name);

	string date;
	in >> date;
	data.set_date(date);

	int goal;
	in >> goal;
	data.set_goal(goal);
	
	return in;
}
