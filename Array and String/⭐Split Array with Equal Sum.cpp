// Split Array with Equal Sum

https://www.lintcode.com/problem/877/description



class Solution
{
  public:

    bool splitArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> sum(n, 0);
        sum[0] = nums[0];

        for (int i = 1; i < n; ++i)
            {sum[i] = sum[i - 1] + nums[i]; }
            // cout<<endl;


        for (int j = 3; j < n - 3; ++j)
        {
            set<int> S;
            
            for (int i = 1; i < j - 1; ++i)
                if (sum[i - 1] == sum[j - 1] - sum[i])
                    S.insert(sum[i - 1]);

            for (int k = j + 2; k < n - 1; ++k)
                if (sum[k - 1] - sum[j] == sum[n - 1] - sum[k] && S.count(sum[k - 1] - sum[j]))
                    return true;
        }
        return false;
    }
};
