#pragma once

#include "pa5.h"
#include "DietPlans.h"
#include "ExercisePlan.h"

class FitnessAppWrapper {
	private:
		DietPlan plans[7];
	public:
		void runApp(void);
	
		/* DietPlan Functions */
		void loadDailyPlan(ifstream &fileStream, DietPlan &plan);
		void loadWeeklyPlan(ifstream &fileStream, DietPlan weeklyPlan[]);

		void displayDailyPlan(DietPlan &plan);
		void displayWeeklyPlan(DietPlan weeklyPlan[]);
		
		void storeDailyPlan(ofstream &output_file, DietPlan &plan);
		void storeWeeklyPlan(ofstream &output_file, DietPlan weeklyPlan[]);
		
		void edit_daily_plan(DietPlan &plan);

		/* ExercisePlan Functions */
		void loadDailyPlan(ifstream &fileStream, ExercisePlan &plan);
		void loadWeeklyPlan(ifstream &fileStream, ExercisePlan weeklyPlan[]);

		void displayDailyPlan(ExercisePlan &plan);
		void displayWeeklyPlan(ExercisePlan weeklyPlan[]);
		
		void storeDailyPlan(ofstream &output_file, ExercisePlan &plan);
		void storeWeeklyPlan(ofstream &output_file, ExercisePlan weeklyPlan[]);

		void edit_daily_plan(ExercisePlan &plan);
		/* Other functionalities */

		// print the screen
		void displayMenu();

		void save_to_file(ofstream &file, DietPlan &plan); 

		// inserting to record
		// <some insert function>
		
		// deleting record
		// <some delete function>
};
