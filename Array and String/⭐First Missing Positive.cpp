https://leetcode.com/problems/first-missing-positive/description/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=0) nums[i]=INT_MAX; // to overcome negs and zeros
        }

        for(int i=0;i<nums.size();i++)
        {
            if(abs(nums[i])==INT_MAX) continue;
            else
            {
                int temp = abs(nums[i]);
                if(temp-1<nums.size() and nums[temp-1]>0) // to avoid duplicates
                nums[temp-1]*=-1;
            }
        }

        for(int i=0;i<nums.size();i++)
        {   if(abs(nums[i]==INT_MAX)) return i+1;
            else if(abs(nums[i])!=INT_MAX and nums[i]>0) return i+1;
        }
       
        return nums.size()+1;
    }
};
