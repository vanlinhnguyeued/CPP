// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
using namespace std;

struct Student {
	int id;
	string name;
	float score;
};

typedef vector<Student> listStudent;


int InputNumberStudent() {
	cout << "Input number of customers (n>=1): \t";
	int n; cin >> n;
	while (!cin || n <= 0) {
		cout << "Invalid number, please enter again!: \t";
		cin.clear();
		cin >> n;
	}
	return n;
}

void InputStudentsInfor(listStudent* vlist, Student *student) {

	cout << "______________Input the student information______________" << endl;
	int n = InputNumberStudent();
	for (int i = 0; i < n; i++) {
		cout << "Input the student information " << i + 1 << ":" << endl;
		cout << "ID: "; cin >> student->id;
		cout << "Name: "; cin.ignore(); getline(cin, student->name);
		cout << "Score: "; cin >> student->score;
		while (!cin || student->score < 0 || student->score>10) {
			cout << "Invalid score, please enter again!\n";
			cin.clear();
			cout << "Score: "; cin >> student->score;
		}
		vlist->push_back(*student);
	}
}

void DisplayAStudentInfor(Student *student) {
	cout << "\t" << student->id << "\t\t" << student->name << "\t\t" << student->score << endl;
}
void DisplayStudentInfor(listStudent *vlist ) {
	
	if (vlist->empty()) {
		cout << "______Nothing in the list!" << endl;
	}
	else {
		cout << endl << "_______________________LIST STUDENT______________________" << endl;
		cout << "\tID\t\tFULL NAME\t\tScore" << endl;
		for (auto i : *vlist) {
			DisplayAStudentInfor(&i);
		}
	}
}
string SetDataToFile(Student *student) {
	string id, score;
	ostringstream convertID;
	convertID << student->id;
	id = convertID.str();
	ostringstream convertScore;
	convertScore << student->score;
	score = convertID.str();
	return id+"\t|\t"+student->name+"\t|\t"+score+"\n";
}
void SaveToFile(listStudent *vlist) {
	ofstream outFileListStudents;
	outFileListStudents.open("ListStudents.txt");
	outFileListStudents << "ID\t|\tFULL NAME\t|\tScore\n" << endl;
	for (auto i : *vlist) {
		outFileListStudents << SetDataToFile(&i) << endl;
		
	}
	outFileListStudents.close();
}
int main() {
	int choice;
	Student *student = new Student;
	listStudent vlist;
	while (1)
	{
		cout << "______________MENU______________" << endl;
		cout << "\t1. Input" << endl;
		cout << "\t2. Display" << endl;
		cout << "\t3. Save to file" << endl;
		cout << "\t4. Load from file" << endl;
		cout << "\t0. Exit" << endl;
		cout << "_________________________________" << endl;
		cout << "Choose: ";
		cin >> choice;
		switch (choice) {
		case 1:
			InputStudentsInfor(&vlist, student);
			break;
		case 2:
			DisplayStudentInfor(&vlist);
			break;
		case 3:
			SaveToFile(&vlist);
			break;
		case 0:
			vlist.clear();
			exit(1);
			break;
		default:
			cout << "Invalid number, please enter again!: \t"<<endl;
			break;
		}
	}
	system("pause");
}