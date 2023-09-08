class Solution {
public:
    int ans = 0; 

    // Backtracking function to explore different combinations of words.
    void backtrack(vector<string> &words, vector<int> &score, vector<int> &count, vector<int> &used, int ind, int res) {
        // Check if any used character count exceeds its given count.
        for (int i = 0; i < 26; i++) {
            if (used[i] > count[i])
                return; 
            // If any character count is exceeded, stop exploring 
        }
        
        ans = max(ans, res); 

        for (int i = ind; i < words.size(); i++) {
            for (auto x : words[i]) {
                used[x - 'a']++; 
                // Mark characters from the current word as used.
                res += score[x - 'a']; 
                // Add score of the used characters to the result.
            }

     // Recursively explore next word while updating counts, result.
            backtrack(words, score, count, used, i + 1, res);

            for (auto x : words[i]) {
                used[x - 'a']--; 
                // Unmark characters as used (backtrack).
                res -= score[x - 'a']; 
                // Subtract score of the characters from the result.
            }
        }
    }

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        vector<int> count(26, 0); 
        // Initialize a count array to store available char counts.
        vector<int> used(26, 0); 
        // Initialize an array to keep track of used char\ counts.

        // Populate the count array with counts of available char
        for (auto x : letters)
            count[x - 'a']++;

        // Start the backtracking process with initial values.
        backtrack(words, score, count, used, 0, 0);

        return ans; // Return the maximum score found.
    }
};
