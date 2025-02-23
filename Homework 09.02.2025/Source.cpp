/*

���������� ��������
===================


�������� �������� �� ����������
	https://materials.itstep.org/content/d13e2cb9-a875-4643-9ba8-b6009a467cfb/uk/?cache=0


�1 - ��������������� ��������� new/delete
�2 - ��������������� �������� vector


���������� ������� �� ���������� http://surl.li/umeci


��������� ������: ��������� �� GitHub





�������� 1

������� ��������� Student (�������, �����, �������� (����� �� 5 int)). �������� ����� �������� � �������� ��������, �� ��������:

�������� �������� ����� ������;
�������� ������ �������� (>75% ������� ������);
�������� ������ �⳺����� (>50% ������ 2 � 3).



�������� 2

������� ��������� Man (�������, ��'�, ³�, ���� ����������). �������� �����, �����������:

��������� ���������� �� ����������� �� �������� ��� ��'��;
��������� ������ ���������� ����� �� ����������� ���� ����������;
���� ������ ������ �� ��� ��������� � ��������� ������;
����� �� �������� �� ��'��;
����������� ������.

*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;



#pragma region Structures

// EXERCISE 1


struct Student {
    string lastName; 
    string group;    
    vector<int> grades; 
};






#pragma endregion




#pragma region Functions prototypes


void addStudent(vector<Student>& students);


void printStudents(const vector<Student>& students);


void printExcellentStudents(const vector<Student>& students);


void printFailingStudents(const vector<Student>& students);


double calculateAverage(const Student& student);


bool isExcellent(const Student& student);


bool isFailing(const Student& student);


void removeStudent(vector<Student>& students);


#pragma endregion

int main()
{
    system("chcp 1251>null");
    srand(time(0));


#pragma region Exercise 1


    vector<Student> students = {
        {"��������", "��-11", {12, 11, 10, 12, 11}},
        {"��������", "��-21", {4, 6, 5, 6, 3}},
        {"���������", "��-31", {9, 10, 12, 11, 8}}
    };


    int choice = -1;

    while (choice != 0)
    {
        while (true)
        {
            cout << "\n\t\t\033[042m����:\033[0m\n";
            cout << "\033[033m1. ������ ��������\n";
            cout << "2. ������� ������ ��������\n";
            cout << "3. ������� ��������\n";
            cout << "4. ������� �⳺�����\n";
            cout << "5. �������� ��������\n";
            cout << "0. �����\033[0m\n";
            cout << "��� ����: ";
            cin >> choice;
            cin.ignore(); 

          
            if (cin.fail()) {
                cout << "\033[031m �������! ���� �����, ������ �����.\033[0m\n";
                cin.clear(); 
                cin.ignore(1000, '\n'); 
                continue;
            }
           
            if (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 ) {
                cout << "\033[031m �������! ���� �����, ������ ����� � ������� �� 0 �� 5 (�������).\033[0m\n";
                continue;
            }

            
            break;
            

        }

        cout << endl;
        switch (choice) {
        case 1:
            addStudent(students);
            break;
        case 2:
            printStudents(students);
            break;
        case 3:
            printExcellentStudents(students);
            break;
        case 4:
            printFailingStudents(students);
            break;
        case 5:
            removeStudent(students);
            break;
        case 0:
            cout << "�����...\n";
            break;
        default:
            cout << "������������ ����, ��������� �� ���.\n";
        }
    }


#pragma endregion


    return 0;
}

#pragma region Functions

// EXERCISE 1

void addStudent(vector<Student>& students) {
    Student student;
    int numGrades;

    while (true)
    {
        cout << "������ ������� ��������: ";
        getline(cin, student.lastName);

        if (cin.fail()) {
            cout << "\033[031m �������! ���� �����, ������ ��������� �������.\033[0m\n";
            cin.clear(); 
            cin.ignore(1000, '\n');
            continue;
        }

        if (student.lastName.empty())
        {
            cout << "\033[031m �������! ����� �� ����� ������ �����.\033[0m\n";
            continue;
        }
        
        break;
        

    }


    while (true)
    {
        cout << "������ ����� ��������: ";
        getline(cin, student.group);

        if (cin.fail()) {
            cout << "\033[031m �������! ���� �����, ������ ��������� ����� ��������.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (student.group.empty())
        {
            cout << "\033[031m �������! ����� �� ����� ������ �����.\033[0m\n";
            continue;
        }

        break;


    }
 
    while (true)
    {
        cout << "������ ������ � ��������? ";
        cin >> numGrades;

        if (cin.fail()) {
            cout << "\033[031m �������! ���� �����, ������ �����.\033[0m\n";
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            continue;
        }
        
        if (numGrades < 0)
        {
            cout << "\033[031m �������! ���� �����, ������ ����� >= 0.\033[0m\n";
            continue;
        }

        break;
        

    }

    student.grades.resize(numGrades);
    cout << "������ " << numGrades << " ������ ����� �����: " << endl;

    int count = 0;
    for (int& grade : student.grades) {
        ++count;
        while (true)
        {
            cout << "������ �" << count << ": ";
            cin >> grade;

            if (cin.fail()) {
                cout << "\033[031m �������! ���� �����, ������ �����.\033[0m\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (grade < 1)
            {
                cout << "\033[031m �������! ���� �����, ������ ����� >= 1.\033[0m\n";
                continue;
            }

            if (grade > 12)
            {
                cout << "\033[031m �������! ���� �����, ������ ����� <= 12.\033[0m\n";
                continue;
            }

            break;

        }
    }
    cin.ignore();

    students.push_back(student);
}


void printStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "������ �������� �������.\n";
        return;
    }

    cout << left << setw(15) << "�������"
        << setw(10) << "�����"
        << "������ (������� ���)" << endl;
    cout << string(50, '-') << endl;

    for (const auto& student : students) {
        cout << left << setw(15) << student.lastName
            << setw(10) << student.group;

        for (int grade : student.grades) {
            cout << grade << " ";
        }

        cout << "(" << fixed << setprecision(2) << calculateAverage(student) << ")";
        cout << endl;
    }
}


double calculateAverage(const Student& student) {
    double sum = 0;
    for (int grade : student.grades) {
        sum += grade;
    }
    return sum / student.grades.size();
}


bool isExcellent(const Student& student) {
    int count5 = 0;
    for (int grade : student.grades) {
        if (grade > 10) count5++;
    }
    return (static_cast<double>(count5) / student.grades.size()) > 0.75;
}


bool isFailing(const Student& student) {
    int countLow = 0;
    for (int grade : student.grades) {
        if (grade < 6) countLow++;
    }
    return (static_cast<double>(countLow) / student.grades.size()) > 0.5;
}


void printExcellentStudents(const vector<Student>& students) {
    cout << "\n������ ��������:\n";
    bool found = false;
    for (const auto& student : students) {
        if (isExcellent(student)) {
            cout << student.lastName << " (" << student.group << ")\n";
            found = true;
        }
    }
    if (!found) cout << "���� ��������.\n";
}


void printFailingStudents(const vector<Student>& students) {
    cout << "\n������ �⳺�����:\n";
    bool found = false;
    for (const auto& student : students) {
        if (isFailing(student)) {
            cout << student.lastName << " (" << student.group << ")\n";
            found = true;
        }
    }
    if (!found) cout << "���� �⳺�����.\n";
}


void removeStudent(vector<Student>& students) {
    cout << "\n������ ������� ��������, ����� ����� ��������: ";
    string surname;
    getline(cin, surname);

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->lastName == surname) {
            students.erase(it);
            cout << "�������� ��������!\n";
            return;
        }
    }
    cout << "�������� �� ��������.\n";
}

#pragma endregion