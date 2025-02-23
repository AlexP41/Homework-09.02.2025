/*

ВИЗНАЧЕННЯ СТРУКТУР
===================


Завдання знайдете за посиланням
	https://materials.itstep.org/content/d13e2cb9-a875-4643-9ba8-b6009a467cfb/uk/?cache=0


№1 - використовувати оператори new/delete
№2 - використовувати бібліотеку vector


Навчальний матеріал за посиланням http://surl.li/umeci


Результат роботи: посилання на GitHub

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

Завдання 1

Описати структуру Student (прізвище, група, успішність (масив із 5 int)). Створити масив студентів і написати програму, що дозволяє:

Динамічно змінювати розмір масиву;
Виводити список відмінників (>75% відмінних оцінок);
Виводити список двієчників (>50% оцінок 2 і 3).

*/


#pragma region Exercise 1


    exercise(1);

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


/*

Завдання 2

Описати структуру Man (Прізвище, Ім'я, Вік, Дата народження). Створити масив, передбачити:

Виведення інформації із сортуванням за прізвищем або ім'ям;
Виведення списку іменинників місяця із зазначенням дати народження;
Зміну розмірів масиву під час додавання і видалення записів;
Пошук за прізвищем та ім'ям;
Редагування запису.

*/

#pragma region Exercise 2


    exercise(2);


    int size = 3;
    int choice2;

    Man* people = new Man[size];

    people[0] = { "Іваненко", "Іван", 30, 15, 8, 1994 };
    people[1] = { "Петренко", "Петро", 25, 22, 3, 1999 };
    people[2] = { "Сидоренко", "Сидір", 40, 5, 12, 1984 };

    do {
        while (true) {
            cout << "\t\t\t\033[042mМеню:\033[0m\n";
            cout << "\033[033m1. Додати людину\n";
            cout << "2. Видалити людину\n";
            cout << "3. Редагувати дані людини\n";
            cout << "4. Вивести список людей\n";
            cout << "5. Відсортувати список\n";
            cout << "6. Пошук іменинників за місяцем\n";
            cout << "0. Вихід\033[0m\n";
            cout << "Ваш вибір: ";
            cin >> choice2;
            cin.ignore();  

            if (cin.fail()) {
                cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
                cin.clear();  
                cin.ignore(1000, '\n');  
                continue;
            }

            if (choice2 < 0 || choice2 > 6) {
                cout << "\033[031m Помилка! Будь ласка, введіть число в діапазоні від 0 до 6.\033[0m\n";
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
            cout << "Сортувати за прізвищем? (1 - так, 0 - ні): ";
            cin >> bySurname;
            printSorted(people, size, bySurname);
            break;
        }
        case 6:
            printBirthdayMonth(people, size); break;
        case 0:
            cout << "Вихід...\n";
            break;
        default:
            cout << "Неправильний вибір, спробуйте ще раз.\n";
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


// EXERCISE 2

void addPerson(Man*& people, int& size) {
    Man* newPeople = new Man[size + 1];
    for (int i = 0; i < size; i++) {
        newPeople[i] = people[i];
    }

    cout << "\nДодавання людини:" << endl;
    cout << "Прізвище: ";
    cin >> newPeople[size].surname;
    cout << "Ім'я: ";
    cin >> newPeople[size].name;
    cout << "Вік: ";
    cin >> newPeople[size].age;
    cout << "День народження: ";
    cin >> newPeople[size].birthDay;
    cout << "Місяць народження: ";
    cin >> newPeople[size].birthMonth;
    cout << "Рік народження: ";
    cin >> newPeople[size].birthYear;

    delete[] people;
    people = newPeople;
    size++;
    cout << "\033[042mЛюдину додано!\033[0m" << endl;
}


void deletePerson(Man*& people, int& size) {
    if (size == 0) {
        cout << "\n\033[041mСписок порожній!\033[0m" << endl;
        return;
    }

    string surname;
    cout << "\nВведіть прізвище для видалення: ";
    cin >> surname;

    int index = -1;
    for (int i = 0; i < size; i++) {
        if (people[i].surname == surname) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "\033[041mЛюдину не знайдено!\033[0m" << endl;
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
    cout << "\033[042mЛюдину видалено!\033[0m" << endl;
}


void editPerson(Man* people, int size) {
    if (size == 0) {
        cout << "\n\033[041mСписок порожній!\033[0m" << endl;
        return;
    }

    string surname;
    cout << "\nВведіть прізвище для редагування: ";
    cin >> surname;

    for (int i = 0; i < size; i++) {
        if (people[i].surname == surname) {
            cout << "Нове ім'я: ";
            cin >> people[i].name;
            cout << "Новий вік: ";
            cin >> people[i].age;
            cout << "Новий день народження: ";
            cin >> people[i].birthDay;
            cout << "Новий місяць народження: ";
            cin >> people[i].birthMonth;
            cout << "Новий рік народження: ";
            cin >> people[i].birthYear;
            cout << "\033[042mДані оновлено!\033[0m" << endl;
            return;
        }
    }
    cout << "\033[041mЛюдину не знайдено!\033[0m" << endl;
}


void searchPerson(Man* people, int size) {
    if (size == 0) {
        cout << "\n\033[041mСписок порожній!\033[0m" << endl;
        return;
    }

    string surname;
    cout << "\nВведіть прізвище для пошуку: ";
    cin >> surname;

    for (int i = 0; i < size; i++) {
        if (people[i].surname == surname) {
            cout << "\033[042mЗнайдено: \033[0m" << people[i].surname << " " << people[i].name
                << ", Вік: " << people[i].age << " років, Дата нар.: "
                << people[i].birthDay << "." << people[i].birthMonth << "." << people[i].birthYear << endl;
            return;
        }
    }
    cout << "\033[041mЛюдину не знайдено!\033[0m" << endl;
}


void printPeople(Man* people, int size) {
    if (size == 0) {
        cout << "\n\033[041mСписок порожній!\033[0m" << endl;
        return;
    }

    cout << "\nСписок людей:" << endl;
    for (int i = 0; i < size; i++) {
        cout << people[i].surname << " " << people[i].name << ", Вік: "
            << people[i].age << " років, Дата нар.: " << people[i].birthDay << "."
            << people[i].birthMonth << "." << people[i].birthYear << endl;
    }
}


void printSorted(Man* people, int size, bool bySurname) {
    if (size == 0) {
        cout << "\n\033[041mСписок порожній!\033[0m" << endl;
        return;
    }

    sort(people, people + size, [bySurname](const Man& a, const Man& b) {
        return bySurname ? a.surname < b.surname : a.name < b.name;
        });

    printPeople(people, size);
}


void printBirthdayMonth(Man* people, int size) {
    if (size == 0) {
        cout << "\n\033[041mСписок порожній!\033[0m" << endl;
        return;
    }

    int month;
    cout << "\nВведіть номер місяця для пошуку іменинників: ";
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
        cout << "\033[041mНемає іменинників у цьому місяці!\033[0m" << endl;
    }
}



#pragma endregion