#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the maximum number of employees and the maximum length of employee names and departments
#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 50
#define MAX_DEPT_LENGTH 50

// Define a struct for employee records
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char department[MAX_DEPT_LENGTH];
    float salary;
} Employee;

// Declare global variables for the employee database and the current number of employees
Employee employees[MAX_EMPLOYEES];
int num_employees = 0;

// Function to print a menu of options for the user
void print_menu() {
    printf("\nEmployee Management System\n");
    printf("--------------------------\n");
    printf("1. Add Employee\n");
    printf("2. Search Employee\n");
    printf("3. Update Employee\n");
    printf("4. Delete Employee\n");
    printf("5. List Employees\n");
    printf("6. Exit\n");
    printf("\nEnter your choice: ");
}

int find_employee_index(int id) {
    int i;
    for (i = 0; i < num_employees; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}
// Function to add a new employee record to the database
void add_employee() {
    Employee employee;
    printf("\nEnter employee ID: ");
    scanf("%d", &employee.id);
    printf("Enter employee name: ");
    scanf("%s", employee.name);
    printf("Enter employee department: ");
    scanf("%s", employee.department);
    printf("Enter employee salary: ");
    scanf("%f", &employee.salary);
    employees[num_employees++] = employee;
    printf("Employee record added successfully.\n");
}

// Function to search for an employee record by ID
void search_employee() {
    int id;
    printf("\nEnter employee ID: ");
    scanf("%d", &id);
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee found:\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Salary: %.2f\n", employees[i].salary);
            return;
        }
    }
    printf("\nEmployee not found.\n");
}

// Function to update an employee record by ID
void update_employee() {
    int id;
    printf("\nEnter employee ID: ");
    scanf("%d", &id);
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].id == id) {
            printf("\nEnter new employee name: ");
            scanf("%s", employees[i].name);
            printf("Enter new employee department: ");
            scanf("%s", employees[i].department);
            printf("Enter new employee salary: ");
            scanf("%f", &employees[i].salary);
            printf("Employee record updated successfully.\n");
            return;
        }
    }
    printf("\nEmployee not found.\n");
}

// Function to delete an employee record by ID
// Function to delete an employee record from the database
void delete_employee() {
    int id;
    printf("\nEnter the ID of the employee you want to delete: ");
    scanf("%d", &id);
    int index = find_employee_index(id);
    if (index == -1) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }
    for (int i = index; i < num_employees - 1; i++) {
        employees[i] = employees[i + 1];
    }
    num_employees--;
    printf("Employee with ID %d deleted successfully.\n", id);
}

// Function to list all employee records in the database
void list_employees() {
    printf("\nEmployee List:\n");
    printf("----------------\n");
    for (int i = 0; i < num_employees; i++) {
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
          printf("Department: %s\n", employees[i].department);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                search_employee();
                break;
            case 3:
                update_employee();
                break;
            case 4:
                delete_employee();
                break;
            case 5:
                list_employees();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}
