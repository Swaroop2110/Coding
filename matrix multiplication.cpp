#include<bits/stdc++.h>
using namespace std;

int main(){
    int m ,n , p;
    cout << "Enter the number of rows for matrix A: ";
    cin >> m;
    cout << "Enter the number of columns for matrix A and rows for matrix B: ";
    cin >> n;
    cout << "Enter the number of columns for matrix B: ";
    cin >> p;
    int** A = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++){
        A[i] = (int*)malloc(n * sizeof(int));
    }
    int** B = (int**)malloc(m * sizeof(int*));
    for(int i = 0 ; i < n; i++){
        // input
        B[i] = (int*)malloc(p * sizeof(int));
    }
    int** C =  (int**)malloc(m * sizeof(int*));
    for(int i = 0;  i < m; i++){
        C[i] = (int*)malloc(p * sizeof(int));
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0;
        }
    }
    cout << "ENTER ELEMENTS OF A : " << endl;
    for(int i = 0 ; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
    cout << "ENTER ELEMENTS OF B : " << endl;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < p; j++){
            cin >> B[i][j];
        }
    }
    for(int i = 0;  i < m ; i++){
        for(int j = 0; j < p; j++){
            for(int k = 0;  k < n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "RESULTANT MATRIX C : "<< endl;
    for(int i = 0 ; i < m; i++){
        for(int  j = 0; j < p; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;


}
