https://www.lintcode.com/problem/903/

class Solution {
public:

    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        // Write your code here
        vector<int> ans(length,0);
        for(auto x:updates)
        {
            ans[x[0]]+=x[2];
            if(x[1]<length-1) ans[x[1]+1]-=x[2];
        }

        int T=0;
        for(int i=0;i<length;i++)
        {
            T+=ans[i];
            ans[i]=T;

        }
        return ans;

    }
};
