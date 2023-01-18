// https://leetcode.com/problems/integer-to-roman/description/
// Integer to roman

class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]  = {"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};


// https://leetcode.com/problems/roman-to-integer/description/
// Roman to Integer

class Solution {
public:
int romanToInt(string num) {
    unordered_map<char,int> m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;

    int ans=0;
    for(int i=0;i<num.size()-1; i++)
    {
        if(m[num[i]]>=m[num[i+1]])
        ans+=m[num[i]];
        else
        ans-=m[num[i]];
    }
    ans+=m[num[num.size()-1]];
    return ans;

}
};
