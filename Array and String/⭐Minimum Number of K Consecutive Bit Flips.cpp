// If we encounter a '0', it MUST be flipped and hence we increase ans by 1.

// If we don't get k elements including this element, that means we can't change this element from 0 to 1 and we have to return -1.

// if flip[i]%2==0 it means i th element has been flipped even number of times and is in the same state as mentioned in ar[i].

// Flipping is done when ar[i] has 0 and ar[i] is in original state of when ar[i] is 1 and ar[i] is in flipped state.


class Solution {
public:
int minKBitFlips(vector<int>& ar, int k) {
   
    int n=ar.size(),ans=0;
    vector<int> flip(n,0); //  flip[i] stores how many times current index(i) is flipped

    for(int i=0;i<n;i++){

        if(i) flip[i]+=flip[i-1]; 
        if((flip[i]%2 && ar[i]) || (flip[i]%2==0 && !ar[i])){ // result nullified
            ans++; 
            // ar[i] MUST be flipped 
            // ar[i+k] ( i-k is not flipped by i )
            flip[i]++;
            if(i+k>n) return -1; 
            if(i+k<n) flip[i+k]--; // nullify effect on i+k
        }

    }
    return ans;
}
};
