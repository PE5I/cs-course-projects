#pragma once

#include "pa5.h"


// We need three (3) classes.
// (1) DietPlan, (2) ExercisePlan, (3) FitnessAppWraper


// DietPlan has three members
// goal (int), name (string), and date (string)
class DietPlan {
	private:
		int goal_calories;
		string plan_name;
		string completion_date;
	public:
		DietPlan() {
			goal_calories = 0;
			plan_name = "Unknown";
			completion_date = "00/00/0000"; // mm/dd/yyyy
		}
				
		void edit_goal();

		// setters
		void set_goal(int goal = 0);
		void set_name(string name = "Unknown");
		void set_date(string date= "00/00/0000");

		// getters
		int get_goal() { return goal_calories; };
		string get_name() { return plan_name; };
		string get_date() { return completion_date; };

};

// overloading the output operator for printing to files
ofstream &operator<< (ofstream &os, DietPlan &data);

// overloading the output operator for printing to screen
ostream &operator<< (ostream &os, DietPlan &data);

// overloading the input operator for reading files
ifstream &operator>> (ifstream &os, DietPlan &data);
