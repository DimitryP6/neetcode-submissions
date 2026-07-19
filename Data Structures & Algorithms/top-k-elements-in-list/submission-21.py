class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # create freq list
        freqs = {}
        for i in range(len(nums)):
            if nums[i] in freqs:
                freqs[nums[i]] = freqs[nums[i]]+1
            else:
                freqs[nums[i]] = 1

        # put into buckets
        buckets = [[] for _ in range(len(nums) + 1)]

        for key in freqs:
            buckets[freqs[key]].append(key)

        # get highest from buckets
        ans = []
        count = k
        high = len(nums)
        while count > 0:
            for val in buckets[high]:
                ans.append(val)
                count -= 1
            high -= 1

        return ans
        