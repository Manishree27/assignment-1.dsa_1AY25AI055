#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
typedef struct {
    int row;
    int col;
    int value;
} term;
void fast_transpose(term a[], term b[]) {
    int num_cols = a[0].col;
    int num_terms = a[0].value;
    int row_terms[MAX_TERMS] = {0};
    int starting_pos[MAX_TERMS] = {0};
   for (int i = 1; i <= num_terms; i++) {
        row_terms[a[i].col]++;
    }
    starting_pos[0] = 1;
    for (int i = 1; i < num_cols; i++) {
        starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
    }
    printf("\nrow_terms[] array: ");
    for (int i = 0; i < num_cols; i++) {
        printf("%d ", row_terms[i]);
    }
    printf("\n");
    printf("starting_pos[] array: ");
    for (int i = 0; i < num_cols; i++) {
        printf("%d ", starting_pos[i]);
    }
    printf("\n");
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = num_terms;
    for (int i = 1; i <= num_terms; i++) {
        int col = a[i].col;
        int j = starting_pos[col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}
int main() {
    term a[MAX_TERMS], b[MAX_TERMS];
    int rows, cols;
    int num_terms = 0;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter matrix elements (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int val;
            scanf("%d", &val);
            if (val != 0) {
                num_terms++;
                a[num_terms].row = i;
                a[num_terms].col = j;
                a[num_terms].value = val;
            }
        }
    }
    a[0].row = rows;
    a[0].col = cols;
    a[0].value = num_terms;
    printf("\nOriginal matrix triples:\n");
    printf("Header: rows=%d, cols=%d, num_terms=%d\n", 
           a[0].row, a[0].col, a[0].value);
    for (int i = 1; i <= num_terms; i++) {
        printf("a[%d]: row=%d, col=%d, value=%d\n", 
               i, a[i].row, a[i].col, a[i].value);
    }
    fast_transpose(a, b);
    printf("\nTransposed matrix triples:\n");
    printf("Header: rows=%d, cols=%d, num_terms=%d\n", 
           b[0].row, b[0].col, b[0].value);
    for (int i = 1; i <= num_terms; i++) {
        printf("b[%d]: row=%d, col=%d, value=%d\n", 
               i, b[i].row, b[i].col, b[i].value);
    }
    printf("\nVerifying row-major order in transposed matrix:\n");
    int in_order = 1;
    for (int i = 1; i < num_terms; i++) {
        if (b[i].row > b[i+1].row || 
            (b[i].row == b[i+1].row && b[i].col > b[i+1].col)) {
            in_order = 0;
            break;
        }
    }
  if (in_order) {
        printf("? Transposed triples are in row-major order\n");
    } else {
        printf("? Transposed triples are NOT in row-major order\n");
    }
    return 0;
}
