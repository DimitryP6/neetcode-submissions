class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        // HashMap between frequencies of characters (size 26 arrays) as a key,
        // and the current group.
        unordered_map<string, vector<string>> groupAnagramHash;
        int nextOutputIndex = 0;
        for (const string& curString : strs) {
            vector<int> curStringCounts(26, 0);
            for (const char& strChar : curString) {
                curStringCounts[strChar - 'a']++;
            }
            string curCountKey = "";
            for (int i = 0; i < curStringCounts.size(); i++) {
                curCountKey = curCountKey + "," + to_string(i) + "," +  to_string(curStringCounts[i]);
            }
            // If hashmap already doesn't contain such a char frequency,
            // set the hashMap value with the current char freq. and next index.
            if (!groupAnagramHash.contains(curCountKey)) {
                vector<string> nextGroupVector;
                nextGroupVector.push_back(curString);
                groupAnagramHash[curCountKey] = nextGroupVector;
            } else {
                groupAnagramHash[curCountKey].push_back(curString);
            }
        }
        for (const pair<string, vector<string>>& keyGroupPair : groupAnagramHash) {
            output.push_back(keyGroupPair.second);
        }
        return output;
    }
};
