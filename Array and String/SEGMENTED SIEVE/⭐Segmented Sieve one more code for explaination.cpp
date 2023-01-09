https://practice.geeksforgeeks.org/problems/product-of-primes5328/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


#define ll long long
#define mod 1000000007
class Solution{
public:

void simple_sieve(vector<ll>& chprimes, ll limit)
{
    vector<bool> PRIMES(limit + 1,true);
    for(ll i=2;i*i<=limit;i++)
    {
        if(PRIMES[i]==true)
        {  
            for(ll j=i*i;j<=limit;j+=i)
            {
                PRIMES[j]=false;
            }
        }
    }

    for(ll i=2;i<=limit;i++)
    {
        if(PRIMES[i])  {chprimes.push_back(i); 
        }
    }

}

long long segmented_sieve(ll low,ll high)
{
    ll limit= floor(sqrt(high)) + 1;
    vector<ll> chprimes;
    simple_sieve(chprimes,limit);
    long long p=1;
    if(low<2 and high>=2) low=2;

  
    vector<bool> primes(high-low+1,true);

    for(ll i=0;i<chprimes.size();i++)
    {
        ll lower = (low/chprimes[i])*chprimes[i];
        
        if(lower==0) lower=2*chprimes[i];
        if(lower<low) lower+=chprimes[i]; 
        if(lower==low and lower==chprimes[i]) lower+=chprimes[i];
        
        for(ll j=lower;j<=high;j+=chprimes[i])
        {
            primes[j-low]=false;
        }
    }

    for(ll i=low;i<=high;i++)
    {
        if(primes[i-low]==true) p = (p*i)%mod;
    }
    return p;




}

    long long primeProduct(long long L, long long R){
        // code here
        return segmented_sieve(L,R);
        
        
    }
};
