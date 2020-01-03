# programming-cpp
#include <iostream> 
#include <string> 
#include <cmath> 

using namespace std;

// Function prototype declaration here.....
void sortByGrade(string name[], double exercise[], double assignment[]); 	// Prototype Sorted based on final grade
void sortByName(string name[], double exercise[], double assignment[]); 	// Prototype Sorted based on Student names alphabetically

// Main function start here.....
int main() {
	// How many student's data do you want to add..... you can change from below "NumOfStudent" also you need to change from two function...
	const int NumOfStudent = 3;
	cout << "\tThere are " << NumOfStudent << " students in this course? " << endl;

	// Variable as Array here.....
	string name[NumOfStudent];
	double weekly_exercises[NumOfStudent], final_assignment[NumOfStudent];
	int sort_list;

	// Ask from the user, Student data.....
	for (int i = 0; i < NumOfStudent; i++) {
		cout << "\n     " << i+1 << ". Enter a first name of the student: ";
		cin >> name[i];
		//getline(cin, name[i]);
		cout << "\tHow many weekly exercises have done? ";
		cin >> weekly_exercises[i];
		cout << "\tHow much grade have got for final assignment? ";
		cin >> final_assignment[i];
	}
	cout << endl << endl;

	// User can decide if the list is sorted based on grade or student names alphabetically. 
	cout << "\tDo you want the grede list sorted based on grade or student names alphabetically?\n\tFor based on grade higher to lowyer enter \"1\"\n\tFor based on student names alphabetically enter \"2\"\t: ";
	cin >> sort_list;
	cout << endl;

	// Switch loop for printing grade point list
	switch (sort_list) {
	case 1: sortByGrade(name, weekly_exercises, final_assignment);	// Call the sortByGrade function
		break;

	case 2:	sortByName(name, weekly_exercises, final_assignment);		// Call the sortByName function
		break;

	default: cout << "\tPlease enter only 1 or 2";
	}

	cin.ignore();
	cin.get();

	cout << endl << endl;
	return 0;
}

// Function definition sortByGrade here.....
void sortByGrade(string name[], double exercise[], double assignment[]) {
	//Student data list header 
	cout << "\t****************************************************************************" << endl;
	cout << "\tStudent Name";
	cout << "\t| Accepted exercises";
	cout << "\t| Precise grade";
	cout << "\t   | Rounded grade";
	cout << endl;
	cout << "\t****************************************************************************" << endl;

	// Function variable here.....
	// If you change the "NumOfStudent" variable from main function, then you need to change from two function...
	const int NumOfStudent = 3;
	double gpa[NumOfStudent];
	int sort[NumOfStudent];
	for (int i = 0; i < NumOfStudent; i++) {
		sort[i] = i;
	}
	for (int i = 0; i < NumOfStudent; i++) {
		gpa[sort[i]] = ((5 * (exercise[sort[i]] / 46) * 0.4) + (assignment[sort[i]] * 0.6));	// course grade calculation. 40%/60%	40% - 0.4; 60% - 0.6;
	}
	for (int i = 0; i <= NumOfStudent; i++) {
		for (int j = i + 1; j < NumOfStudent; j++) {
			int temp;
			if (gpa[sort[i]] < gpa[sort[j]]) {
				temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}
		}
	}
	// Print student data.....
	for (int i = 0; i < NumOfStudent; i++) {
		cout << "\t" << name[sort[i]];
		cout << "\t\t| " << exercise[sort[i]];
		cout << "\t\t\t| " << gpa[sort[i]];
		cout << "\t   | " << round(gpa[sort[i]]);
		cout << endl;
		cout << "\t----------------------------------------------------------------------------" << endl;
	}
}

// Function definition sortByName here.....
void sortByName(string name[], double exercise[], double assignment[]) {
	//Student data list header 
	cout << "\t****************************************************************************" << endl;
	cout << "\tStudent Name";
	cout << "\t| Accepted exercises";
	cout << "\t| Precise grade";
	cout << "\t   | Rounded grade";
	cout << endl;
	cout << "\t****************************************************************************" << endl;

	// Function variable here.....
	// If you change the "NumOfStudent" variable from main function, then you need to change from two function...
	const int NumOfStudent = 3;
	double gpa[NumOfStudent];
	int sort[NumOfStudent];
	for (int i = 0; i < NumOfStudent; i++) {
		sort[i] = i;
	}
	for (int i = 0; i <= NumOfStudent; i++) {
		for (int j = i + 1; j < NumOfStudent; j++) {
			int temp;
			if (name[sort[i]] > name[sort[j]]) {
				temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}
		}
	}
	// Print student data.....
	for (int i = 0; i < NumOfStudent; i++) {
		cout << "\t" << name[sort[i]];
		cout << "\t\t| " << exercise[sort[i]];
		gpa[sort[i]] = ((5 * (exercise[sort[i]] / 46) * 0.4) + (assignment[sort[i]] * 0.6));	// course grade calculation.  40%/60%	40% - 0.4; 60% - 0.6;
		cout << "\t\t\t| " << gpa[sort[i]];
		cout << "\t   | " << round(gpa[sort[i]]);
		cout << endl;
		cout << "\t----------------------------------------------------------------------------" << endl;
	}
}
