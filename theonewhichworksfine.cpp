#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <string_view>
#include <regex>
#include <stdio.h>
using namespace std;
class student
{
private:
    string name, roll_no, sub1, sub4, sub2, sub3;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void deleted();
};
void student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT REPORT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Report" << endl;
    cout << "\t\t\t 2. Display Report" << endl;
    cout << "\t\t\t 3. Modify Report" << endl;
    cout << "\t\t\t 4. Delete Report" << endl;
    cout << "\t\t\t 5. Exit" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add Another Student Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        deleted();
        break;
    case 5:
        exit(0);
    default:
        cout << "\n\t\t\t Oops!! INVALID ";
    }
    getch();
    goto menustart;
}
void student::insert()
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Insert Student Details ---------------------------------------------" << endl;
   
    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\t\t\tEnter mark in subject 1 : ";
    cin >> sub1;
    cout << "\t\t\tEnter mark in subject 2 : ";
    cin >> sub2;
    cout << "\t\t\tEnter mark in subject 3 : ";
    cin >> sub3;
    cout << "\t\t\tEnter mark in subject 4 : ";
    cin >> sub4;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << sub1 << " " << sub2 << " " << sub3 << " " << sub4 << "\n";
    file.close();
}

void student::display()
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        
        cout << "\n\t\t\tNo Data Is available...";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> sub1 >> sub2 >> sub3 >> sub4;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Student No.: " << total++ << endl;
            cout << "\t\t\t Student Name: " << name << endl;
            cout << "\t\t\t Student Roll No.: " << roll_no << endl;
            cout << "\t\t\t sub1 : " << sub1 << endl;
            cout << "\t\t\t sub2 : " << sub2 << endl;
            cout << "\t\t\t sub3 : " << sub3 << endl;
            cout << "\t\t\t sub4 : " << sub4 << endl;
            file >> name >> roll_no >> sub1 >> sub2 >> sub3 >> sub4;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is available...";
        }
    }
    file.close();
}
void student::modify() 
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is available..";
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> sub1 >> sub2 >> sub3 >> sub4;
        while (!file.eof())
        {
            if (rollno != roll_no)

                file1 << " " << name << " " << roll_no << " " << sub1 << " " << sub2 << " " << sub3 << " " <<sub4 << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter sub1: ";
                cin >> sub1;
                cout << "\t\t\tEnter sub2: ";
                cin >> sub2;
                cout << "\t\t\tEnter sub3: ";
                cin >> sub3;
                cout << "\t\t\tEnter sub4: ";
                cin >> sub4;
                file1 << " " << name << " " << roll_no << " " << sub1 << " " << sub2 << " " << sub3 << " " << sub4 << "\n";
                found++;
            }
            file >> name >> roll_no >> sub1 >> sub2 >> sub3 >> sub4;
            if (found == 0)
            {
                cout << "\n\n\t\t\t Student Roll No. Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
void student::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is available..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data:";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> sub1 >> sub2 >> sub3 >> sub4;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << sub1 << " " << sub2 << " " << sub3 << " " << sub4 << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> sub1 >> sub2 >> sub3 >> sub4;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
main()
{
    student project;
    project.menu();
    return 0;
} 