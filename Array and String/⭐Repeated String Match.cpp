// OJ: https://leetcode.com/problems/repeated-string-match/
// Time: O(B * (A + B))
// Space: O(A + B)
// Ref: https://leetcode.com/problems/repeated-string-match/solution/
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int k = 1;
        string s = a;
        for (; s.size() < b.size(); ++k) s += a;
        if (s.find(b) != string::npos) return k;
        return (s + a).find(b) != string::npos ? k + 1 : -1;
    }
};
