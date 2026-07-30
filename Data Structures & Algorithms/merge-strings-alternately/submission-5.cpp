class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int stringIndex = 0;
        for (stringIndex = 0; (stringIndex < word1.size()) && (stringIndex < word2.size()); stringIndex++) {
            result += word1[stringIndex];
            result += word2[stringIndex];
        }
        if (stringIndex < word1.size()) {
            result.append(word1.substr(stringIndex, word1.size() - stringIndex));
        } else {
            result.append(word2.substr(stringIndex, word2.size() - stringIndex));
        }
        return result;
    }
};