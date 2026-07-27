class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCounts;
        for (const int& num : nums) {
            numCounts[num]++;
        }
        vector<vector<int>> freqToNum(nums.size() + 1);
        for (const pair<int, int>& numToCount : numCounts) {
            freqToNum[numToCount.second].push_back(numToCount.first);
        }
        vector<int> result;
        for (int i = (freqToNum.size() - 1), addedCount = 0; i > 0; i--) {
            for (const int& highFreqNum : freqToNum[i]) {
                result.push_back(highFreqNum);
                addedCount++;
                if (addedCount == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
