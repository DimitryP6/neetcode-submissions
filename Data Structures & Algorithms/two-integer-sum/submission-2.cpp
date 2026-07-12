class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashNums;
        for (int i = 0; i < nums.size(); i++) {
            hashNums[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            if (hashNums.contains(difference) && hashNums[difference] != i) {
                return {i, hashNums[difference]};
            }
        }
    }
};
