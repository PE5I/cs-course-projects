#include "FitnessAppWrapper.h"

/******************** App Wrapper for DietPlan ****************************/ 

// Precondition: File has already opened
// Reads one record from given stream
void FitnessAppWrapper::loadDailyPlan(ifstream &fileStream, DietPlan &plan) {
	fileStream >> plan;
}

// Precondition: File has already opened
// (note-to-self: the header would change if you implement a linked list)
void FitnessAppWrapper::loadWeeklyPlan(ifstream &fileStream, DietPlan weeklyPlan[]) { // there are 7 days in a week, so 7 weeklyPlan
	int i = 0;
	while(i < 7) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
		i++;
	}
}

void FitnessAppWrapper::displayDailyPlan(DietPlan &plan) {
	cout << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[]) {
	int i = 0;
	while(i < 7) {
		displayDailyPlan(weeklyPlan[i]);
		i++;
	}
}
		
void FitnessAppWrapper::storeDailyPlan(ofstream &output_file, DietPlan &plan) {
	output_file << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(ofstream &output_file, DietPlan weeklyPlan[]){
	int i = 0;
	while(i < 7) {
		storeDailyPlan(output_file, weeklyPlan[i]);
		i++;
	}
}

/***************** App Wrapper for ExercisePlan *****************************/

// Precondition: File has already opened
// Reads one record from given stream
void FitnessAppWrapper::loadDailyPlan(ifstream &fileStream, ExercisePlan &plan) {
	fileStream >> plan;
}

// Precondition: File has already opened
// (note-to-self: the header would change if you implement a linked list)
void FitnessAppWrapper::loadWeeklyPlan(ifstream &fileStream, ExercisePlan weeklyPlan[]) { // there are 7 days in a week, so 7 weeklyPlan
	int i = 0;
	while(i < 7) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
		i++;
	}
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan &plan) {
	cout << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[]) {
	int i = 0;
	while(i < 7) {
		displayDailyPlan(weeklyPlan[i]);
		i++;
	}
}
		
void FitnessAppWrapper::storeDailyPlan(ofstream &output_file, ExercisePlan &plan) {
	output_file << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(ofstream &output_file, ExercisePlan weeklyPlan[]){
	int i = 0;
	while(i < 7) {
		storeDailyPlan(output_file, weeklyPlan[i]);
		i++;
	}
}


// Prints out menu 
void FitnessAppWrapper::displayMenu() {
	cout << "Fitness Application" << endl;
	cout << endl;
	cout << "\t1. Load Weekly Diet Plan from a file" << endl;
	cout << "\t2. Load Weekly Exercise Plan from a file" << endl;
	cout << "\t3. Store weekly diet plan to file" << endl;
	cout << "\t4. Store weekly exercise plan to file" << endl;
	cout << "\t5. Display weekly diet plan to screen" << endl;
	cout << "\t6. Display weekly exercise plan to screen" << endl;
	cout << "\t7. Edit daily diet plan" << endl;
	cout << "\t8. Edit daily exercise plan" << endl;
	cout << "\t9. Save & Terminate" << endl;
}

void FitnessAppWrapper::edit_daily_plan(ExercisePlan &plan) {
	string new_plan_name, new_date;
	int new_goal;
	cout << "Enter a new plan name: "; cin >> new_plan_name;
	cout << "Enter a new date of completion (dd/mm/yyyy): "; cin >> new_date;
	cout << "Enter a new goal for steps taken: "; cin >> new_goal;

	plan.set_name(new_plan_name);
	plan.set_date(new_date);
	plan.set_goal(new_goal);

	cout << "Your changes were made successfully!" << endl;
}

void FitnessAppWrapper::edit_daily_plan(DietPlan &plan) {
	string new_plan_name, new_date;
	int new_goal;
	cout << "Enter a new plan name: "; cin >> new_plan_name;
	cout << "Enter a new date of completion (dd/mm/yyyy): "; cin >> new_date;
	cout << "Enter a new goal for calorie consumption: "; cin >> new_goal;

	plan.set_name(new_plan_name);
	plan.set_date(new_date);
	plan.set_goal(new_goal);

	cout << "Your changes were made successfully!" << endl;
}

// Invokes upon first access
void FitnessAppWrapper::runApp(void) {
	int user_input = 0;
	
		ExercisePlan exercise_data[7]; 
		DietPlan diet_data[7];
	
	while (user_input != 9) {
		displayMenu();
		cout << " >> ";
		cin >> user_input;
	
		if (user_input == 1) { // Load DietPlan from file
			// open file
			ifstream read_file;
			read_file.open(DIET_FILE);

			if(read_file.is_open()) {
				loadWeeklyPlan(read_file, diet_data);
				// close file
				read_file.close();
			} else {
				cout << "Problem opening DietPlan file for reading: " << DIET_FILE << endl;
			}
		} else if (user_input == 2) { // load ExercisePlan from file
			// open file
			ifstream read_file;
			read_file.open(EXERCISE_FILE);

			if(read_file.is_open()) {
				loadWeeklyPlan(read_file, exercise_data);
				// close file
				read_file.close();
			} else {
				cout << "Problem opening ExercisePlan file for reading: " << EXERCISE_FILE << endl;
			}
		} else if (user_input == 3) { // Store weekly diet plan to file
			// open file
			ofstream out_file;
			out_file.open(DIET_FILE);

			if(out_file.is_open()) {
				storeWeeklyPlan(out_file, diet_data);
				// close file
				out_file.close();
			} else {
				cout << "Problem opening DietPlan file for output: " << DIET_FILE << endl;
			}
		} else if (user_input == 4) { // Store weekly exercise plan to file
			// open file
			ofstream out_file;
			out_file.open(EXERCISE_FILE);

			if(out_file.is_open()) {
				storeWeeklyPlan(out_file, exercise_data);
				// close file
				out_file.close();
			} else {
				cout << "Problem opening ExercisePlan file for output: " << EXERCISE_FILE << endl;
			}
		} else if (user_input == 5) { // display weekly diet plan to screen
			displayWeeklyPlan(diet_data);
		} else if (user_input == 6) {
			displayWeeklyPlan(exercise_data);
		} else if (user_input == 7) { // edit daily diet plan
			// we should prompt for which day to edit
			int day_of_week = 0;
			do {
				cout << "Which day of the week would you like to edit? >> ";
				cin >> day_of_week;
			} while (day_of_week < 0 || day_of_week > 7);
			edit_daily_plan(diet_data[day_of_week]);
			
			cout << diet_data[day_of_week];
		} else if (user_input == 8) { // edit daily exercise plan
 			int day_of_week = 0;
			do {
				cout << "Which day of the week would you like to edit? >> ";
				cin >> day_of_week;
			} while (day_of_week < 0 || day_of_week > 7);
			edit_daily_plan(exercise_data[day_of_week]);

			cout << exercise_data[day_of_week];
		} else if (user_input == 9) {
			// open file
			ofstream out_file;
			out_file.open(DIET_FILE);

			if(out_file.is_open()) {
				storeWeeklyPlan(out_file, diet_data);
				cout << "writing data to file then exiting..." << endl;
				// close file
				out_file.close();
			} else {
				cout << "Problem opening DietPlan file for output: " << DIET_FILE << endl;
			}
			
			out_file.open(EXERCISE_FILE);

			if(out_file.is_open()) {
				storeWeeklyPlan(out_file, exercise_data);
				// close file
				out_file.close();
			} else {
				cout << "Problem opening ExercisePlan file for output: " << EXERCISE_FILE << endl;
			}
		}
	}
	
}