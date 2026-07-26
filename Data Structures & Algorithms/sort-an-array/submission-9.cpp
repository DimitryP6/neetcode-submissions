class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int heapsize;
        int n = nums.size();
        buildMaxHeap(nums, heapsize);
        for (int i = (n -  1); i > 0; i--) {
            heapsize--;
            int largest = nums[0];
            nums[0] = nums[i];
            nums[i] = largest;
            maxHeapify(nums, 0, heapsize);
        }
        return nums;
    }

private:
    int parent(int index) {
        return ((index - 1) / 2);
    }

    int leftChild(int index) {
        return (2 * index + 1);
    }

    int rightChild(int index) {
        return (2 * index + 2);
    }

    void maxHeapify(vector<int>& nums, int index, int& heapsize) {
        int right = rightChild(index);
        int left = leftChild(index);
        int largest = index;
        if ((right < heapsize) && nums[right] > nums[largest]) {
            largest = right;
        }
        if ((left < heapsize) && nums[left] > nums[largest]) {
            largest = left;
        }
        if ((largest != index) && (largest <= (heapsize - 1))) {
            int largestElement = nums[largest];
            nums[largest] = nums[index];
            nums[index] = largestElement;
            maxHeapify(nums, largest, heapsize);
        }
        return;
    }

    void buildMaxHeap(vector<int>& nums, int& heapsize) {
        heapsize = nums.size();
        for (int i = (heapsize / 2 - 1); i >= 0; i--) {
            maxHeapify(nums, i, heapsize);
        }
        return;
    }
};