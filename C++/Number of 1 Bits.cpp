// Number of 1 Bits

// Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

// For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.


//My solution

class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        
        int temp = 1;
        
        
        while(n >= temp)
        {
            if(n & temp)
                count++;
            
            temp = temp << 1;
            
            if(temp == 1<<31)
                break;
        }
        
        if(n&temp)
            count++;
        
        return count;
        
    }
};