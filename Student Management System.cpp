#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Student {
//	data members
private:
	string studNum, firstName, lastName;

//	member functions
public:
	Student(); //	default constructor
	void PromptUser();
	void DisplayStudent();
	void CreateStudent();	//	create a file and store student data
};

Student::Student() {
	cout << "***Student Management System***" << endl;
}

void Student::PromptUser() {
	cout << "Student Number: ";
	cin >> studNum;
	cout << "First name: ";
	cin >> firstName;
	cout << "Lastname: ";
	cin >> lastName;
}

void Student::DisplayStudent() {
	cout << "Student Number: " << studNum << endl;
	cout << "Name: " << lastName << " " << firstName << endl;
}

void Student::CreateStudent() {
	ofstream outFile(studNum + ".txt"); // filename

	if (!outFile.is_open()) {
		// error message
		cout << "Failed to create a file!..." << endl;
		exit(0);
	}
	else {
		outFile << "Student Number: \t" << studNum << endl;
		outFile << "First Name: \t" << firstName << endl;
		outFile << "Last Name: \t" << lastName << endl;
		outFile << "********************************" << endl;
		cout << "Student file created Successfully" << endl;
	}
}

int main() {

	Student obj; // create object

	// variables declaration
	int option;

	//	Menu
	cout << "***Menu***" << endl;
	cout << "Add new Student:\t1" << endl;
	cout<<"Search for a Student:\t2" << endl;
	cout << "Exit the App!:\t0" << endl;
	cout << "\nOption: ";
	cin >> option;

	// if statement
	if (option == 0) {
		exit(1);
	}else
		if (option == 1) {
			//call member functions
			obj.PromptUser();
			obj.CreateStudent();
		}else
			if (option == 2) {
				//call member function
				obj.DisplayStudent();
			}
	system("pause");
}