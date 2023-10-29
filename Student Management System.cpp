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

	//setters and getters
	void setStudent(string, string, string);
	string getStudNum() { return studNum; }
	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
};

Student::Student() {
	studNum = "";
	firstName = "";
	lastName = "";
}

void Student::setStudent(string sn, string fn, string ln) {
	studNum = sn;
	firstName = fn;
	lastName = ln;
}


void PromptUser(Student *St,int sz) {

	string sn, fn, ln;
	for (int i = 0; i < sz;i++) {
		cout << "Student Number: ";
		cin >> sn;
		cout << "First name: ";
		cin >> fn;
		cout << "Lastname: ";
		cin >> ln;
		St[i].setStudent(sn, fn, ln);
	}
}

void DisplayStudents(Student *St,int sz) {
	cout << "***Students***" << endl;
	for (int i = 0; i < sz; i++) {
		cout << i + 1 << ": " << St[i].getStudNum() << " " << St[i].getFirstName() << " " << St[i].getLastName() << endl;
	}
	cout << "**********************" << endl;
}

void CreateStudents(Student *St,int sz) {
	ofstream outFile("Students.txt"); // filename

	if (!outFile.is_open()) {
		// error message
		cout << "Failed to create a file!..." << endl;
		exit(0);
	}
	else {
		for (int i = 0; i < sz; i++) {
			outFile << i + 1 << ": " << St[i].getStudNum() << "," << St[i].getFirstName() << "," << St[i].getLastName() << endl;
		}
		cout << "Students file created Successfully" << endl;
	}
}

int main() {

	cout << "***Student Management System***" << endl;

	// declare variables
	Student obj; // create object
	int option;
	int numStudents = 0;

	//	Menu
	cout << "***Menu***" << endl;
	cout << "Add new Students:\t1" << endl;
	cout << "Search for a Student:\t2" << endl;
	cout << "Exit the App!:\t0" << endl;
	cout << "\nOption: ";
	cin >> option;

	cout << "How many students do you want to enter: ";
	cin >> numStudents;
	Student* St = new Student[numStudents];

	// if statement
	if (option == 0) {
		exit(1);
	}
	else
		if (option == 1) {

			//call member functions
			PromptUser(St,numStudents);
			CreateStudents(St,numStudents);
		}
		else
			if (option == 2) {
				//call member function
				DisplayStudents(St,numStudents);
			}
	system("pause");
}