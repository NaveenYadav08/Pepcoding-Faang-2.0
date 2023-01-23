https://leetcode.com/problems/optimal-division/description/

MATH BASED


class Solution {
public:

string optimalDivision(vector<int>& nums) {

      int n = nums.size();

      if(n == 0) return "";
      string num = to_string(nums[0]);
      
      if(n == 1) return num;
      if(n == 2) return num + "/" + to_string(nums[1]);

      string den = "";

      for(int i = 1; i < n; i++){
         den += to_string(nums[i]);
         if(i != n - 1) den += "/";
      }
      return num + "/" + "(" + den + ")";
   }
};



// EXPLAIN 

To maximize a, b, c we pick the greater one from a / b / c and a / (b / c).

Let’s compare them.

Since a / b / c = a / (b * c) and a / (b / c) = a * c / b.

Multiplying b / a we get 1 / c and c. So given c >= 1 we always have 1 / c <= c, and thus a / b / c <= a / (b / c).

So given a, b, c, a / (b / c) is always greater than a / b / c.

For a, b, c, d:

If we divide it into a and b, c, d, the greatest result is a / (b / c / d) = a * c * d / b.
If we divide it into a, b and c, d, the result is (a / b) / (c / d) = a * d / (b * c).
If we devide it into a, b, c and d, the greatest result is a / (b / c) / d = a * c / (b * d).
We can see a * c * d / b is the greatest since its denominator is the smallest.

So given a, b, c, d, a / (b / c / d) is the greatest division.

Generally, the best division of x_1, x_2, ..., x_n is x_1 / (x_2 / ... / x_n) (which equals x_1 * x_3 * ... x_n / x_2).

