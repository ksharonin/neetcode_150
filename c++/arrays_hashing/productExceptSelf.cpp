class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // ATTEMPT 

        // given: array of nums
        // return: arr where output[i]
        // is product 
        // NOTE can be signed
        // NOTE all should fit in 32 bit int

        // idea; go thru and divide out self
        // solve without dividing out?

        // build total sum
        int multi = 1;

        for (const int& n: nums) {
            multi *= n;
        }

        // now construct vector 
        vector<int> result;
        int index = 0;

        for (const int& i: nums){

            int calc;

            if (i != 0) {
                // VIOLATES RESTRICTION
                calc = static_cast<int>(multi / i);
            } 
            else {
                // div 0
                // ISSUE: whole multi would be 0 otherwise
                // TRY: copy original vector, and remove
                // this wastes complexity...

                vector<int> nums_cpy = nums;
                nums_cpy.erase(nums_cpy.begin() + index);
                calc = 1;
                for (const int& n: nums_cpy) {
                    calc *= n;
                }


            }

            result.push_back(calc);
            index++;
        }

        return result;

        // OFFICIAL SOLUTION NOTES
        
        // 1. init vector of len nums, all elements as 1
        // 2. iterate through result and generate product
        // 2. now go backwards 
        // REASONING: to avoid the divide operator
        // prefix: prod all BEFORE nums[i]
        // postfix: prod all AFTER nums[i]

        // e.g. 
        // [1,2,3,4]
        // prefix, mul this way ->
        // [1, 2, 6, 24]
        // postfix, mul this way <-
        // [24, 24, 12, 4]
        // output
        // 1 is default prefix
        // 1. take prefix before, and mul with i+1 postfix
        // 2: get prefix which is 1 at i-1, then postfix is i+1 
        // mul prefix and postfix

        // FOR MEMORY COMPACTNESS

        // store prefix result in intended slot of output
        // default fill value 1s
        // then final result is remainders after position in input

        /*
        class Solution {
        public:
            vector<int> productExceptSelf(vector<int>& nums) {
                int n = nums.size();
                vector<int> result(n, 1);
                
                int prefix = 1;
                for (int i = 0; i < n; i++) {
                    result[i] = prefix;
                    prefix = prefix * nums[i];
                }
                
                int postfix = 1;
                for (int i = n - 1; i >= 0; i--) {
                    result[i] = result[i] * postfix;
                    postfix = postfix * nums[i];
                }
                
                return result;
            }
        };*/


    }
};
