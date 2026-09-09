#include <iostream> 

#include <string> 

using namespace std; 

int analyzePattern(string input, string pattern) 

{ 

    if (pattern.length() == 0) 

        return 0; 

 

    if (pattern.length() > input.length()) 

        return -1; 

 

    for (int i = 0; i <= input.length() - pattern.length(); i++) 

    { 

        int j = 0; 

 

        while (j < pattern.length() && input[i + j] == pattern[j]) 

        { 

            j++; 

        } 

        if (j == pattern.length()) 

            return i; 

    } 

    return -1; 

} 

int main() 

{ 

    cout << "Case 1 "; 

    cout << analyzePattern("My Class", "My") << endl; 

 

    cout << "Case 2 "; 

    cout << analyzePattern("Car wheel", "Wheel") << endl; 

 

    cout << "Case 3"; 

    cout << analyzePattern("Room window", "chair") << endl; 

 

    cout << "Case 4 "; 

    cout << analyzePattern("My bag", "") << endl; 

 

    return 0; 

} 