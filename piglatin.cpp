// Pari K. Shah 

#include <iostream>
#include <string>
#include <cctype>

// Function to convert a word to Pig Latin
std::string piglatin(const std::string& s) {
    std::string vowels = "aeiouAEIOU";
    std::string word = s;
    std::string result;

    if (word.empty()) return result;

    // Convert to lowercase for processing
    std::string lower_word = word;
    for (char &c : lower_word) c = std::tolower(c);

    // Check if the first letter is a vowel
    if (vowels.find(lower_word[0]) != std::string::npos) {
        result = lower_word + "way";
    } else {
        // Find the first vowel in the word
        size_t first_vowel_pos = lower_word.find_first_of(vowels);
        if (first_vowel_pos != std::string::npos) {
            result = lower_word.substr(first_vowel_pos) + lower_word.substr(0, first_vowel_pos) + "ay";
        } else {
            result = lower_word + "ay";
        }
    }

    // Convert result back to original case
    for (size_t i = 0; i < result.size(); ++i) {
        if (i == 0 || lower_word[i] != lower_word[i-1]) {
            result[i] = std::toupper(result[i]);
        }
    }

    return result;
}

int main() {
    std::string word;
    while (std::cin >> word) {
        std::cout << piglatin(word) << std::endl;
    }
    return 0;
}
