class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        // HashMap between frequencies of characters (size 26 arrays) as a key,
        // and the current group.
        unordered_map<string, vector<string>> groupAnagramHash;
        for (const string& curString : strs) {
            int alphabetSize = 26;
            vector<int> curStringCounts(alphabetSize, 0);
            for (const char& strChar : curString) {
                curStringCounts[strChar - 'a']++;
            }
            string curCountKey = "";
            for (int i = 0; i < alphabetSize; i++) {
                curCountKey += "," +  to_string(curStringCounts[i]);
            }
            groupAnagramHash[curCountKey].push_back(curString);
        }
        for (const pair<string, vector<string>>& keyGroupPair : groupAnagramHash) {
            output.push_back(keyGroupPair.second);
        }
        return output;
    }
};
