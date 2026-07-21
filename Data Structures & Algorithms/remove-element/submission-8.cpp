class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int latestValidElement = nums.size();
        int i = 0; // Tracks copy index.
        while (i < latestValidElement) {
            if (nums[i] == val) {
                nums[i] = nums[--latestValidElement];
            } else {
                i++;
            }
        }
        return latestValidElement;
    }
};