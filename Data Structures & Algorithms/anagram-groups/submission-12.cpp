class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        for (int i = 0; i < strs.size(); i++) {
            const string& curString = strs[i];
            unordered_map<char, int> curStringCounts;
            for (char curChar : curString) {
                curStringCounts[curChar]++;
            }
            vector<string> curAnagramGroup = {curString};
            for (int j = 0; j < strs.size(); j++) {
                if (i == j) {
                    continue;
                }
                const string& checkString = strs[j];
                unordered_map<char, int> checkStringCounts;
                for (char curChar : checkString) {
                    checkStringCounts[curChar]++;
                }
                if (curStringCounts == checkStringCounts) {
                    curAnagramGroup.push_back(checkString);
                }
            }
            bool doesntExist = true;
            for (const vector<string>& someGroup : output) {
                if (set(someGroup.begin(), someGroup.end()) 
                == set(curAnagramGroup.begin(), curAnagramGroup.end())) {
                    doesntExist = false;
                }
            }
            if (doesntExist) {
                output.push_back(curAnagramGroup);
            }
        }
        return output;
    }
};
