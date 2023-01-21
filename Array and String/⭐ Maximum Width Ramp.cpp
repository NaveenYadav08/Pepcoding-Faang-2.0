// https://leetcode.com/problems/maximum-width-ramp/description/

// MONOTONIC STACK

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {

        int mx = 0;
        stack<int> stk;
        stk.push(0);

        for(int i = 1; i < A.size(); ++i) {
            if(A[i] < A[stk.top()]) stk.push(i); // store strictly decreasing values
        }
        
        for(int i = A.size() - 1; i >= 0; --i) {
            while(!stk.empty() && A[i] >= A[stk.top()]) { // if this value is greater than value at stk top index, we have a candidate
                mx = max(mx, i - stk.top());
                cout<<i-stk.top()<<endl;;
                stk.pop();
            }
        }
        return mx;
    }
};
