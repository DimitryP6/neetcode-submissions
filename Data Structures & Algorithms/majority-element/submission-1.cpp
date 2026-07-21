class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maxBitSize = 32;
        vector<int> bitCounts(maxBitSize, 0);
        for (int num : nums) {
            for (int i = 0; i < maxBitSize; i++) {
                bitCounts[i] += (num >> i & 1);
            }
        }
        int res = 0;
        for (int i = 0; i < maxBitSize; i++) {
            if (bitCounts[i] > (n / 2)) {
                res |= (1 << i);
            }
        }
        return res;
    }
};