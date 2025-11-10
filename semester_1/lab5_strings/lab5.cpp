#include <iostream>
#include <string>
#include <cctype>
bool ContainsOnlyDigits(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
std::string RegroupWords(const std::string& str) {
    std::string digitWords;  
    std::string otherWords;  
    size_t start = 0;
    size_t end = 0;
    while (start < str.length()) {
        start = str.find_first_not_of(" ", end);
        if (start == std::string::npos) break;
        end = str.find_first_of(" ", start);
        if (end == std::string::npos) {
            end = str.length();
        }
        std::string word = str.substr(start, end - start);
        if (ContainsOnlyDigits(word)) {
            if (!digitWords.empty()) {
                digitWords.append(" "); 
            }
            digitWords.append(word);     
        }
        else {
            if (!otherWords.empty()) {
                otherWords.append(" ");  
            }
            otherWords.append(word);    
        }
    }
    std::string result;
    if (!digitWords.empty()) {
        result.append(digitWords);  
    }
    if (!otherWords.empty()) {
        if (!result.empty()) {
            result.append(" ");     
        }
        result.append(otherWords);  
    }

    return result;
}
int main() {
    try {
        std::string str;
        std::cout << "Input string: ";
        getline(std::cin, str);
        std::string result = RegroupWords(str);
        std::cout << "Sorted string: " << result << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }
    return 0;
}