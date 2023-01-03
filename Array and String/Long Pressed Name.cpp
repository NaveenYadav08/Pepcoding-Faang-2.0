https://leetcode.com/problems/long-pressed-name/description/

SOLUTION 

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n_idx=0;
        int t_idx=0;
        if(name[0]!=typed[0]) return false;
        for(;t_idx<typed.size();t_idx++)
        {
            if(typed[t_idx]==name[n_idx]) n_idx++;
            else if(t_idx!=0 and typed[t_idx]!=typed[t_idx-1]) return false;
        }
        return(n_idx==name.size());
    }
};
