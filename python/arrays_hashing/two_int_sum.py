class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        assert len(nums) >= 2, "critical failure"
        
        # every pair must have one pair
        if len(nums) == 2:
            return [0, 1]
        
        # outer loop sum
        for i_t in range(len(nums)):
            i = nums[i_t]
            # inner loop 
            for j_t in range(len(nums)):
                j = nums[j_t]
                if i+j == target and i_t != j_t:
                    return [i_t, j_t]

        return []

