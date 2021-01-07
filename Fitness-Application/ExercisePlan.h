#pragma once

#include "pa5.h"

class ExercisePlan { 
    private:
        int goal_steps;
        string plan_name;
        string completion_date;
    public:
        ExercisePlan() { 
            goal_steps = 0;
            plan_name = "Unknown";
            completion_date = "00/00/0000";  // mm/dd/yyyy
        }

		void edit_goal();
   
        // setters declaration
        void set_goal(int goal = 0);
        void set_name(string name = "Unkown");
        void set_date(string date = "00/00/0000");

        // getters declaration & definition
        int get_goal() { return goal_steps; };
        string get_name() { return plan_name; };
        string get_date() { return completion_date; };      
};

// overloading the output operator for printing to files
ofstream &operator<< (ofstream &os, ExercisePlan &data);

// overloading the output operator for printing to screen
ostream &operator<< (ostream &os, ExercisePlan &data);

// overloading the input operator for reading files
ifstream &operator>> (ifstream &os, ExercisePlan &data);
