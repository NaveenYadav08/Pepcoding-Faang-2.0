https://leetcode.com/problems/shortest-word-distance-iii/

https://leetcode.ca/all/245.html

class Solution {
public:
   int shortestWordDistance(vector<string<& words, string word1, string word2) {
      int ret = 1e9;
      int l1 = 1e9;
      int l2 = -1e9;
      int n = words.size();
      for (int i = 0; i < n; i++) {
         if (words[i] == word1) {
            l1 = i;
         }
         if (words[i] == word2) {
            if (word1 == word2) {
               l1 = l2;
            }
            l2 = i;
         }
         ret = min(abs(l2 - l1), ret);
      }
      return ret;
   }
};
