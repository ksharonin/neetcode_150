class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        # NOTE: official solution makes smart use of ascii values
	# to make a default dict of {List of ints : [word, word...]}
	# the list of ints is indexed with ascii, and each val
	# at the index indicates count of char

	# BEGIN SOL
	# return nested list 
        # make sublists, where each sublist are strings that share unique chars

        # approach
        # generate sets per word -> check if existing sets work
        # map each set to an index via dictionary 
        # MUST ALSO TRACK CHAR COUNT!

        # base case
        if len(strs) == 1:
            return [strs]

        # dict with existing sets
        set_to_index = {}
        # master index incr
        i = 0
        # result
        result = []

        # main body
        for word in strs:
            # generate unique set 
            unique = frozenset(word)
            # map char to count
            ccount = {}
            for u in list(set(word)):
                ccount[u] = word.count(u)

            if unique not in set_to_index:
                # save the index and char count info
                set_to_index[unique] = [i, ccount]
                i += 1
                # begin list inside
                result.append([word])

            else:
                # fetch other dict and compare, otherwise make new one
                if set_to_index[unique][1] == ccount:
                    # exists, append to existing list
                    result[set_to_index[unique][0]].append(word)
                else:
                    # save the index and char count info
                    set_to_index[unique] = [i, ccount]
                    i += 1
                    # begin list inside
                    result.append([word])

        return result
