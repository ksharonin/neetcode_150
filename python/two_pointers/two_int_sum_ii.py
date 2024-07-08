class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # return list of len 2, indices s.t.
        # index1 < index 2, == not permitted
        # numbers add up to target 
        # CANNOT use the same elem twice
        # always only one valid sol. at a time

        # base case: the only possible result from len2
        if len(numbers) == 2:
            return [1,2]

        # SPACE must be constant AKA not scale with numbers input


        # APPROACH: double pointer: start from end and begin
        # if sum > target, we overshot with end number -> reduce
        # if sum < target, bump up the end to incr, since end is maxed out
        # if ==, return 

        l = 0
        r = len(numbers) - 1

        while l < r:
            c_sum = numbers[l] + numbers[r]

            if c_sum > target:
                r -= 1

            elif c_sum < target:
                l +=1

            else:
                # since indices are based on one, you must increment!!!
                # e.g. [1,2,3,4] w target 3 returns [1,2]

                return [l+1, r+1]
