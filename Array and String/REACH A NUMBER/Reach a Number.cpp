https://leetcode.com/problems/reach-a-number/description/

https://www.geeksforgeeks.org/find-the-number-of-jumps-to-reach-x-in-the-number-line-from-zero/

Note:- The minimum steps to target is same as the minimum steps to abs(target).

On each negative jump I cancel twice the effect because ( one its own and on next jump I have to recross that same length )
  

// CODE
  
class Solution {
public:
    int reachNumber(int target) {
        // answer is min n with value of n*(n+1)/2 greater then target and difference even
        int answer = 0; int n = 1;
        target = abs(target);
        int value = 0;
        while(value < target || (value-target)%2 == 1)
        {
            answer += 1;
            value+=n;
            n++;
        }
        return answer;
    }
};
