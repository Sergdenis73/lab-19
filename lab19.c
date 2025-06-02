#include <stdio.h>
#include <math.h>

void input_array(double arr[], int size, const char *name) {
    printf("Введіть %d елементів масиву %s:\n", size, name);
    for (int i = 0; i < size; i++) {
        printf("%s[%d] = ", name, i + 1);
        scanf("%lf", &arr[i]);
    }
}

void process_alpha(const double alpha[], int n, double *A, double *B, double *C, double *s_alpha) {
    *s_alpha = 0;
    *B = 1;
    *A = 0;
    *C = 0;

    for (int i = 0; i < n; i++) {
        *s_alpha += alpha[i];
    }

    for (int i = 0; i < n; i++) {
        *A += alpha[i] * tan(alpha[i]);
        *B *= alpha[i];
        *C += alpha[i] * sin(alpha[i]);
    }
    
    *A *= *s_alpha; 
}

void process_beta(const double beta[], int m, double *D, double *E, double *F, double *s_beta) {
    *s_beta = 0;
    *E = 1;
    *D = 0;
    *F = 0;

    for (int i = 0; i < m; i++) {
        *s_beta += beta[i];
    }

    for (int i = 0; i < m; i++) {
        *D += beta[i] * cos(beta[i]);
        *E *= beta[i];
        *F += beta[i] * fabs(beta[i]);
    }
}

int main() {
    system("chcp 65001");
    int n, m;
    
    printf("Введіть кількість елементів масиву α (n): ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву β (m): ");
    scanf("%d", &m);
    
    double alpha[n], beta[m];

    input_array(alpha, n, "α");
    input_array(beta, m, "β");
    
    double A, B, C, s_alpha;
    process_alpha(alpha, n, &A, &B, &C, &s_alpha);

    double D, E, F, s_beta;
    process_beta(beta, m, &D, &E, &F, &s_beta);

    double omega = (A * cos(B) + C) / (D + E * sin(F));

    printf("\nПроміжні результати:\n");
    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("C = %lf\n", C);
    printf("s_alpha = %lf\n", s_alpha);
    printf("D = %lf\n", D);
    printf("E = %lf\n", E);
    printf("F = %lf\n", F);
    printf("s_beta = %lf\n", s_beta);
    printf("\nРезультат:\nω = %lf\n", omega);
    
    return 0;
}