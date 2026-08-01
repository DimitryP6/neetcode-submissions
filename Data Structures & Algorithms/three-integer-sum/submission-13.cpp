class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int remainder = 0 - nums[i];
            int leftIndex = i + 1, rightIndex = nums.size() - 1;
            while (leftIndex < rightIndex) {
                if ((nums[leftIndex] + nums[rightIndex]) == remainder) {
                    result.push_back({nums[i], nums[leftIndex], nums[rightIndex]});
                    leftIndex++, rightIndex--;
                    while (nums[leftIndex] == nums[leftIndex - 1] && leftIndex < rightIndex) {
                        leftIndex++;
                    }
                    while (nums[rightIndex] == nums[rightIndex + 1] && rightIndex > leftIndex) {
                        rightIndex--;
                    }
                } else if ((nums[leftIndex] + nums[rightIndex]) < remainder) {
                    leftIndex++;
                } else {
                    rightIndex--;
                }
            }
        }
        return result;
    }
};
