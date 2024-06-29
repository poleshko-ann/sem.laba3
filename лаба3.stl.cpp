// 9. Создать абстрактный класс «живое существо». Создать класс «человек»(наследник абстрактного класса), 
// имеющий имя, возраст, вес. Определить конструкторы, деструктор и функцию вывода. Создать public-производный класс – совершеннолетний (от человек), 
// имеющий номер паспорта. Определить конструкторы по умолчанию и с разным числом параметров, деструкторы, функцию вывода. 
// Определить функции переназначения возраста и номера паспорта. Использовать статическую переменную для хранения количества 
// созданных объектов классов наследников и константы для хранения идентификационных номеров в абстрактном классе, в классах наследниках.

#include <iostream>
#include <string>м
using namespace std;

class Being {           //абстрактный класс живое существо
public:
    static int numObjects;
    const int id = 1;
    virtual ~Being() {}
    virtual void display() const = 0;
};

class Human : public Being {  // класс человек - наследник
protected:
    string name;
    int age;
    double weight;
public:
    Human(const string& name, int age, double weight)
        : name(name), age(age), weight(weight) {
        numObjects++;
    }
    ~Human() {}
    void display() const override {
        setlocale(LC_ALL, "ru");
        cout << "имя:" << name << " возраст:" << age << " вес:" << weight <<endl;
    }
    void setAge(int newAge) {
        age = newAge;
    }
};

class Adult : public Human {  //класс совершеннолетний (от человека)
private:
    string passportNumber;
public:
    Adult() : Human("", 0, 0), passportNumber("") {}   // по умолчанию
    Adult(const string& name, int age, double weight, const string& passportNumber)   //разные параметры
        : Human(name, age, weight), passportNumber(passportNumber) {
        numObjects++;
    }
    ~Adult() {}
    void display() const override {  
        Human::display();
        setlocale(LC_ALL, "ru");
        cout << "Номер паспорта: " << passportNumber << endl;
    }
    void setPassportNumber(const string& newPassportNumber) {
        passportNumber = newPassportNumber;
    }
};
int Being::numObjects = 0;

int main() {
    setlocale(LC_ALL, "ru");
    Adult person1("John", 25, 70.5, "1234567890");
    person1.display();
    cout << "Количество созданных объектов: " << Being::numObjects << endl;
    Adult person2("Alice", 30, 65.2, "0987654321");
    person2.display();
    Human person3("ауап4", 25, 70.5 );
    person3.display();
    cout << "Количество созданных объектов: " << Being::numObjects << endl;
    cout << "Изменение номера паспорта и веса" << endl; 
    person2.setAge(35);
    person2.setPassportNumber("1357924680");
    person2.display();
    return 0;
}

