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

	// call member functions 
	obj.PromptUser();
	obj.DisplayStudent();
	obj.CreateStudent();

	system("pause");
}