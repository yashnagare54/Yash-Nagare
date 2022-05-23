//
// Created by NIHAAL on 1/21/2022.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;


const int MAX = 20;


class Student {
    int roll_no;
    char name[20]{}, city[20]{};
    char div;
    int year;
public:
    Student() {
        strcpy(name, "");
        strcpy(city, "");
        roll_no = year = div = 0;
    }

    Student(int roll_no, char name[MAX], int year, char div, char city[MAX]) {
        strcpy(this->name, name);
        strcpy(this->city, city);
        this->roll_no = roll_no;
        this->year = year;
        this->div = div;
    }

    int getRollNo() {
        return roll_no;
    }

    void displayRecord() {
        cout << setw(5) << roll_no << setw(8) << name << setw(20) << year << setw(10) << div << setw(10)
        << city << endl;
    }
};

//==========File Operations ===========

class FileOperations {
    fstream file;
public:
    FileOperations(char *filename) {
        file.open(filename, ios::in | ios::out);
    }

    void insertRecord(int roll_no, char name[MAX], int year, char div, char city[MAX]) 
    {
        Student s1(roll_no, name, year, div, city);
        file.seekp(0, ios::end);
        file.write((char *) &s1, sizeof(Student));
        file.clear();
    }

    void displayAll() 
    {
        Student s1;
        file.seekg(0, ios::beg);
        while (file.read((char *) &s1, sizeof(Student))) 
        {
            s1.displayRecord();
        }
        file.clear();
    }

    void displayRecord(int rollNo) {
        Student s1;
        file.seekg(0, ios::beg);
        bool flag = false;
        while (file.read((char *) &s1, sizeof(Student)))
        {
            if (s1.getRollNo() == rollNo)
            {
                cout << setw(5) << "ROLL" << setw(8) << "NAME" << setw(20) << "YEAR" << setw(10) << "DIV"
                     << setw(8) << "CITY" << endl;
                s1.displayRecord();
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << "No records found!!";
        }
        file.clear();
    }

    void deleteRecord(int roll_no)
    {
        ofstream outFile("new.dat", ios::binary);
        file.seekg(0, ios::beg);
        bool flag = false;
        Student s1;
        while (file.read((char *) &s1, sizeof(Student)))
        {
            if (s1.getRollNo() == roll_no)
            {
                flag = true;
                cout << "Success!" << endl;
                continue;
            }
            outFile.write((char *) &s1, sizeof(Student));
        }
        if (!flag)
        {
            cout << "No records found!!"<<endl;
        }
        file.close();
        outFile.close();
        remove("student.dat");
        rename("new.dat", "student.dat");
        file.open("student.dat", ios::in | ios::out);
    }

    ~FileOperations() 
    {
        file.close();
        cout << "File Closed!";
    }
};

int main()
{
    ofstream newFile("student.dat", ios::app | ios::binary);
    newFile.close();
    FileOperations file((char *) "student.dat");
    int rollNo, year, choice = 0;
    char div;
    char name[MAX], city[MAX];
    cout << "\n*****Student Database*****\n  1) Add Record\n  2) Display All Records\n  3) Display by Roll No.\n  4) Del"
            "ete a Record\n  5) Exit" << endl;
    while (choice != 5)
    {
        cout << "\nChoice: ";
        cin >> choice;
         switch (choice)
        {
            case 1 : //New Record
                cout << "Roll No.: ", cin >> rollNo;
                cout << "Name: ", cin >> name;
                cout << "Year: ", cin >> year;
                cout << "Division: ", cin >> div;
                cout << "City: ", cin >> city;
                file.insertRecord(rollNo, name, year, div, city);
                cout << "Success!" << endl;
                break;
            case 2 :
                cout << setw(5) << "ROLL" << setw(8) << "NAME" << setw(20) << "YEAR" << setw(10) << "DIV"
                     << setw(8) << "CITY" << endl;
                file.displayAll();
                break;
            case 3 :
                cout << "Enter Roll No.: ";
                cin >> rollNo;
                file.displayRecord(rollNo);
                break;
            case 4:
                cout << "Enter Roll No.: ";
                cin >> rollNo;
                file.deleteRecord(rollNo);
                break;
            case 5:
                cout << "Exiting..."<<endl;
                exit(0);
        }
    }
    return 0;
}