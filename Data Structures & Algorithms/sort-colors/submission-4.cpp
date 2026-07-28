class Solution {
public:
    void sortColors(vector<int>& nums) {
        int leftIndex = -1;
        int rightIndex = nums.size();
        int curNumIndex = 0;
        while (curNumIndex < rightIndex) {
            if (nums[curNumIndex] == 0) {
                leftIndex++;
                swap(nums, leftIndex, curNumIndex);
                curNumIndex++;
            } else if (nums[curNumIndex] == 2) {
                rightIndex--;
                swap(nums, curNumIndex, rightIndex);
            } else {
                curNumIndex++;
            }
        }
        return;
    }

    void swap(vector<int>& nums, int leftIndex, int rightIndex) {
        int leftNum = nums[leftIndex];
        nums[leftIndex] = nums[rightIndex];
        nums[rightIndex] = leftNum;
        return;
    }
};