class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        set<int> sub(nums.begin(), nums.end());
        bool is_smaller = sub.size() < nums.size();
        return is_smaller;

    }
};

