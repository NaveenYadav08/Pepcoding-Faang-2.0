// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

// https://www.youtube.com/watch?v=aH-2Sig2H2Q

// CODE 

typedef pair<int, pair<int, int>> pi;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int L_ANS = INT_MIN;
        int R_ANS = INT_MAX;

        int RANGE = INT_MAX;

        int MMAX = INT_MIN;

        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i][0],{i,0}}); // ele row col
            MMAX=max(MMAX,nums[i][0]);
        }

        RANGE = MMAX-pq.top().first;
        L_ANS=pq.top().first;
        R_ANS=MMAX;

        while(!pq.empty())
        {
            auto temp = pq.top();
            if( (MMAX-temp.first)< RANGE )
            {
                L_ANS=temp.first;
                R_ANS=MMAX;
                RANGE=R_ANS-L_ANS;
            }
            pq.pop();
            if(temp.second.second==nums[temp.second.first].size()-1) break;
            else
            {
                auto new_ele = nums[temp.second.first][temp.second.second+1];
                MMAX=max(MMAX,new_ele);
                pq.push({new_ele,{temp.second.first,temp.second.second+1}});
            }
        }

        vector<int> ANS;
        ANS.push_back(L_ANS); ANS.push_back(R_ANS);
        return ANS;
       cout<<RANGE<<endl;
       cout<<L_ANS<<" "<<R_ANS<<endl;
        return {};
    }
};



