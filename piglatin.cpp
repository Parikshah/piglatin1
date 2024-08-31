#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Function to convert a word to Pig Latin
string piglatin(const string& s) {
    string word = s;
    // Convert to lowercase for consistency
    for (char& c : word) {
        c = tolower(c);
    }

    // Check if the word starts with a vowel
    if (word.empty()) return word; // Handle empty string

    char firstChar = word[0];
    if (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u') {
        return word + "way";
    }

    // Handle consonants
    size_t firstVowelPos = 0;
    while (firstVowelPos < word.size() && (word[firstVowelPos] != 'a' && word[firstVowelPos] != 'e' &&
                                           word[firstVowelPos] != 'i' && word[firstVowelPos] != 'o' &&
                                           word[firstVowelPos] != 'u')) {
        ++firstVowelPos;
    }

    if (firstVowelPos == word.size()) {
        // No vowels found, treat entire word as consonant cluster
        return word + "ay";
    }

    return word.substr(firstVowelPos) + word.substr(0, firstVowelPos) + "ay";
}

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Please specify filename on command line\n";
        exit(1);
    }

    ifstream inStream(argv[1]);
    if (!inStream) {
        cout << "Failed to open file\n";
        exit(1);
    }

    ofstream outStream("piglatin_output.txt");
    if (!outStream) {
        cout << "Failed to open output file\n";
        exit(1);
    }

    string word;
    bool firstWord = true;

    while (inStream >> word) {
        if (!firstWord) {
            outStream << '\n'; // Add newline between words
        }
        firstWord = false;
        outStream << piglatin(word);
    }

    inStream.close();
    outStream.close();

    cout << "Pig Latin words have been written to piglatin_output.txt\n";

    return 0;
}
