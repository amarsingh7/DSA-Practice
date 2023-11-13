class Solution {
public:
    
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

 string sortVowels(string s) {
    std::vector<char> consonants;
    std::vector<char> vowels;

    for (int i = 0; i < s.length(); i++) {
        if (isVowel(s[i])) {
            vowels.push_back(s[i]);
        } else {
            consonants.push_back(s[i]);
        }
    }

    std::sort(vowels.begin(), vowels.end());

    std::string t(s.length(), ' ');

    int vowelIndex = 0;
    int consonantIndex = 0;

    for (int i = 0; i < s.length(); i++) {
        if (isVowel(s[i])) {
            t[i] = vowels[vowelIndex++];
        } else {
            t[i] = consonants[consonantIndex++];
        }
    }

    return t;
}
   
};