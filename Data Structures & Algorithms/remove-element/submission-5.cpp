class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nextValidInsertPos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[nextValidInsertPos++] = nums[i];
            }
        }
        return nextValidInsertPos;
    }
};