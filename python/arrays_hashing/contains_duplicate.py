class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # unique only
        sub_set = set(nums)
        # if set len is smaller than nums
        # then nums must have dups
        has_dups = len(sub_set) < len(nums)

        return has_dups
         
