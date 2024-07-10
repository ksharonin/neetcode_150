class Solution {
public:
    int maxArea(vector<int>& heights) {
        // ex 
        // [1,8,6,2,5,4,8,3,7]
        // 8 --> 6 --> 2 ...
        // count slots BEFORE the intended last num

        // to maximize area:
        // (1) find two largest heights where ALSO
        // (2) biggest len between each other 

        // two pointer approach 

        // [1,7,2,5,4,7,3,6]
        // len == 8

        // left max and right max recorded 
        // left = 1 --> index 0
        // right = 6 --> index 7
        // 7 - 0 == 7
        // if max changed, reassess len
        // len == 

        // return when index left == index right 

        // base case 
        if (heights.size() == 2) {
            // len must be 1
            return min(heights[0],heights[1]);
        }

        // start left right
        int left_index = 0;
        int right_index = heights.size() - 1;

        int current = 0;
        int winning_area = 0;

        while (left_index < right_index) {

            // NOTE: must take the MIN of the existing since
            // we can only support area up to that point
            current = (right_index - left_index) * min(heights[left_index], heights[right_index]);
            winning_area = max(winning_area, current);

            if (heights[left_index] <= heights[right_index]) {
                // upgrade index only if the left value could be incr
                left_index++;
            } else{
                right_index--;
            }


        }

        return winning_area;
    }
};
