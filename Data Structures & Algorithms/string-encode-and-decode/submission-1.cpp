class Solution {
public:

    string encode(vector<string>& strs) {
        string encoding;
        for (const string& oneString : strs) {
            encoding += (to_string(oneString.size()));
            encoding += "#";
            encoding += oneString;
        }
        return encoding;
    }

    vector<string> decode(string s) {
        vector<string> decoding;
        int i = 0;
        while (i < s.size()) {
            int curStringPos = i;
            while (s[curStringPos] != '#') {
                curStringPos++;
            }
            int length = stoi(s.substr(i, curStringPos));
            i = curStringPos + 1;
            curStringPos = i + length;
            decoding.push_back(s.substr(i, length));
            i = curStringPos;
        }
        return decoding;
    }
};
