class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorfs = 0;  // Variable to store XOR of both 1st and 2nd numbers
        int mask = 1;   // Mask to find the rightmost set bit in XOR result
        int first = 0;  // Variable to store the first single number

        // Step 1: Calculate XOR of all elements in 'nums' vector
        for (auto &x : nums) {
            xorfs ^= x;
        }

        // Step 2: Find the rightmost set bit in 'xorfs' using 'mask'
        while (!(xorfs & mask)) {
            mask <<= 1;
        }

        // Step 3: Find the first single number by iterating through 'nums'
        for (auto &x : nums) {
            if (x & mask) {
                first ^= x;
            }
        }

        // Step 4: Find the other single number using XOR operation
        int second = xorfs ^ first;

        // Return the vector containing both single numbers
        return {first, second};
        
    }
};