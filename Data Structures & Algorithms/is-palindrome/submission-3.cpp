class Solution {
public:
    bool isPalindrome(string s) {
        string cleanString;
        for (const char& c : s) {
            if (isalnum(c) && (c != ' ')) {
                cleanString += tolower(c);
            }
        }
        int leftCharIndex = 0;
        int rightCharIndex = cleanString.size() - 1;
        while (leftCharIndex < rightCharIndex) {
            if (cleanString[leftCharIndex] != cleanString[rightCharIndex]) {
                return false;
            }
            leftCharIndex++;
            rightCharIndex--;
        }
        return true;
    }
};
