class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
       
        # NOTES - original solution does not meet O(N) requirements
        # approach
        # unique set generation 

        # longest len tracker 

        # if n-1 not in the unique set
        # len = 1
        # while n+len in numset , len + 1
        # longest = max ( len , longest )
        # longest set back

        # MAKE
        unq = set(nums)
        best = 0

        for n in nums:
            # if there is no prev smaller -> seq covered
	    # reasoning: if there is a previous, the len would already be accounted for
            if (n-1) not in unq:
                lent = 1
                # continue counter
                while (n+lent) in unq:
                    lent += 1
                best = max(lent, best)

        return best
