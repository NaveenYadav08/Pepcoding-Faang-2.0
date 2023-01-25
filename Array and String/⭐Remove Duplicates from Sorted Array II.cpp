https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =nums.size();
        if(n < 3) return n;
        
        int indx = 2; // make it k and -2 as -k for general
        for(int i =2; i< nums.size(); i++){
             if(nums[i] != nums[indx -2]){
                 nums[indx] = nums[i];
                 indx++;
             }
        }
        return indx;
  }
};
