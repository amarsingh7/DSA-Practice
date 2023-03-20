class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size= flowerbed.size();
        if (n == 0) 
            return true;
        
        for (int i = 0; i < size; i++) 
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)) 
            {
                flowerbed[i] = 1;
                n--;
                if (n == 0) 
                    return true;
            }
        }
        return false;
    }
};