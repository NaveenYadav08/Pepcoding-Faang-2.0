// https://www.youtube.com/watch?v=EtalsGoNrBI

// https://leetcode.com/problems/stamping-the-sequence/description/




class Solution {
public:

bool canReplace(string stamp,string target, int i)
{
     for(int j=0;j<stamp.size();j++)
     {
         if(target[j+i]!='?' and target[j+i]!=stamp[j])
         return false;
     }

     return true;
}

void replace(string stamp, string &target, int i, int& count)
{
    for(int j=0;j<stamp.size();j++)
    {
        if(target[j+i]!='?')
        {target[j+i]='?'; count++;}
    }
}



vector<int> movesToStamp(string stamp, string target) {
       
        int Slen=stamp.size(); // "abca" = 4
        int Tlen=target.size(); // "aabCaca" = 7

        int count = 0;
        vector<int> ans;
        vector<bool> stamp_starting_index(Tlen,false);

        while(count!=target.size())
        {   bool change = false;
            for(int i=0;i<=Tlen-Slen;i++)
            {
                if(stamp_starting_index[i]==false and canReplace(stamp,target,i))
                {
                    replace(stamp,target,i,count);
                    ans.push_back(i);
                    stamp_starting_index[i]=true;
                    change=true;
                    if(count==target.size()) break;
                }
                
            }
            // cout<<target<<endl;

            if(change ==false) return {};

        }

         reverse(ans.begin(),ans.end()); return ans;
         // return {};
    }
};
