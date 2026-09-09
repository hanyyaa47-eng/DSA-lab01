#include <vector> 

using namespace std; 

 

vector<int> findModes(int arr[], int size) 

{ 

    vector<int> modes; 

 

    if (size == 0) 

        return modes; 

 

    int maxCount = 0; 

 

    for (int i = 0; i < size; i++) 

    { 

        int count = 0; 

 

        for (int j = 0; j < size; j++) 

        { 

            if (arr[i] == arr[j]) 

                count++; 

        } 

 

        if (count > maxCount) 

            maxCount = count; 

    } 

 

    for (int i = 0; i < size; i++) 

    { 

        int count = 0; 

 

        for (int j = 0; j < size; j++) 

        { 

            if (arr[i] == arr[j]) 

                count++; 

        } 

 

        bool alreadyAdded = false; 

 

        for (int j = 0; j < modes.size(); j++) 

        { 

            if (modes[j] == arr[i]) 

            { 

                alreadyAdded = true; 

                break; 

            } 

        } 

 

        if (count == maxCount && !alreadyAdded) 

            modes.push_back(arr[i]); 

    } 

 

    return modes; 

} 

 

void displayModes(vector<int> modes) 

{ 

    if (modes.empty()) 

    { 

        cout << "Array is empty." << endl; 

        return; 

    } 

 

    cout << "Mode(s): "; 

 

    for (int i = 0; i < modes.size(); i++) 

    { 

        cout << modes[i] << " "; 

    } 

 

    cout << endl; 

} 

 

int main() 

{ 

    // Test Case 1: Unique mode 

    int arr1[] = {2, 4, 4, 5, 7, 4, 8}; 

 

    cout << "Test Case 1: Unique mode" << endl; 

    displayModes(findModes(arr1, 7)); 

 

 

    // Test Case 2: Multiple modes 

    int arr2[] = {1, 2, 2, 3, 3, 4}; 

 

    cout << "\nTest Case 2: Multiple modes" << endl; 

    displayModes(findModes(arr2, 6)); 

 

 

    // Test Case 3: Empty array 

    int arr3[] = {}; 

 

    cout << "\nTest Case 3: Empty array" << endl; 

    displayModes(findModes(arr3, 0)); 

 

    return 0; 

} 