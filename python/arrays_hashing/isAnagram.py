class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # (1) same len
        # (2) same count of each char

        if len(s) != len(t):
            return False
        else:
            # must be same len, count occurence of each char
            # pick each char, and assert same num occur
            for i in range(len(s)):
                # extract char
                curr_char = s[i]
                # count in each
                if s.count(curr_char) != t.count(curr_char):
                    return False
        
            return True
