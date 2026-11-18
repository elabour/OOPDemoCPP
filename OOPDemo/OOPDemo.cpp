
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class
class Address
{
protected:
    string address;

public:
    Address(const string& address)
        : address(address) {
    }

    string getAddress() const
    {
        return address;
    }
};

// Person inherits from Address
class Person : public Address
{
protected:
    string name;
    string phone;

public:
    Person(const string& name,
        const string& phone,
        const string& address)
        : Address(address), name(name),
        phone(phone) 
    { }

    string getName() const
    {
        return name;
    }

    string getPhone() const
    {
        return phone;
    }
};

// Grading represents one course and its mark
class Grading
{
private:
    string course_name;
    float mark;

public:
    Grading(const string& course_name, float mark)
        : course_name(course_name), mark(mark) {
    }

    string getCourseName() const
    {
        return course_name;
    }

    float getMark() const
    {
        return mark;
    }
};

// Student inherits from Person
// Student has multiple Grading objects (Composition)
class Student : public Person
{
private:
    vector<Grading> grades;

public:
    Student(const string& name,
        const string& phone,
        const string& address)
        : Person(name, phone, address) {
    }

    // Add a course and its mark
    void addGrade(const string& course_name, float mark)
    {
        grades.push_back(Grading(course_name, mark));
    }

    // Display student information and all grades
    void displayStudent() const
    {
        cout << "\n========== Student Information ==========\n";
        cout << "Name: " << getName() << endl;
        cout << "Phone: " << getPhone() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "\n========== Student Grades ===============\n";
        for (const Grading& grade : grades)
        {
            cout << "Course: " << grade.getCourseName()
                << " | Mark: " << grade.getMark() << endl;
        }
    }
};

// Teacher inherits from Person
class Teacher : public Person
{
public:
    Teacher(const string& name,
        const string& phone,
        const string& address)
        : Person(name, phone, address) {
    }

    void displayTeacher() const
    {
        cout << "\n========== Teacher Information ==========\n";

        cout << "Name: " << getName() << endl;
        cout << "Phone: " << getPhone() << endl;
        cout << "Address: " << getAddress() << endl;
    }
};

// Main function
int main()
{
    // Create a student
    Student student1("Ahmed Ali","0912345678","Tripoli");
    // Add multiple courses and marks
    student1.addGrade("OOP", 85);
    student1.addGrade("Database", 90);
    student1.addGrade("Data Structures", 78);
    student1.addGrade("Software Engineering", 95);
    // Display student information
    student1.displayStudent();
    // Create a teacher
    Teacher teacher1("Mohamed Omar","0923456789","Misurata");
     // Display teacher information
    teacher1.displayTeacher();
    return 0;
}
