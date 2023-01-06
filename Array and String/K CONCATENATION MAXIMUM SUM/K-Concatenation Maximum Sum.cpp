https://www.codechef.com/JAN18/problems/KCON

https://leetcode.com/problems/k-concatenation-maximum-sum/description/

// CODE

typedef long long int lli;

class Solution {
public:
    
        int maxSubArray(vector<int>& nums) {
        int maxfar=0;
        bool pos=false;
        int maxtill=0;
        for(int i=0;i<nums.size();i++)
        {   if(nums[i]>=0) pos=true;
            maxtill+=nums[i];
            if(maxtill<0)
                maxtill=0;
            maxfar=max(maxfar,maxtill);
        }
        if(pos==false)
        {
            int ans=INT_MIN;
            for(int i=0;i<nums.size(); i++)
                ans=max(ans,nums[i]);
            return ans;
        }
        return maxfar;
    }

int kConcatenationMaxSum(vector<int>& nums, int k) 
{
    
    lli sum=0;
    
    for(int i=0;i<nums.size();i++)
        sum+=nums[i];
    
    
    lli ans;
    
    
    vector<int> toko=nums;
    for(int i=0;i<nums.size();i++)
    {
          toko.push_back(nums[i]);
    }
    
    if(k==1)
        ans=maxSubArray(nums);
    
    else if(sum<0)
         ans=maxSubArray(toko);
    
    else ans=maxSubArray(toko)+sum*(k-2);
        
    
    ans=max<lli>(0,ans);
    ans%=(int)(1e9+7);
    
    
    return ans;
}
};
