https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/



class Solution {
public:
    
    int help(const vector<int>& sum, int L, int M) {
        int maxSumL = sum[L], maxSumLM = sum[L+M];
        for(int i=L+M+1;i<sum.size();i++){
            int curSumL = sum[i-M] - sum[i-M-L]; // L peeche M aage
            int curSumM = sum[i]-sum[i-M]; // M steps back
            maxSumL = max(maxSumL, curSumL);
            maxSumLM = max(maxSumLM, maxSumL + curSumM);
        }
        return maxSumLM;
    }
};
