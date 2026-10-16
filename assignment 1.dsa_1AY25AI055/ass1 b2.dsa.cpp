#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char name[20];
    int  emp_id;
    enum { FULL_TIME, CONTRACT } type;
    union {
        float salary;
        struct { float hourly_rate; int hours_worked; } contract_info;
    } pay;
} Employee;
int main() {
    int n = 0;
    float total_company_bill = 0.0;
    printf("Enter the number of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of employees.\n");
        return 1;
    }

    Employee *emp_array = (Employee *)malloc(n * sizeof(Employee));
    if (emp_array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("\n--- Entering details for Employee %d ---\n", i + 1);
        printf("Enter Employee ID: ");
        scanf("%d", &emp_array[i].emp_id)
        printf("Enter Name: ");
        scanf("%s", emp_array[i].name);
        int type_input;
        printf("Enter Type (0 for Full-Time, 1 for Contract): ");
        scanf("%d", &type_input);
        if (type_input == 0) {
            emp_array[i].type = FULL_TIME;
            printf("Enter Fixed Monthly Salary: ");
            scanf("%f", &emp_array[i].pay.salary);
        } else {
            emp_array[i].type = CONTRACT;
            printf("Enter Hourly Rate: ");
            scanf("%f", &emp_array[i].pay.contract_info.hourly_rate);
            printf("Enter Hours Worked: ");
            scanf("%d", &emp_array[i].pay.contract_info.hours_worked);
        }
    }
    printf("\n=================== GENERATING PAYSLIPS ===================\n");
    for (int i = 0; i < n; i++) {
        float individual_pay = 0.0
        printf("\nEmp ID: %d | Name: %s\n", emp_array[i].emp_id, emp_array[i].name);
        if (emp_array[i].type == FULL_TIME) {
            individual_pay = emp_array[i].pay.salary;
            printf("Employment Type: Full-Time\n");
            printf("Monthly Salary:  $%.2f\n", individual_pay);
        } else {
            individual_pay = emp_array[i].pay.contract_info.hourly_rate * emp_array[i].pay.contract_info.hours_worked;
            printf("Employment Type: Contract\n");
            printf("Hourly Rate:     $%.2f\n", emp_array[i].pay.contract_info.hourly_rate);
            printf("Hours Worked:    %d\n", emp_array[i].pay.contract_info.hours_worked);
        }
        printf("Total Payout:    $%.2f\n", individual_pay);
        total_company_bill += individual_pay;
    }
    printf("===========================================================\n");
    printf("\nTotal Company Salary Bill: $%.2f\n", total_company_bill);
    free(emp_array);
    emp_array = NULL;
    return 0;
}
