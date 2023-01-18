// BOTH International & Indian Standards

https://leetcode.com/problems/integer-to-english-words/description/
// INTERNATIONAL 

class Solution {
public:

string digits[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

string tens[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        else{
            return int2string(num).substr(1);
        }
    }
    
    string int2string(int n){
        if(n >= 1000000000){
            return int2string(n / 1000000000) + " Billion" + int2string(n % 1000000000);
        }
        else if(n >= 1000000){
            return int2string(n / 1000000) + " Million" + int2string(n % 1000000);
        }
        else if(n >= 1000){
            return int2string(n / 1000) + " Thousand" + int2string(n % 1000);
        }
        else if(n >= 100){
            return int2string(n / 100) + " Hundred" + int2string(n % 100);
        }
        else if(n >= 20){
            return " " + tens[n / 10] + int2string(n % 10);
        }
        else if(n >= 1){
            return " " + digits[n];
        }
        else return "";
    }    
};



// https://practice.geeksforgeeks.org/problems/number-to-words0335/1
// INDIAN 

class Solution{   
public:

vector<string> one={"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "};
vector<string> tens={"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
    

string numtoword(long n,string s){
   
        string str="";
        if(n>19){
            str+=tens[n/10]+one[n%10];
        }else{
            str+=one[n];
        }
        if(n!=0){
            str+=s;
        }
        return str;
    }
    
    
    string convertToWords(long n) {
        // code here
        string ans="";
        ans+=numtoword((int)(n/10000000),"crore ");
        ans+=numtoword((int)((n/100000)%100),"lakh ");
        ans+=numtoword((int)((n/1000)%100),"thousand ");
        ans+=numtoword((int)((n/100)%10),"hundred ");
        if(n>100 && n%100>0){
            ans+="and ";
        }
        ans+=numtoword((int)(n%100),"");
        return ans;
    }
};

