
https://www.codechef.com/problems/MAXREMOV

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define fs ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {

    fs;
    ll T;
    cin>>T;
    
    while(T--)
    {
        vector<ll> update(100009,0);
        vector<ll> K0(100009,0); // I made 2 arrays 
        vector<ll> K1(100009,0); // one will keep track of No of K till index i
        vector<vector<ll>> PAIR; // other will keep track of No of K+1 till index i

        ll N,K;
        cin>>N>>K;
        
        for(ll i=0;i<N;i++)
        {
            ll a,b;
            cin>>a>>b;
            PAIR.push_back({a,b});
            update[a]+=1;
            update[b+1]-=1;
        }

        // ll ANS=0;
        ll FINAL_ANS=LLONG_MIN;
        ll sum=0;
        ll ANS_K=0;
        ll ANS_K1=0;

        for(ll i=0;i<update.size();i++)
        {sum+=update[i]; 
        update[i]=sum; 
        if(update[i]==K)  {ANS_K++;}
        else if(update[i]==K+1) {ANS_K1++;}
         K0[i]=ANS_K;
         K1[i]=ANS_K1;
        }

        for(auto x:PAIR)
        {   auto a = x[0];
            auto b = x[1];
            
            ll temp = K0[a-1] + (K0[100008] - K0[b]) + (K1[b] - K1[a-1]);
            // cout<<K0[a-1]<<" "<<K0[100008]<<" "<<K0[b]<<" "<<K1[b]<<" "<<K1[a-1]<<endl;
            FINAL_ANS=max(FINAL_ANS, temp);
        }
        cout<<FINAL_ANS<<endl;
    }
}
