class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # k most frequent elements
        # order is first encountered aka first seen 

        # idea: dict { int : count }
        # when done, need top k 

        # if not an entry, default to int 0
        counter = defaultdict(int)

        for i in nums:
            # increment seen value
            counter[i] += 1

        k_list = []

        # PROBLEM: keys may be sharing values, not reliable to map back
        # sort = (counter.values()).sort(reverse=True)

        # NEW: apply lambda on items
        # explanation: 
        # sorted uses key= as a function to apply on all items
        # it fetches the value and then sorts on the value alone (NOT key AND value)
        # reverse to have highest count first 
        sorted_items = sorted(counter.items(), key=lambda item: item[1], reverse=True)

        # now return up to k top contenders 
        for i in range(k):
            k_list.append(sorted_items[i][0])

        return k_list
