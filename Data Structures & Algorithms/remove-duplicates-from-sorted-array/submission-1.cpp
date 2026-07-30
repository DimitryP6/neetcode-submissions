class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastAddedIndex = 0;
        for (int curIndex = 0; curIndex < nums.size(); curIndex++) {
            if (nums[curIndex] == nums[lastAddedIndex]) {
                continue;
            } else {
                lastAddedIndex++;
                nums[lastAddedIndex] = nums[curIndex];
            }
        }
        return (lastAddedIndex + 1);
    }
};