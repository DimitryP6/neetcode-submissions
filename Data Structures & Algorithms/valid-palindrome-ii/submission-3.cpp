class Solution {
public:
    bool validPalindrome(string s) {
        int leftCharIndex = 0, rightCharIndex = s.size() - 1;
        while (leftCharIndex < rightCharIndex) {
            if (s[leftCharIndex] == s[rightCharIndex]) {
                leftCharIndex++; rightCharIndex--;
            } else {
                return (isPalindrome(s, leftCharIndex + 1, rightCharIndex)
                || isPalindrome(s, leftCharIndex, rightCharIndex - 1));
            }
        }
        return true;
    }
    bool isPalindrome(string s, int leftCharIndex, int rightCharIndex) {
        while (leftCharIndex < rightCharIndex) {
            if (s[leftCharIndex] == s[rightCharIndex]) {
                leftCharIndex++;
                rightCharIndex--;
            } else {
                return false;
            }
        }
        return true;
    }
};