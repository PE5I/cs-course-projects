#include "DietPlans.h"

void DietPlan::set_goal(int goal) {
	goal_calories = goal;
}

void DietPlan::set_date(string date) {
	completion_date = date;
}

void DietPlan::set_name(string name) {
	plan_name = name;
}

// Prompts user for new calorie plan goal
// and uses setter to set the goal
void DietPlan::edit_goal() {
	int user_input = 0;
	cout << "Enter a new calorie goal: ";
	cin >> user_input;
	
	set_goal(user_input);

}

// Overloading << (stream insertion/output)
ostream &operator<< (ostream &os, DietPlan &data) {
	os << data.get_name() << endl
		<< data.get_date() << endl
		<< data.get_goal() << endl;
	
	return os;
}

// Overloading << (stream insertion/output)
ofstream &operator<< (ofstream &os, DietPlan &data) {
	os << data.get_name() << endl
		<< data.get_date() << endl
		<< data.get_goal() << endl;
	
	return os;
}


// input stream
ifstream &operator>> (ifstream &in, DietPlan &data) 
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

