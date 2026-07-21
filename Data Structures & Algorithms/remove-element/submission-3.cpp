class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return (nums.size() - erase(nums, val));
    }
};