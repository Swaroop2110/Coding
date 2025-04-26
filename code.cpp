#include <bits/stdc++.h>
using namespace std;

struct Employee{
    int empId;
    string empName;
    string empDOB;
    string empDesignation;
    double basicSal;
    double DA;
    double HRA;
    double grossSal;
};
void calculate(Employee* emp){
    emp->DA = emp->basicSal * 0.27;
    emp->HRA = emp->basicSal * 0.10;
    emp->grossSal = emp->basicSal + emp->DA + emp->HRA;

}
void display(Employee* emp){
    cout << "EMPLOYEE ID : " << emp->empId;
    cout << "EMPLOYEE NAME : " << emp->empId;
    cout << "DATE OF BIRTH : " << emp->empId;
    cout << "DESIGNATION : " << emp->empId;
    cout << "BASIC SALARY : " << emp->empId;
    cout << "DA : " << emp->empId;
    cout << "HRA : " << emp->empId;
    cout << "GROSS SALARY : " << emp->empId;
}
int main(){
    int n;
    cout << "ENTER THE NUMBER OF EMPLOYEES : ";
    cin >> n;
    vector<Employee*> employees(n);
     for (int i = 0; i < n; ++i) {
        employees[i] = new Employee;
        cout << "Enter details for employee " << i + 1 << endl;
        cout << "Employee ID: ";
        cin >> employees[i]->empId;
        cout << "Name: ";
        cin.ignore();
        getline(cin, employees[i]->empName);
        cout << "Date of Birth: ";
        getline(cin, employees[i]->empDOB);
        cout << "Designation: ";
        getline(cin, employees[i]->empDesignation);
        cout << "Basic Salary: ";
        cin >> employees[i]->basicSal;
        calculate(employees[i]);
    }
    sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
        return a->empId < b->empId;
    });
    cout << "\nEmployee Details :\n";
    for (int i = 0; i < n; ++i) {
        display(employees[i]);
        delete employees[i];  
    }
    return 0;





}