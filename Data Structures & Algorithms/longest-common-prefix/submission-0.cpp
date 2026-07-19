#include <algorithm>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestCommonPrefix = "";
        int shortestStringLength = 201;
        for (string oneString : strs) {
            if (oneString.size() < shortestStringLength) {
                shortestStringLength = oneString.size();
            }
        }
        bool commonPrefix = true;
        for (int i = 0; i < shortestStringLength; i++) {
            char nextCharacterToCheck = strs[0][i];
            bool allContainCharacter = true;
            for (string oneString : strs) {
                if (oneString[i] != nextCharacterToCheck) {
                    allContainCharacter = false;
                    commonPrefix = false;
                }
            }
            if (allContainCharacter == true && commonPrefix == true) {
                longestCommonPrefix += nextCharacterToCheck;
            }
        }
        return longestCommonPrefix;
    }
};