https://practice.geeksforgeeks.org/problems/count-element-occurences/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


// ITs Better solution is hashmap 
// this is just to understand mooore voting algorithm

class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        vector<pair<int,int>> count_element(k-1,{0,-1});
        
        for(int i=0;i<n;i++)
        {
            int j=0;
            for(;j<k-1;j++)
            {
                if(arr[i]==count_element[j].second) { count_element[j].first++; break; }
            }
            
            if(j==k-1) {  // no element found
               int l =0;
               for(;l<k-1;l++)
               {
                   if(count_element[l].first<=0){ 
                    count_element[l].first=1; 
                   count_element[l].second=arr[i];
                   break;}
               }
               
               if(l==k-1) // no element found
               {
                   for(int t=0;t<k-1;t++)
                   {
                       count_element[t].first=count_element[t].first-1;
                   }
               }
               
               
            } 
        }
        
        
        
        int ans=0; // major candidates
        for(auto x:count_element)
        {   int count=0;
            for(int t=0;t<n;t++)
            {
                if(x.second==arr[t])  count++;
            }
            if(count>(n/k)) ans++;
        }
        return ans;
    }
};
