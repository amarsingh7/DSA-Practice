class Solution {
public:
    int result = 0; // Global variable to store the result
    int targ;
    unordered_map<int, int> map; 
    //will store running sums and their occurrences

    //calculate the number of subarrays that sum to the target
    void solve(vector<int>& nums) {
        int sum = 0;
        map.clear(); // Clear the map for each new set of numbers
        map[0]++; 
        // Initialize with a sum of 0 (represents an empty subarray)

        for (int &i : nums) {
            sum += i;
            result += map[sum - targ]; 
            //subarrays whose sum equals target and ends at index i
            map[sum]++; 
            // Add the occurrence of the running sum to the map
        }
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)      {
        int r= matrix.size();
        int c= matrix[0].size();
        targ = target; // Set the target sum
        
        vector<int> row(c); 
        // Initialize a vector for storing row sums

        for (int i = 0; i < r; i++) {
            fill(row.begin(), row.end(), 0); 
            // Clear row vector to start with row i as beginning

            for (int j = i; j < r; j++) {
                // Add next row to row vector, effectively creating a 1D array representing submatrix
                for (int x = 0; x < c; x++)
                    row[x] += matrix[j][x];

                solve(row);
            }
        }

        return result;  
    }
};
