class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        
        for (int num : nums) {
            counts[num]++;
        }
        
        int maxcount = 0;
        for (auto& [num, freq] : counts) {
            maxcount = max(maxcount, freq);
        }
        
        vector<vector<int>> buckets(maxcount + 1);
        for (auto& [num, freq] : counts) {
            buckets[freq].push_back(num);
        }
        
        vector<int> result;
        for (int freq = maxcount; freq >= 0 && result.size() < k; freq--) {
            for (int num : buckets[freq]) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};