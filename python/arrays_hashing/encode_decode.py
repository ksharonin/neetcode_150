class Solution:

    def encode(self, strs: List[str]) -> str:
        # NOTE the encoding is not specific to ascii/bin
        # need to be able to diff between words

        # NOTE may see # sign in the word!!!!

        # NOTE strs[i] contains only UTF-8 characters.
        # but couldnt a num still appear?
        # SOVLED: pattern still helps skip over

        # e.g. "hello" "world"
        # "5#hello5#world"
        
        # per split, no separator; before conjoining, apply len + # + string
        return ''.join(f'{len(string)}#{string}'for string in strs
    )
 

    def decode(self, s: str) -> List[str]:
        # sift through chars 
        final = []

        # NOTE: cannot use for loop due to changing i val
        i = 0
        while i < len(s):
            # search for the len before # encoder
            check_digit = i
            while s[check_digit] != '#':
                check_digit += 1
            # slice for len
            len_dig = int(s[i:check_digit])
            # advanced past encoder
            i = check_digit + 1 # skips #
            check_digit = i + len_dig # skips to where next digit starts
            # slice out str value
            final.append(s[i:check_digit])
            # bump index
            i = check_digit

        return final
