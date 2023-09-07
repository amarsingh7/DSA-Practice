#include <bits/stdc++.h>

class Solution {
public:
    
    bool isValidSerialization(string preorder) {
        int degree = 1;               
        // Initialize 'degree' to 1 (one slot for the root node)
        string temp;                  
        // temporary string 'temp' to store each part of the input
        stringstream ss;              
        // stringstream 'ss' to process the 'preorder' string
        ss << preorder;              
        // Load the 'preorder' string into the stringstream 'ss'
        vector<string> vec;          
        // vector 'vec' to store parts of the 'preorder' string
        
        // Split the 'preorder' string into parts separated by commas and store them in 'vec'
        while (getline(ss, temp, ',')) {
            vec.push_back(temp);
        }
        
        // Iterate through each part of the 'vec'
        for (auto x : vec) {
            degree--;                
            // Decrease the available slot count by 1
            
            // If at any point we have more closing nodes than opening nodes, it's invalid
            if (degree < 0)
                return false;
            
            // If current part is not '#' (i.e not an empty node):
            if (x[0] != '#')
                degree += 2;         
            // Increase available slot count by 2 because non-empty nodes have two children
        }
        
        // After processing all parts, if 'degree' is 0, it means the serialization is valid
        return degree == 0;
    }
};
