/*

���������� ��������
===================


�������� �������� �� ����������
	https://materials.itstep.org/content/d13e2cb9-a875-4643-9ba8-b6009a467cfb/uk/?cache=0


�1 - ��������������� ��������� new/delete
�2 - ��������������� �������� vector


���������� ������� �� ���������� http://surl.li/umeci


��������� ������: ��������� �� GitHub

*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;



#pragma region Structures



// EXERCISE 1


struct Student {
    string lastName; 
    string group;    
    vector<int> grades; 
};


// EXERCISE 2


struct Man {
    string surname;
    string name;
    int age;
    int birthDay;
    int birthMonth;
    int birthYear;
};



#pragma endregion




#pragma region Functions prototypes


void exercise(int numberOfExercise);


// EXERCISE 1

void addStudent(vector<Student>& students);


void printStudents(const vector<Student>& students);


void printExcellentStudents(const vector<Student>& students);


void printFailingStudents(const vector<Student>& students);


double calculateAverage(const Student& student);


bool isExcellent(const Student& student);


bool isFailing(const Student& student);


void removeStudent(vector<Student>& students);


// EXEFCISE 2

void addPerson(Man*& people, int& size);


void deletePerson(Man*& people, int& size);


void editPerson(Man* people, int size);


void searchPerson(Man* people, int size);


void printPeople(Man* people, int size);


void printSorted(Man* people, int size, bool bySurname);


void printBirthdayMonth(Man* people, int size);





#pragma endregion




int main()
{
    system("chcp 1251>null");
    srand(time(0));


/*

�������� 1

������� ��������� Student (�������, �����, �������� (����� �� 5 int)). �������� ����� �������� � �������� ��������, �� ��������:

�������� �������� ����� ������;
�������� ������ �������� (>75% ������� ������);
�������� ������ �⳺����� (>50% ������ 2 � 3).

*/


#pragma region Exercise 1


    exercise(1);

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


/*

�������� 2

������� ��������� Man (�������, ��'�, ³�, ���� ����������). �������� �����, �����������:

��������� ���������� �� ����������� �� �������� ��� ��'��;
��������� ������ ���������� ����� �� ����������� ���� ����������;
���� ������ ������ �� ��� ��������� � ��������� ������;
����� �� �������� �� ��'��;
����������� ������.

*/

#pragma region Exercise 2


    exercise(2);


    int size = 3;
    int choice2;

    Man* people = new Man[size];

    people[0] = { "��������", "����", 30, 15, 8, 1994 };
    people[1] = { "��������", "�����", 25, 22, 3, 1999 };
    people[2] = { "���������", "����", 40, 5, 12, 1984 };

    do {
        while (true) {
            cout << "\t\t\t\033[042m����:\033[0m\n";
            cout << "\033[033m1. ������ ������\n";
            cout << "2. �������� ������\n";
            cout << "3. ���������� ��� ������\n";
            cout << "4. ������� ������ �����\n";
            cout << "5. ³���������� ������\n";
            cout << "6. ����� ���������� �� ������\n";
            cout << "0. �����\033[0m\n";
            cout << "��� ����: ";
            cin >> choice2;
            cin.ignore();  

            if (cin.fail()) {
                cout << "\033[031m �������! ���� �����, ������ �����.\033[0m\n";
                cin.clear();  
                cin.ignore(1000, '\n');  
                continue;
            }

            if (choice2 < 0 || choice2 > 6) {
                cout << "\033[031m �������! ���� �����, ������ ����� � ������� �� 0 �� 6.\033[0m\n";
                continue;
            }

            break;  
        }

        switch (choice2) {
        case 1:
            addPerson(people, size); break;
        case 2:
            deletePerson(people, size); break;
        case 3:
            editPerson(people, size); break;
        case 4:
            printPeople(people, size); break;
        case 5: {
            bool bySurname;
            cout << "��������� �� ��������? (1 - ���, 0 - �): ";
            cin >> bySurname;
            printSorted(people, size, bySurname);
            break;
        }
        case 6:
            printBirthdayMonth(people, size); break;
        case 0:
            cout << "�����...\n";
            break;
        default:
            cout << "������������ ����, ��������� �� ���.\n";
        }

    } while (choice2 != 0);

    delete[] people;  


#pragma endregion


    return 0;
}



#pragma region Functions


void exercise(int numberOfExercise)
{
    cout << endl << endl << "\t\t\t\t\033[032mExercise " << numberOfExercise << "\033[0m" << endl << endl;
}


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


