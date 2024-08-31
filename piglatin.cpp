#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Function to convert a word to Pig Latin
string piglatin(string s) {
    // Convert to lowercase for uniform processing
    for (char &c : s) {
        c = tolower(c);
    }

    // Check if the first letter is a vowel
    if (s.empty()) return s; // Handle empty string

    char firstChar = s[0];
    string result;

    if (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u') {
        result = s + "way";
    } else {
        // Find the first vowel
        size_t pos = s.find_first_of("aeiou");
        if (pos != string::npos) {
            result = s.substr(pos) + s.substr(0, pos) + "ay";
        } else {
            // If no vowel is found, just add "ay" (though this case is rare)
            result = s + "ay";
        }
    }

    return result;
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("piglatin_output.txt");
    string word;

    if (!inFile.is_open()) {
        cerr << "Error opening input file" << endl;
        return 1;
    }

    if (!outFile.is_open()) {
        cerr << "Error opening output file" << endl;
        return 1;
    }

    outFile << "Pig Latin words have been written to piglatin_output.txt\n";

    while (inFile >> word) {
        outFile << piglatin(word) << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
