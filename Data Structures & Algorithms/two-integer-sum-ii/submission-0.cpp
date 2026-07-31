class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftIndex = 0, rightIndex = (numbers.size() - 1);
        while ((numbers[leftIndex] + numbers[rightIndex]) != target) {
            if (numbers[leftIndex] + numbers[rightIndex] > target) {
                rightIndex--;
            } else {
                leftIndex++;
            }
        }
        return {leftIndex + 1, rightIndex + 1};
    }
};
