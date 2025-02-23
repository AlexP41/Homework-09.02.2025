/*

ВИЗНАЧЕННЯ СТРУКТУР
===================


Завдання знайдете за посиланням
	https://materials.itstep.org/content/d13e2cb9-a875-4643-9ba8-b6009a467cfb/uk/?cache=0


№1 - використовувати оператори new/delete
№2 - використовувати бібліотеку vector


Навчальний матеріал за посиланням http://surl.li/umeci


Результат роботи: посилання на GitHub





Завдання 1

Описати структуру Student (прізвище, група, успішність (масив із 5 int)). Створити масив студентів і написати програму, що дозволяє:

Динамічно змінювати розмір масиву;
Виводити список відмінників (>75% відмінних оцінок);
Виводити список двієчників (>50% оцінок 2 і 3).



Завдання 2

Описати структуру Man (Прізвище, Ім'я, Вік, Дата народження). Створити масив, передбачити:

Виведення інформації із сортуванням за прізвищем або ім'ям;
Виведення списку іменинників місяця із зазначенням дати народження;
Зміну розмірів масиву під час додавання і видалення записів;
Пошук за прізвищем та ім'ям;
Редагування запису.

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
        {"Петренко", "ІП-11", {12, 11, 10, 12, 11}},
        {"Іваненко", "КН-21", {4, 6, 5, 6, 3}},
        {"Сидоренко", "МТ-31", {9, 10, 12, 11, 8}}
    };


    int choice = -1;

    while (choice != 0)
    {
        while (true)
        {
            cout << "\n\t\t\033[042mМеню:\033[0m\n";
            cout << "\033[033m1. Додати студента\n";
            cout << "2. Вивести список студентів\n";
            cout << "3. Вивести відмінників\n";
            cout << "4. Вивести двієчників\n";
            cout << "5. Видалити студента\n";
            cout << "0. Вихід\033[0m\n";
            cout << "Ваш вибір: ";
            cin >> choice;
            cin.ignore(); 

          
            if (cin.fail()) {
                cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
                cin.clear(); 
                cin.ignore(1000, '\n'); 
                continue;
            }
           
            if (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 ) {
                cout << "\033[031m Помилка! Будь ласка, введіть число в діапазоні від 0 до 5 (включно).\033[0m\n";
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
            cout << "Вихід...\n";
            break;
        default:
            cout << "Неправильний вибір, спробуйте ще раз.\n";
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
        cout << "Введіть прізвище студента: ";
        getline(cin, student.lastName);

        if (cin.fail()) {
            cout << "\033[031m Помилка! Будь ласка, введіть корректне прізвище.\033[0m\n";
            cin.clear(); 
            cin.ignore(1000, '\n');
            continue;
        }

        if (student.lastName.empty())
        {
            cout << "\033[031m Помилка! Схоже Ви ввели пустий рядок.\033[0m\n";
            continue;
        }
        
        break;
        

    }


    while (true)
    {
        cout << "Введіть групу студента: ";
        getline(cin, student.group);

        if (cin.fail()) {
            cout << "\033[031m Помилка! Будь ласка, введіть корректну групу студента.\033[0m\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (student.group.empty())
        {
            cout << "\033[031m Помилка! Схоже Ви ввели пустий рядок.\033[0m\n";
            continue;
        }

        break;


    }
 
    while (true)
    {
        cout << "Скільки оцінок у студента? ";
        cin >> numGrades;

        if (cin.fail()) {
            cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            continue;
        }
        
        if (numGrades < 0)
        {
            cout << "\033[031m Помилка! Будь ласка, введіть число >= 0.\033[0m\n";
            continue;
        }

        break;
        

    }

    student.grades.resize(numGrades);
    cout << "Введіть " << numGrades << " оцінок через пробіл: " << endl;

    int count = 0;
    for (int& grade : student.grades) {
        ++count;
        while (true)
        {
            cout << "Оцінка №" << count << ": ";
            cin >> grade;

            if (cin.fail()) {
                cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (grade < 1)
            {
                cout << "\033[031m Помилка! Будь ласка, введіть число >= 1.\033[0m\n";
                continue;
            }

            if (grade > 12)
            {
                cout << "\033[031m Помилка! Будь ласка, введіть число <= 12.\033[0m\n";
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
        cout << "Список студентів порожній.\n";
        return;
    }

    cout << left << setw(15) << "Прізвище"
        << setw(10) << "Група"
        << "Оцінки (середній бал)" << endl;
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
    cout << "\nСписок відмінників:\n";
    bool found = false;
    for (const auto& student : students) {
        if (isExcellent(student)) {
            cout << student.lastName << " (" << student.group << ")\n";
            found = true;
        }
    }
    if (!found) cout << "Немає відмінників.\n";
}


void printFailingStudents(const vector<Student>& students) {
    cout << "\nСписок двієчників:\n";
    bool found = false;
    for (const auto& student : students) {
        if (isFailing(student)) {
            cout << student.lastName << " (" << student.group << ")\n";
            found = true;
        }
    }
    if (!found) cout << "Немає двієчників.\n";
}


void removeStudent(vector<Student>& students) {
    cout << "\nВведіть прізвище студента, якого треба видалити: ";
    string surname;
    getline(cin, surname);

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->lastName == surname) {
            students.erase(it);
            cout << "Студента видалено!\n";
            return;
        }
    }
    cout << "Студента не знайдено.\n";
}

#pragma endregion