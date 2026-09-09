#include <iostream> 

#include <vector> 

using namespace std; 

 

vector<int> getIndices(int arr[], int size, int key) 

{ 

    vector<int> indices; 

 

    for (int i = 0; i < size; i++) 

    { 

        if (arr[i] == key) 

        { 

            indices.push_back(i); 

        } 

    } 

    return indices; 

} 

void show(vector<int> indices) 

{ 

    if (indices.empty()) 

    { 

        cout << "Index not found ." << endl; 

        return; 

    } 

    cout << "Indices are  "; 

    for (int i = 0; i < indices.size(); i++) 

    { 

        cout << indices[i] << " "; 

    } 

    cout << endl; 

} 

int main() 

{ 

//case 1 : 

    int arr1[] = {2, 5, 7, 7, 9, 7, 3}; 

    int firstkey = 7; 

    cout << "Case Multiple occurrences" << endl; 

    vector<int> firstresult = getIndices(arr1, 7, firstkey); 

    show(firstresult); 

//Case 2 : 

    int arr2[] = {21, 3, 46, 78, 10}; 

    int secondkey = 90; 

    cout << " Case Key not present" << endl; 

    vector<int> secondresult = getIndices(arr2, 90, secondkey); 

    show(secondresult); 

//Case 3 :  

    int arr3[] = {}; 

    int thirdkey = 4; 

    cout << "Case Empty array" << endl; 

    vector<int> thirdresult = getIndices(arr3, 0, thirdkey); 

    show(thirdresult); 

 

    return 0; 

}