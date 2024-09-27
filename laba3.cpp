#include <iostream>
#include <locale.h>
#include <vector>


class Student{
    friend void printStudentDetails(Student &);
    friend std::istream& operator >> (std :: istream& in, Student &s); 

    private: 
        std::string name;
        int age;
        static inline int amount{};
    
    public:
    
        void setName();
        void setAge();

        std::string getName();
        int getAge();

        static void printNameByPointer(Student *);
        void updateAgeByReference(int &);

        static Student* createStudentArray();
        static void printStudentArray(Student*);

        Student();
        Student(std :: string n, int a) : name(n), age(a) {}
        ~Student();

    protected :
        void DisplayName(); 

}; 

void  printStudentDetails(Student &s) {
    std :: cout << "Все данные на студента: " << std :: endl << "Имя - " << s.name << " возраст - " << s.age;
}

void Student :: setName() {
    std::cout << "Введите имя студента ";
    std::string name;
    std::cin >> name;
    this->name = name;
}

void Student :: setAge() {
    std :: cout << "Введите возраст студента ";
    std :: cin >> age;
}

std::string Student :: getName () {
    return name;
}

int Student :: getAge () {
    return age;
}

Student :: Student() {
    std :: cout << std :: endl;
    setName();
    std :: cout << std::endl;
    setAge();
}

Student :: ~Student() {
    std::cout << std:: endl <<"Объект удален!" << std::endl;
}

void Student :: printNameByPointer(Student *student) {
    std :: cout << "Имя студента - " << student->name;
}

void Student :: DisplayName() {
    std :: cout << "Имя студента - " << name;
}

void Student :: updateAgeByReference(int &age) {
    this -> age = age;
}

Student* Student :: createStudentArray() {
    std :: cout << "Введите размер массива ";
    std :: cin >> amount;
    Student *s = new Student[amount];
    return s;
}

void Student :: printStudentArray(Student * s) {
    for (int i = 0; i < amount; i++) {
        std :: cout << "Студент " << i << ": имя - " << s[i].name << ", возраст - " << s[i].age << std:: endl;
    }
}


Student* operator + (Student &s1, Student &s2) {
    Student* s = new Student(s1.getName() + s2.getName(), s1.getAge() + s2.getAge());
    return s;
}


bool operator == (Student &s1, Student &s2) {
    if (s1.getAge() == s2.getAge() && s1.getName() == s2.getName()) 
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& stream,  Student &s) {
    stream << "Имя студента - " << s.getName() << ", возраст - " << s.getAge() << std :: endl;
    return stream; 
}

std :: istream& operator>>(std :: istream& in, Student &s) {
    in >> s.name >> s.age;
    return in; 
}


class GraduateStudent : Student {
    public:
        void showInfo();       
};

void GraduateStudent :: showInfo() {
    DisplayName();
}


int main() {
    setlocale(LC_ALL, "rus");

    std :: cout << "Инициализация 3 студентов: ";
    Student* a = new Student;
    Student* b = new Student;
    GraduateStudent* c = new GraduateStudent;
    std :: cout << std :: endl << "Вывод информации о студентах: " << std :: endl << "Через printNameByPointer: ";
    Student :: printNameByPointer(a);
    std :: cout << std :: endl << "Через printStudentDetails: ";
    printStudentDetails(*b);
    std :: cout << std :: endl << "Через ShowInfo: ";
    c->showInfo();

    std :: cout << std :: endl << "Обновление возраста студента: введите значение ";
    int age;
    std :: cin >> age;
    a->updateAgeByReference(age);
    std :: cout << std :: endl <<"Новые данные студента: " << *a;

    std :: cout << std :: endl << "Перегрузка операторов: " << std :: endl << "Введите информацию о новом испытуемом: ";
    Student* d = new Student;
    std :: cout << std :: endl << "Считываем новые данные(оператор >>) ";
    std :: cin >> *d;
    std :: cout << *d;
    b  = *d + *a;
    std :: cout << std :: endl << "Сложение 2 студентов: " << *b;
    if (*a == *b) {std :: cout << std :: endl << "Студент a равен студенту b";} else {std :: cout << std :: endl << "Студент a не равен студенту b";}


    std :: cout << std :: endl << "Создание массива студентов: ";
    Student *s = Student :: createStudentArray();
    Student :: printStudentArray(s);
    


}