class Solution {
public:
    void reverseString(vector<char>& s) {
        int leftCharIndex = 0;
        int rightCharIndex = s.size() - 1;
        while (leftCharIndex < rightCharIndex) {
            swap(s, leftCharIndex, rightCharIndex);
            leftCharIndex++;
            rightCharIndex--;
        }
    }

    void swap(vector<char>& s, int leftIndex, int rightIndex) {
        char leftChar = s[leftIndex];
        s[leftIndex] = s[rightIndex];
        s[rightIndex] = leftChar;
    }
};