class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> indexes;
        int n = s.length();
        int num = words.size();
        int len = words[0].length();
        
        // Check for edge cases where either the string 's' or 'words' vector is empty
        if (n == 0 || num == 0 || len == 0)
            return indexes;

        int wordSize = num * len; // Total length of all words combined

        unordered_map<string, int> counts;
        for (string word : words)
            counts[word]++;

        // Iterate through each starting index within the length of a word
        for (int i = 0; i < len; i++) {
            int left = i, right = i, count = 0; // Initialize pointers and count for the current window
            unordered_map<string, int> seen; // Map to track word counts in the current window

            // Move the right pointer in increments of word length
            while (right + len <= n) {
                string word = s.substr(right, len); // Extract the current word
                right += len; // Move the right pointer to the end of the current word

                // Check if the word is in the 'words' vector
                if (counts.find(word) != counts.end()) {
                    seen[word]++; // Increment count for the current word in the window
                    count++; // Increment total count of words in the window

                    // Adjust the window by moving the left pointer if a word occurs more times than allowed
                    while (seen[word] > counts[word]) {
                        seen[s.substr(left, len)]--; // Decrement count for the word at the left pointer
                        count--; // Decrement total count
                        left += len; // Move the left pointer to the next word
                    }

                    // If all words are found exactly once, add the starting index to the result
                    if (count == num)
                        indexes.push_back(left);
                } else {
                    // If an invalid word is encountered, reset the window
                    seen.clear(); // Clear the map
                    count = 0; // Reset the total count
                    left = right; // Move the left pointer to the next position
                }
            }
        }

        return indexes;
    }
};
