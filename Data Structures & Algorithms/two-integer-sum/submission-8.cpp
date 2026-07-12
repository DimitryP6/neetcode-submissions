class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap;
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            if (prevMap.contains(difference)) {
                return {prevMap[difference], i};
            } else {
                prevMap.insert({nums[i], i});
            }
        }
        return {0, 0};
    }
};
