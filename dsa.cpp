#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> addMatrix(vector<vector<int>> A,
                              vector<vector<int>> B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

vector<vector<int>> subtractMatrix(vector<vector<int>> A,
                                   vector<vector<int>> B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

vector<vector<int>> strassen(vector<vector<int>> A,
                             vector<vector<int>> B)
{
    int n = A.size();

    if (n == 1)
    {
        return {{A[0][0] * B[0][0]}};
    }

    int mid = n / 2;

    vector<vector<int>> A11(mid, vector<int>(mid));
    vector<vector<int>> A12(mid, vector<int>(mid));
    vector<vector<int>> A21(mid, vector<int>(mid));
    vector<vector<int>> A22(mid, vector<int>(mid));

    vector<vector<int>> B11(mid, vector<int>(mid));
    vector<vector<int>> B12(mid, vector<int>(mid));
    vector<vector<int>> B21(mid, vector<int>(mid));
    vector<vector<int>> B22(mid, vector<int>(mid));

    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    vector<vector<int>> M1 = strassen(
        addMatrix(A11, A22),
        addMatrix(B11, B22)
    );

    vector<vector<int>> M2 = strassen(
        addMatrix(A21, A22),
        B11
    );

    vector<vector<int>> M3 = strassen(
        A11,
        subtractMatrix(B12, B22)
    );

    vector<vector<int>> M4 = strassen(
        A22,
        subtractMatrix(B21, B11)
    );

    vector<vector<int>> M5 = strassen(
        addMatrix(A11, A12),
        B22
    );

    vector<vector<int>> M6 = strassen(
        subtractMatrix(A21, A11),
        addMatrix(B11, B12)
    );

    vector<vector<int>> M7 = strassen(
        subtractMatrix(A12, A22),
        addMatrix(B21, B22)
    );

    vector<vector<int>> C11 = addMatrix(
        subtractMatrix(addMatrix(M1, M4), M5),
        M7
    );

    vector<vector<int>> C12 = addMatrix(M3, M5);

    vector<vector<int>> C21 = addMatrix(M2, M4);

    vector<vector<int>> C22 = addMatrix(
        subtractMatrix(addMatrix(M1, M3), M2),
        M6
    );

    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
}

vector<vector<int>> normalMultiply(vector<vector<int>> A,
                                   vector<vector<int>> B)
{
    int n = A.size();

    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

void display(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool sameMatrix(vector<vector<int>> A, vector<vector<int>> B)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            if (A[i][j] != B[i][j])
                return false;
        }
    }

    return true;
}

int main()
{
    // Test Case 1: 2x2
    vector<vector<int>> A = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> B = {
        {5, 6},
        {7, 8}
    };

    cout << "2x2 Matrix - Strassen Result:" << endl;
    vector<vector<int>> result = strassen(A, B);
    display(result);

    cout << "\nCompare with normal multiplication: ";

    vector<vector<int>> normal = normalMultiply(A, B);

    if (sameMatrix(result, normal))
        cout << "Same" << endl;
    else
        cout << "Different" << endl;


    // Test Case 2: 4x4
    vector<vector<int>> C = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<vector<int>> D = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    cout << "\n4x4 Matrix - Strassen Result:" << endl;

    vector<vector<int>> result4 = strassen(C, D);
    display(result4);

    cout << "\nCompare with normal multiplication: ";

    vector<vector<int>> normal4 = normalMultiply(C, D);

    if (sameMatrix(result4, normal4))
        cout << "Same" << endl;
    else
        cout << "Different" << endl;

    return 0;
}