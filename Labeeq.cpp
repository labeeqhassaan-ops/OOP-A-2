#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Employee {
private:
    char* name;
    int id;
    float salary;
    static int count;
    static const string companyName;

public:
    Employee(const char* n, int id, float salary)
        : id(id), salary(salary) {
        this->name = new char[strlen(n) + 1];
        strcpy(this->name, n);
        count++;
    }

    Employee(const Employee& e) {
        name = new char[strlen(e.name) + 1];
        strcpy(name, e.name);
        id = e.id;
        salary = e.salary;
        count++;
    }

    void display() const {
        cout << "Company: " << companyName << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl << endl;
    }

    static void showCount() {
        cout << "Total Employees: " << count << endl << endl;
    }

    void setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    Employee returnBonusEmployee() const {
        Employee temp("Bonus Employee", 999, salary + 500);
        return temp;
    }

    ~Employee() {
        delete[] name;
    }
};


int Employee::count = 0;
const string Employee::companyName = "Tech Solutions";


void showEmployee(Employee e) {
    cout << "Employee Data (Passed by Value)" << endl;
    e.display();
}


int main() {
    cout << "Employee Management System" << endl << endl;

    Employee* e1 = new Employee("Ali", 101, 55000);
    Employee* e2 = new Employee("Gogi", 102, 50000);

    cout << "Displaying Employee Details" << endl;
    e1->display();
    e2->display();

    Employee::showCount();

    cout << "Deep Copy Demonstration" << endl;
    Employee e3 = *e1;  
    e1->setName("Teefi");

    cout << "Original Object after change:" << endl;
    e1->display();

    cout << "Copied Object:" << endl;
    e3.display();

    cout << "Showing Employee (*e2) passed by value:" << endl;
    showEmployee(*e2);

    cout << "Object Returned from Function:" << endl;
    Employee bonus = e2->returnBonusEmployee();
    bonus.display();

    delete e1;
    delete e2;

    cout << "Program Completed Successfully" << endl;
    return 0;
}
