class Solution {
public:
    int search(vector<int>& nums, int target) {

        // NEW SOlUTION: dynamically recalc midpoint
        int lower = 0;
        int upper = nums.size()-1;

        while (lower <= upper) {

            // formula:
            // upper - lower == dist
            // / 2 for midpoint 
            // + lower to correctly shift on x axis 
            int mid = lower + ((upper - lower ) / 2);

            if (nums[mid] > target) {
                // kick down upper bound
                upper = mid - 1;
            } else if (nums[mid] < target) {
                lower = mid + 1;
            } else {
                // located index match
                return mid;
            }
        }

        return -1;

        /*
        // OLD SOLUTION: pivot based split
        // idea: start in middle -> split down
        // idea: to prevent back forth, add to (seen before) list
        
        int len = nums.size();
        // base case
        if (len == 1 && nums[0] != target) {
            return -1;
        }
        
        // select midpoint
        int pivot = len / 2;

        // pick direction
        bool go_left = true;

        if (nums[pivot] == target) {
            return pivot;
        }

        if (nums[pivot] > target) {
            pivot--;
        }
        else {
            // nums[pivot] < target
            go_left = false;
            pivot++;
        }

        // iterate until index out of bounds
        while (pivot != -1 && pivot != len) {
            // found!
            if (nums[pivot] == target) {
                return pivot;
            }
            else {
                if (go_left) {
                    pivot--;
                }
                else {
                    pivot++;
                }
            }

        }

        // never found
        return -1;
        */
        
    }
};
