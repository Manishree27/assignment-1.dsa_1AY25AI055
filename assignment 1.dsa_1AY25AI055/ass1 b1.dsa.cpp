#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int   roll_no;
    char  name[20];
    float marks;
} Student;
void read_record(Student *p) {
    printf("Enter roll, name, marks: ");
    scanf("%d %19s %f", &p->roll_no, p->name, &p->marks);
}
void show_stats(Student *arr, int n, const char *label) {
    if (n == 0) {
        printf("No records to display.\n");
        return;
}
float  sum  = 0.0f;
    Student *top = arr;                 
 for (int i = 0; i < n; i++) {
        Student *cur = arr + i;         
        sum += cur->marks;
        if (cur->marks > top->marks) {
            top = cur;
     }
printf("%s: %.2f\n", label, sum / n);
if (strcmp(label, "Average marks") == 0) {
        printf("Topper: %s (Roll %d, Marks %.2f)\n",
               top->name, top->roll_no, top->marks);
}
int main(void) {
    int n;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of students.\n");
        return 1;
    }
Student *arr = (Student *)malloc(n * sizeof(Student));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
for (int i = 0; i < n; i++) {
        read_record(arr + i);           
   }
}
show_stats(arr, n, "Average marks");
char choice;
    printf("\nAdd 2 more students? (y/n): ");
    scanf(" %c", &choice);
 if (choice == 'y' || choice == 'Y') {
        Student *temp = (Student *)realloc(arr, (n + 2) * sizeof(Student));
        if (temp == NULL) {
            fprintf(stderr, "Reallocation failed. Existing data preserved.\n");
            free(arr);                  
            return 1;
        }
        arr = temp;
for (int i = 0; i < 2; i++) {
            read_record(arr + n + i);   
        }
        n += 2;
show_stats(arr, n, "Updated average marks");
}
free(arr);
    return 0;
}
