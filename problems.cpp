#include<bits/stdc++.h>
using namespace std;
int main() {
    int **a, **b, **c;
    int a_r, a_c, b_r, b_c;

    // Input dimensions and elements for matrix A
    cout <<("Enter rows and columns for matrix A: ");
    cin >>a_r >> a_c;

    // Allocate memory for matrix A
    a = (int **)malloc(a_r * sizeof(int *));
    for (int i = 0; i < a_r; i++) {
        a[i] = (int *)malloc(a_c * sizeof(int));
    }

    cout <<("Enter elements of matrix A:\n");
    for (int i = 0; i < a_r; i++) {
        for (int j = 0; j < a_c; j++) {
            cin >>(a[i][j]);
        }
    }

    // Input dimensions and elements for matrix B
    cout <<("Enter rows and columns for matrix B: ");
    cin >>b_r >> b_c;

    if (a_c != b_r) {
        cout <<("Matrix multiplication is not possible.\n");
        // Free allocated memory
        for (int i = 0; i < a_r; i++) {
            free(a[i]);
        }
        free(a);
        return 1;
    }

    // Allocate memory for matrix B
    b = (int **)malloc(b_r * sizeof(int *));
    for (int i = 0; i < b_r; i++) {
        b[i] = (int *)malloc(b_c * sizeof(int));
    }

    cout <<("Enter elements of matrix B:\n");
    for (int i = 0; i < b_r; i++) {
        for (int j = 0; j < b_c; j++) {
            cin >>b[i][j];
        }
    }

    // Allocate memory for the result matrix C
    c = (int **)malloc(a_r * sizeof(int *));
    for (int i = 0; i < a_r; i++) {
        c[i] = (int *)malloc(b_c * sizeof(int));
    }

    // Initialize the result matrix C to zero
    for (int i = 0; i < a_r; i++) {
        for (int j = 0; j < b_c; j++) {
            c[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < a_r; i++) {
        for (int j = 0; j < b_c; j++) {
            for (int k = 0; k < a_c; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Display the result matrix C
    cout <<("\nProduct of matrix A and B is:\n");
    for (int i = 0; i < a_r; i++) {
        for (int j = 0; j < b_c; j++) {
            cout <<("\t", c[i][j]);
        }
        cout <<("\n");
    }

    // Free allocated memory
    for (int i = 0; i < a_r; i++) {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < b_r; i++) {
        free(b[i]);
    }
    free(b);

    for (int i = 0; i < a_r; i++) {
        free(c[i]);
    }
    free(c);

    return 0;
}
