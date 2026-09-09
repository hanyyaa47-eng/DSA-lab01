#include <iostream> 

#include <vector> 

using namespace std; 

 

vector<vector<int>> genTriangle(int n) 

{ 

    vector<vector<int>> triangle; 

 

    for (int i = 0; i < n; i++) 

    { 

        vector<int> row(i + 1, 1); 

 

        for (int j = 1; j < i; j++) 

        { 

            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; 

        } 

 

        triangle.push_back(row); 

    } 

 

    return triangle; 

} 

 

void show(vector<vector<int>> triangle) 

{ 

    for (int i = 0; i< triangle.size(); i++) 

    { 

        for (int j = 0; j< triangle[i].size(); j++) 

        { 

            cout << triangle[i][j] << " "; 

        } 

        cout << endl; 

    } 

} 

 

int main() 

{ 

    cout << "n = 0" << endl; 

    show(genTriangle(0)); 

 

    cout << "n = 1" << endl; 

    show(genTriangle(1)); 

 

    cout << "n = 5" << endl; 

    vector<vector<int>> result = genTriangle(5); 

    show(result); 

 

    cout << "Row 5: "; 

    for (int x : result[4]) 

    { 

        cout << x << " "; 

    } 

    return 0; 

} 