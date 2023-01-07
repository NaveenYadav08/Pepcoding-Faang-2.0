https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/

if nums[i] > R than these are break points   , move your start pointer to curr + 1;
else if element lies between the range than number of subarrays = end -  start + 1;
but if element is less than L than only that element will not contribute to ans ;
  
// CODE

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int L, int R) {
        int i=0,j=0,curr_subarrays=0,ans=0;

        while(j<nums.size())
        {
            if(nums[j]>R)
            {
                curr_subarrays=0;
                i=j+1;
            }

            else if(nums[j]>=L and nums[j]<=R)
            {
                curr_subarrays = j-i+1;
            }

            ans+= curr_subarrays;
            j++;
            
        }

        return ans;
    }
};
