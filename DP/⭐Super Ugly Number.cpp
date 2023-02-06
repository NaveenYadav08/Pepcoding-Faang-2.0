https://leetcode.com/problems/super-ugly-number/description/


// PRIORITY QUEUE
#define ll long long
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        vector<ll> nums(n);
        vector<ll> indices(primes.size(),0); 
        // keep track that which multiple from nums is multiplied with primes

   

        // index of the prime number inside nums array
        nums[0] = 1;

		// first item is value of ugly number, second item is identity of the prime
        // second is the index of primes
        // first is the number primes

        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>pq;
        for(int i=0; i<primes.size(); ++i)  pq.emplace(primes[i], i);

        for(int i=1; i<n; ){
            auto [val, id] = pq.top();
            pq.pop();
            if(val != nums[i-1])    nums[i++] = val; // avoid duplicate
             // prevent overflow
                pq.emplace(nums[++indices[id]] * primes[id], id);
        }
        return (int)nums.back();
    }
};




DP 

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int N = primes.size();
        vector<int> ptr(N,0);

        vector<long long> DP;
        DP.push_back(1);

        if(n==1) return 1;

        for(int i=2;i<=n;i++)
        { long long mini = LLONG_MAX;
          

          for(int j=0;j<ptr.size();j++)
          {
              if(DP[ptr[j]]*primes[j] <= mini)
              {
                  mini = DP[ptr[j]] * primes[j];
              }
          }

          for(int j=0;j<ptr.size(); j++)
          {
              if(mini == DP[ptr[j]]*primes[j] )
              ptr[j]++;
          }

          DP.push_back(mini);

        }

        return (int)DP.back();
    }
};
