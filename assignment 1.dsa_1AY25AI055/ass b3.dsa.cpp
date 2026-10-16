#include <stdio.h>
#include <math.h>
#define MAX_DEGREE 100
#define EPSILON    
typedef struct {
    int   degree;
    float coef[101];  
} polynomial
polynomial add(polynomial a, polynomial b) {
    polynomial result;
    int max_deg = (a.degree > b.degree) ? a.degree : b.degree;
    result.degree = max_deg;
    for (int i = 0; i <= max_deg; i++) {
        result.coef[i] = 0.0f;
    }
    for (int e = max_deg; e >= 0; e--) {
        float ca = 0.0f, cb = 0.0f;
        if (e <= a.degree) ca = a.coef[a.degree - e];
        if (e <= b.degree) cb = b.coef[b.degree - e];
        result.coef[max_deg - e] = ca + cb;
    }
    while (result.degree > 0 && fabsf(result.coef[0]) < EPSILON) {
        for (int i = 0; i < result.degree; i++) {
            result.coef[i] = result.coef[i + 1];
        }
        result.degree--;
    }
    if (result.degree == 0 && fabsf(result.coef[0]) < EPSILON) {
        result.degree = 0;
        result.coef[0] = 0.0f;
}
return result;
}
void display(polynomial p) {
    int first = 1;
int all_zero = 1;
for (int e = p.degree; e >= 0; e--) {
        float c = p.coef[p.degree - e];
        if (fabsf(c) < EPSILON) continue;   /* skip zero terms */
        all_zero = 0;
if (!first) {
            if (c > 0) printf(" + ");
            else {
                printf(" - ");
                c = -c;
            }
        } else {
            if (c < 0) {
                printf("-");
                c = -c;
            }
        }

        if (fabsf(c - (int)c) < EPSILON)
            printf("%d", (int)c);
        else
            printf("%.2f", c);
        if (e > 1)      printf("x^%d", e);
        else if (e == 1) printf("x");
        e == 0 : 
first = 0;
}
if (all_zero) printf("0");
    printf("\n");
}
polynomial read_poly(void) {
    polynomial p;
    printf("  Enter degree: ");
    scanf("%d", &p.degree);
    printf("  Enter coefficients from highest to lowest power:\n");
    for (int i = 0; i <= p.degree; i++) {
        printf("    coef of x^%d : ", p.degree - i);
        scanf("%f", &p.coef[i]);
    }
    return p;
}
int main(void) {
    printf("=== TEST CASE 1 ===\n");
    printf("Expected: A(x) = 3x^4 + 2x^2 + 1\n");
    printf("Expected: B(x) = 5x^3 - 2x^2 + 4\n");
    printf("Expected Sum: 3x^4 + 5x^3 + 5   (x^2 term cancels)\n\n");
polynomial a, b;
a.degree = 4;
    a.coef[0] =  3; a.coef[1] = 0; a.coef[2] = 2;
    a.coef[3] =  0; a.coef[4] = 1;
b.degree = 3;
    b.coef[0] =  5; b.coef[1] = -2; b.coef[2] = 0; b.coef[3] = 4;
 printf("A(x) = "); display(a);
    printf("B(x) = "); display(b);
    printf("A(x) + B(x) = "); display(add(a, b));
printf("\n=== TEST CASE 2 (leading terms cancel) ===\n");
    printf("A(x) =  4x^3 + 2x + 1\n");
    printf("B(x) = -4x^3 + 3x^2 + 7\n");
printf("Expected Sum: 3x^2 + 2x + 8   (x^3 term cancels, degree drops)\n\n")
printf("A(x) = "); display(a);
    printf("B(x) = "); display(b);
printf("A(x) + B(x) = "); display(add(a, b));
printf("\n=== TEST CASE 3 (interactive) ===\n");
    printf("Enter Polynomial A:\n");
    a = read_poly();
    printf("Enter Polynomial B:\n");
    b = read_poly();
printf("\nA(x) = "); display(a);
    printf("B(x) = "); display(b);
printf("A(x) + B(x) = "); display(add(a, b));
  return 0;
}
