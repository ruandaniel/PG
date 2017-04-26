class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r){
            while (l < r && (!isNum(s[l]) && !isLet(s[l]))) l++;
            while (l < r && (!isNum(s[r]) && !isLet(s[r]))) r--;
            if (l >= r) break;
            if (tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    }
    
    bool isNum(char c){
        return c >= '0' && c <= '9';
    }
    
    bool isLet(char c){
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }
};