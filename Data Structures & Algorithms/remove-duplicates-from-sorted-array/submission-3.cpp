class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastAddedIndex = 1;
        for (int curIndex = 1; curIndex < nums.size(); curIndex++) {
            if (nums[curIndex] != nums[curIndex - 1]) {
                nums[lastAddedIndex++] = nums[curIndex];
            }
        }
        return lastAddedIndex;
    }
};