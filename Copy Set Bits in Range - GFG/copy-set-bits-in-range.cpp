//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
// Function to set a range of bits in integer 'x' based on the bits in integer 'y'.
// The range of bits to be set is from the 'l'-th bit to the 'r'-th bit (both inclusive).
// Function to set a range of bits in integer 'x' based on the bits in integer 'y'.
// The range of bits to be set is from the 'l'-th bit to the 'r'-th bit (both inclusive).
int setSetBit(int x, int y, int l, int r) {
    // Step 1: Create a mask to isolate the bits to be set in 'x'.
    int mask = 1; // Initialize a mask with the value 1 (binary: 0000...0001).
    
    // Shift the mask to the left by 'r - l + 1' positions and subtract 1 to create a bit pattern
    // with 'r - l + 1' set bits. Example: if 'l = 2' and 'r = 4', the mask will be '0000...0111'.
    mask = (mask << (r - l + 1)) - 1;
    
    // Step 2: Position the mask at the 'l'-th bit in 'y' and combine it with 'y'.
    // This operation isolates the 'r - l + 1' bits in 'y' that need to be set in 'x'.
    // Example: if 'y = 1010110', 'l = 2', and 'r = 4', the mask will be '0000...0111' and
    // the result will be '000000010' (the bits 2 to 4 in 'y').
    mask = (mask << (l - 1)) & y;
    
    // Step 3: Set the isolated bits from 'y' in 'x'.
    // Perform bitwise OR operation between 'x' and the mask.
    // Example: if 'x = 1101001' and the isolated bits from 'y' are '000000010',
    // the result of the OR operation will be '1101001 | 000000010 = 1101101'.
    x = x | mask;
    
    // Step 4: Return the updated value of 'x' after setting the specified bits from 'y'.
    return x;
}

};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends