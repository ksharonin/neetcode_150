class Solution {
public:
    bool isPalindrome(string s) {
        // NOTES
        // case insenstitive
        // non alphanumeric -> need to apply for equivs in C++?

        // 1 remove spaces / join to become same
        // 2 reverse and compare
        // e.g. wasitacaroracatisaw

        // METHOD
        // index from start and finish to compare
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            // loop it to the end
            while(!isalnum(s[start]) && start < end) {
                start++;
            }
            while(!isalnum(s[end]) && start < end) {
                end--;
            }
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }

            // keep decrementing
            start++;
            end--;
        }
        return true;
        
    }
};
