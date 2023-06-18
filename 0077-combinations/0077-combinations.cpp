class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;  
        int i = 0;
        vector<int> combination(k, 0);  

        while (i >= 0) 
        {
            combination[i]++; // Increment the current element in the combination
            
            if (combination[i] > n) {
                // If the current element exceeds 'n', backtrack
                // by decrementing 'i' and exploring other possibilities
                i--;
            } 
            else if (i == k - 1) {
                // If 'i' reaches the last position in the combination,
                // a complete combination has been generated, so add to the result
                result.push_back(combination);
            } 
            else {
                i++;    // Move to the next position in the combination
                combination[i] = combination[i - 1]; 
                // Set the next element equal to the previous one
            }
        }

        return result;
    }
};