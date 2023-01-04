https://leetcode.com/problems/container-with-most-water/description/


We can start with the container of maximum width and then if there is we find a bar whose height is greater than the shorter of the previous two bars we took into consideration, then we can calculate the area between those two bars and so on.



class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,j = height.size() -1,area = 0;
        while(i < j){
            area = max(area, min(height[i],height[j])*(j-i));
            if(height[i] <= height[j])i++;
            else j--;
        }
        return area;   
    }
};
