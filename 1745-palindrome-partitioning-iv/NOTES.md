To cut a cake in 3 pieces, we need 2 cuts. Hence, if we can pick 2 indices (p, s) in the array, we can cut the string in 3 parts. This would look like :
​
str[0...p] + str[p + 1, ... s - 1] + str[s, ... n - 1]
​
Prepare the DP table in O(n^2).
Pick every (p, s) pairs in the array. (There are n^2 such pairs).
Query the DP table in O(1) to see whether any partition is a palindrome.