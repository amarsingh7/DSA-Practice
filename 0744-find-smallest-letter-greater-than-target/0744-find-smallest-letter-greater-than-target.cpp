class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n= letters.size();
        if (letters.back() <= target) 
            return letters.front();
        int low = 0, high = n - 1;
        while (low <= high) {
            auto mid = (low + high) / 2;
            if (target < letters[mid]) 
                high = mid-1;
            else 
                low = mid + 1;
        }
        return letters[low];
    }
};