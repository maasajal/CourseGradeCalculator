#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// Declaration of a global variable
//const int NumOfStudent = 2;
int NumOfStudent;
int fieldWidth = 15;

// Function prototype declaration here.....
void sortByGrade(string name[], double exercise[], double assignment[]); 	// Prototype Sorted based on final grade
void sortByName(string name[], double exercise[], double assignment[]); 	// Prototype Sorted based on Student names alphabetically

// Main function start here.....
int main() {
	// cout << "\tThere are " << NumOfStudent << " students in this course. " << endl;
	cout << "\tHow many students do you have in this course? ";
	cin >> NumOfStudent;

	// Variable as Array here.....
	string name[NumOfStudent];
	double weekly_exercises[NumOfStudent], final_assignment[NumOfStudent];
	int sort_list;

	// Ask from the user, Student data.....
	for (int i = 0; i < NumOfStudent; i++) {
		cout << "\n     " << i+1 << ". Enter a first name of the student: ";
		cin >> name[i];
		//getline(cin, name[i]);
		cout << "\tHow many weekly exercises have done between (1-46)? ";
		cin >> weekly_exercises[i];
		while(weekly_exercises[i] < 1 || 46 < weekly_exercises[i]) {
            cout << "\tPleae enter weekly exercises between (1-46) ";
            cin >> weekly_exercises[i];
        }
		cout << "\tHow much grade have got for final assignment (1-5)? ";
		cin >> final_assignment[i];
        while(final_assignment[i] < 1 || 5 < final_assignment[i]) {
            cout << "\tPleae enter a grade between (1-5) ";
            cin >> final_assignment[i];
        }
	}
	cout << endl << endl;

	// User can decide if the list is sorted based on grade or student names alphabetically.
	cout << "\tDo you want the grede list sorted based on grade or student names alphabetically?\n\tFor based on grade higher to lowyer enter \"1\"\n\tFor based on student names alphabetically enter \"2\"\t: ";
	cin >> sort_list;
	cout << endl;

	//Student data list header
	cout << "************************************************************************" << endl;
	cout << "|" << setw(fieldWidth) << "Student Name" << " | ";
	cout << setw(fieldWidth) << "Exercises" << " | ";
	cout << setw(fieldWidth) << "Precise grade" << " | ";
	cout << setw(fieldWidth) << "Rounded grade" << " | ";
	cout << endl;
	cout << "*************************************************************************" << endl;

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
	// Function variable here.....
	double gpa[NumOfStudent];
	int sort[NumOfStudent];

	for (int i = 0; i < NumOfStudent; i++) {
        sort[i] = i;
		gpa[sort[i]] = ((5 * (exercise[sort[i]] / 46) * 0.4) + (assignment[sort[i]] * 0.6));	// course grade calculation. 40%/60%	40% - 0.4; 60% - 0.6;
	}
	for (int i = 0; i < NumOfStudent; i++) {
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
		cout << "|" << setw(fieldWidth) << name[sort[i]] << " | ";
		cout << setw(fieldWidth) << exercise[sort[i]] << " | ";
		cout << setw(fieldWidth) << gpa[sort[i]] << " | ";
		cout << setw(fieldWidth) << round(gpa[sort[i]]) << " | ";
		cout << endl;
		cout << "------------------------------------------------------------------------" << endl;
	}
}

// Function definition sortByName here.....
void sortByName(string name[], double exercise[], double assignment[]) {
	// Function variable here.....
	double gpa[NumOfStudent];
	int sort[NumOfStudent];
	for (int i = 0; i < NumOfStudent; i++) {
		sort[i] = i;
		gpa[sort[i]] = ((5 * (exercise[sort[i]] / 46) * 0.4) + (assignment[sort[i]] * 0.6));	// course grade calculation.  40%/60%	40% - 0.4; 60% - 0.6;
	}
	for (int i = 0; i < NumOfStudent; i++) {
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
		cout << "|" << setw(fieldWidth) << name[sort[i]] << " | ";
		cout << setw(fieldWidth) << exercise[sort[i]] << " | ";
		cout << setw(fieldWidth) << gpa[sort[i]] << " | ";
		cout << setw(fieldWidth) << round(gpa[sort[i]]) << " | ";
		cout << endl;
		cout << "------------------------------------------------------------------------" << endl;
	}
}