// EXERCISE 2

void addPerson(Man*& people, int& size) {
    Man* newPeople = new Man[size + 1];
    for (int i = 0; i < size; i++) {
        newPeople[i] = people[i];
    }

    cout << "\n��������� ������:" << endl;
    cout << "�������: ";
    cin >> newPeople[size].surname;
    cout << "��'�: ";
    cin >> newPeople[size].name;
    cout << "³�: ";
    cin >> newPeople[size].age;
    cout << "���� ����������: ";
    cin >> newPeople[size].birthDay;
    cout << "̳���� ����������: ";
    cin >> newPeople[size].birthMonth;
    cout << "г� ����������: ";
    cin >> newPeople[size].birthYear;

    delete[] people;
    people = newPeople;
    size++;
    cout << "\033[042m������ ������!\033[0m" << endl;
}


void deletePerson(Man*& people, int& size) {
    if (size == 0) {
        cout << "\n\033[041m������ �������!\033[0m" << endl;
        return;
    }

    string surname;
    cout << "\n������ ������� ��� ���������: ";
    cin >> surname;

    int index = -1;
    for (int i = 0; i < size; i++) {
        if (people[i].surname == surname) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "\033[041m������ �� ��������!\033[0m" << endl;
        return;
    }

    Man* newPeople = new Man[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newPeople[j++] = people[i];
        }
    }

    delete[] people;
    people = newPeople;
    size--;
    cout << "\033[042m������ ��������!\033[0m" << endl;
}


void editPerson(Man* people, int size) {
    if (size == 0) {
        cout << "\n\033[041m������ �������!\033[0m" << endl;
        return;
    }

    string surname;
    cout << "\n������ ������� ��� �����������: ";
    cin >> surname;

    for (int i = 0; i < size; i++) {
        if (people[i].surname == surname) {
            cout << "���� ��'�: ";
            cin >> people[i].name;
            cout << "����� ��: ";
            cin >> people[i].age;
            cout << "����� ���� ����������: ";
            cin >> people[i].birthDay;
            cout << "����� ����� ����������: ";
            cin >> people[i].birthMonth;
            cout << "����� �� ����������: ";
            cin >> people[i].birthYear;
            cout << "\033[042m��� ��������!\033[0m" << endl;
            return;
        }
    }
    cout << "\033[041m������ �� ��������!\033[0m" << endl;
}


void searchPerson(Man* people, int size) {
    if (size == 0) {
        cout << "\n\033[041m������ �������!\033[0m" << endl;
        return;
    }

    string surname;
    cout << "\n������ ������� ��� ������: ";
    cin >> surname;

    for (int i = 0; i < size; i++) {
        if (people[i].surname == surname) {
            cout << "\033[042m��������: \033[0m" << people[i].surname << " " << people[i].name
                << ", ³�: " << people[i].age << " ����, ���� ���.: "
                << people[i].birthDay << "." << people[i].birthMonth << "." << people[i].birthYear << endl;
            return;
        }
    }
    cout << "\033[041m������ �� ��������!\033[0m" << endl;
}


void printPeople(Man* people, int size) {
    if (size == 0) {
        cout << "\n\033[041m������ �������!\033[0m" << endl;
        return;
    }

    cout << "\n������ �����:" << endl;
    for (int i = 0; i < size; i++) {
        cout << people[i].surname << " " << people[i].name << ", ³�: "
            << people[i].age << " ����, ���� ���.: " << people[i].birthDay << "."
            << people[i].birthMonth << "." << people[i].birthYear << endl;
    }
}


void printSorted(Man* people, int size, bool bySurname) {
    if (size == 0) {
        cout << "\n\033[041m������ �������!\033[0m" << endl;
        return;
    }

    sort(people, people + size, [bySurname](const Man& a, const Man& b) {
        return bySurname ? a.surname < b.surname : a.name < b.name;
        });

    printPeople(people, size);
}


void printBirthdayMonth(Man* people, int size) {
    if (size == 0) {
        cout << "\n\033[041m������ �������!\033[0m" << endl;
        return;
    }

    int month;
    cout << "\n������ ����� ����� ��� ������ ����������: ";
    cin >> month;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (people[i].birthMonth == month) {
            cout << people[i].surname << " " << people[i].name << " - "
                << people[i].birthDay << "." << people[i].birthMonth << "." << people[i].birthYear << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "\033[041m���� ���������� � ����� �����!\033[0m" << endl;
    }
}



#pragma endregion