
#include <iostream>
#include <string>
using namespace std;

class Address
{
protected:
    string address;

public:
    Address(const string& address) : address(address) {}

    string getAddress() const
    {
        return address;
    }
};

class Person : public Address
{
protected:
    string name;
    string phone;

public:
    Person(const string& name, const string& phone, const string& address)
        : Address(address), name(name), phone(phone) {}

    string getName() const
    {
        return name;
    }

    string getPhone() const
    {
        return phone;
    }
};

class Grading
{
protected:
    string course_name;
    float mark;

public:
    Grading(const string& course_name, float mark)
        : course_name(course_name), mark(mark) {}

    string getCourseName() const
    {
        return course_name;
    }

    float getMark() const
    {
        return mark;
    }
};

class Student : public Person, public Grading
{
public:
    Student(const string& name, const string& phone, const string& address,
            const string& course_name, float mark)
        : Person(name, phone, address), Grading(course_name, mark) {}
};

class Teacher : public Person
{
public:
    Teacher(const string& name, const string& phone, const string& address)
        : Person(name, phone, address) {}
};

int main()
{
    Student student("Ahmed Ali", "092-010101010", "Misrata", "OOP", 95.5f);
    Teacher teacher("Jane Teacher", "091-747555555501", "Tripoli");

    cout << "Student: " << student.getName() << '\n'
         << "Phone: " << student.getPhone() << '\n'
         << "Address: " << student.getAddress() << '\n'
         << "Course: " << student.getCourseName() << '\n'
         << "Mark: " << student.getMark() << '\n';

    cout << "\nTeacher: " << teacher.getName() << '\n'
         << "Phone: " << teacher.getPhone() << '\n'
         << "Address: " << teacher.getAddress() << '\n';
}

