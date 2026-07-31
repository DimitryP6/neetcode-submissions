class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int leftIndex = m - 1, rightIndex = n - 1, curInsertIndex = m + n - 1;
        while ((leftIndex >= 0) && (rightIndex >= 0)) {
            if (nums1[leftIndex] > (nums2[rightIndex])) {
                nums1[curInsertIndex] = nums1[leftIndex];
                leftIndex--;
            } else {
                nums1[curInsertIndex] = nums2[rightIndex];
                rightIndex--;
            }
            curInsertIndex--;
        }
        while (leftIndex >= 0) {
            nums1[curInsertIndex] = nums1[leftIndex];
            leftIndex--, curInsertIndex--;
        }
        while (rightIndex >= 0) {
            nums1[curInsertIndex] = nums2[rightIndex];
            rightIndex--, curInsertIndex--;
        }
        return;
    }
};