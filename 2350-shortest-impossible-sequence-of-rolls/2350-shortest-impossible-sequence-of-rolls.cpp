class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n = rolls.size();  
        // Get the number of elements in the 'rolls' vector.
        unordered_map<int, int> ump;  
        // Create an unordered_map to store the count of each element.
        int count = 0;  
        //to keep track of unique elements encountered.
        int res = 0;  
        //to store the length of the shortest sequence.

        for (auto x : rolls) {  
            ump[x]++;  
            // Increment count of current element in the unordered_map.
            
            if (ump[x] == 1)  
            // If count of current ele becomes 1, so it's a unique ele
                count++;  // Increment count of unique elements.
            
            if (count == k) {  
                // If we have encountered 'k' unique elements.
                res++;  // Increment result to account for this sequence.
                ump.clear();  
                // Clear unordered_map to start counting next sequence.
                count = 0;  // Reset the count of unique elements.
            }
        }

        return res + 1;  // Return the total count of sequences, adding 1 to account for the last remaining sequence.
    }
};
