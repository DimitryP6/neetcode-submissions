class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> resultSet;
        for (int i = 0; i < nums.size() - 2; i++) {
            int remainder = 0 - nums[i];
            int leftIndex = i + 1, rightIndex = nums.size() - 1;
            while (leftIndex < rightIndex) {
                if ((nums[leftIndex] + nums[rightIndex]) == remainder) {
                    resultSet.insert({nums[i], nums[leftIndex], nums[rightIndex]});
                    leftIndex++, rightIndex--;
                } else if ((nums[leftIndex] + nums[rightIndex]) < remainder) {
                    leftIndex++;
                } else {
                    rightIndex--;
                }
            }
        }
        vector<vector<int>> resultVector(resultSet.begin(), resultSet.end());
        return resultVector;
    }
};
