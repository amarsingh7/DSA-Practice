class Solution {
public:
    int largestVariance(string s) {
        vector<int> counter(26, 0);  
        
        // Count the occurrences of each character in s
        for (char ch : s) {
            counter[ch - 'a']++; 
        }
        
        int globalMax = 0;  // Variable to store the largest variance
        
        // Iterate over all possible pairs of characters
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                // Skip this pair if major and minor are the same or if either character is not present in s
                if (i == j || counter[i] == 0 || counter[j] == 0) {
                    continue;
                }
                
                // Find the major and minor characters based on their indices
                char major = 'a' + i;
                char minor = 'a' + j;
                int majorCount = 0;  // Count of major character occurrences
                int minorCount = 0;  // Count of minor character occurrences
                int restMinor = counter[j];  // Remaining minor character count in the rest of s
                
                // Iterate over each character in s
                for (char ch : s) {    
                    if (ch == major) {
                        majorCount++;  // Increment the major character count
                    }
                    if (ch == minor) {
                        minorCount++;   
                        restMinor--;    
                    }
                    
                    // Update the largest variance if there is at least one minor character
                    if (minorCount > 0) {
                        globalMax = max(globalMax, majorCount - minorCount);
                    }
                    
                    // If the major character count becomes less than the minor character count
                    // and there are still remaining minor characters, we can reset the counts
                    if (majorCount < minorCount && restMinor > 0) {
                        majorCount = 0;
                        minorCount = 0;
                    }
                }
            }
        }
        
        return globalMax;  
    }
};
