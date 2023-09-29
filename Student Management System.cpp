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
	void CreateStudent();
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
	cout << "Name: " << lastName << " " << firstName << endl;
	cout << "Student Number: " << studNum << endl;
	cout << "Thank you for registering" << endl;
}

int main() {

	Student obj;

	obj.PromptUser();
	obj.DisplayStudent();

	system("pause");
}