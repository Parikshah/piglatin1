#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Function to convert a word to Pig Latin
string piglatin(string s) {
    string vowels = "aeiouAEIOU";
    size_t first_vowel_pos = s.find_first_of(vowels);

    // If the first letter is a vowel
    if (first_vowel_pos == 0) {
        return s + "way";
    }
    // If the word starts with a consonant or consonant cluster
    else if (first_vowel_pos != string::npos) {
        string prefix = s.substr(0, first_vowel_pos);
        string stem = s.substr(first_vowel_pos);
        return stem + prefix + "ay";
    }
    // In case there are no vowels (not common in English, but just in case)
    else {
        return s + "ay";
    }
}

int main(int argc, char **argv) {
    ifstream inStream;
    ofstream outStream;
    string s;

    if (argc < 2) {
        cout << "Please specify filename on command line\n";
        return 1;
    }

    // Try to open file to read
    inStream.open(argv[1]);

    if (inStream.fail()) {
        cout << "Failed to open file\n";
        return 1;
    }

    // Prepare to write to output file
    outStream.open("piglatin_output.txt");

    // Read input words one by one, convert to Pig Latin, and write to output
    while (inStream >> s) {
        string piglatin_word = piglatin(s);

        // Write the Pig Latin word to the output file
        outStream << piglatin_word << " ";
    }

    inStream.close();
    outStream.close();

    cout << "Pig Latin words have been written to piglatin_output.txt\n";

    return 0;
}
