class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
};

class Trie {
    public: 
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
    
    void insert(const string& word) {
        TrieNode* curNode = this->root;
        for (char c : word) {
            if (curNode->children.find(c) == curNode->children.end()) {
                curNode->children[c] = new TrieNode();
            }
            curNode = curNode->children[c];
        }
    }

    int longestCommonPrefixLength(const string& word, int maxPrefixLen) {
        TrieNode* curNode = this->root;
        int i = 0;
        while(i < min(((int) word.length()), maxPrefixLen)) {
            if (curNode->children.find(word[i]) == curNode->children.end()) {
                return i;
            } else {
                curNode = curNode->children[word[i]];
                i++;
            }
        }
        return min(((int) word.length()), maxPrefixLen);
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        int maxLengthStringIndex = 0;
        for (int i = 1; i < strs.size(); i++) {
            if (strs[maxLengthStringIndex].length() < strs[i].length()) {
                maxLengthStringIndex = i;
            }
        }

        Trie trie;
        trie.insert(strs[maxLengthStringIndex]);
        int prefixLen = strs[maxLengthStringIndex].length();
        for (int i = 0; i < strs.size(); i++) {
            prefixLen = trie.longestCommonPrefixLength(strs[i], prefixLen);
        }

        return strs[0].substr(0, prefixLen);
    }
};