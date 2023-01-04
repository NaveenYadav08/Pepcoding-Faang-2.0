https://leetcode.com/problems/squares-of-a-sorted-array/description/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int s=0; int e=n-1;
        int N=n-1;
        while(s<=e)
        {
            if(abs(nums[s]) >= abs(nums[e]))
            {
                ans[N]=nums[s]*nums[s];
                s++;
            }
            else
            {
                ans[N]=nums[e]*nums[e];
                e--;
            }
            N--;
        }
        return ans;
    }
};
