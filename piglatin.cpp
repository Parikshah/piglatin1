// Pari K. Shah

#include <iostream>
#include <string>
#include <cctype>

std::string piglatin(const std::string& s) {
    if (s.empty()) return "";

    std::string vowels = "aeiouAEIOU";
    std::string lower_word = s;
    for (char &c : lower_word) c = std::tolower(c);

    std::string result;
    if (vowels.find(lower_word[0]) != std::string::npos) {
        result = lower_word + "way";
    } else {
        size_t first_vowel_pos = lower_word.find_first_of(vowels);
        if (first_vowel_pos != std::string::npos) {
            result = lower_word.substr(first_vowel_pos) + lower_word.substr(0, first_vowel_pos) + "ay";
        } else {
            result = lower_word + "ay";
        }
    }

    // Capitalize the first letter of the result if the input was capitalized
    if (std::isupper(s[0])) {
        result[0] = std::toupper(result[0]);
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
