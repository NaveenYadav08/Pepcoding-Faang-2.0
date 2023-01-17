https://leetcode.com/problems/flip-string-to-monotone-increasing/description/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int zeros_flipped=0;
        for(int i=0;i<n;i++)
        if(s[i]=='0') zeros_flipped++;

        int ones_to_zeros = 0, result = zeros_flipped;

        for(int i=0;i<n;i++)
        {   
            // consider each point as the breaking point before it all zero and after it all 1
            if(s[i]=='0')
            zeros_flipped--;
            else
            ones_to_zeros++;

            result = min(result, zeros_flipped+ones_to_zeros);

        }
        return result;
        
    }
};

