class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int countRemaining = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[countRemaining++] = nums[i];
            }
        }
        return countRemaining;
    }
};