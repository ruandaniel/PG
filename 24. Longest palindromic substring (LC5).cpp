class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int start = 0, len = 1;
        for (int i = 0; i < s.size(); i++){
            if (s.size() - i <= len / 2) break; //the remain not long enough to contain longer
            int j = i, k = i;
            while (k + 1 < s.size() && s[k + 1] == s[k]){ //right skip to the end of dup chars
                k++;
            }
            i = k;
            while (k + 1 < s.size() && j > 0 && s[k + 1] == s[j - 1]){ //expand
                k++;
                j--;
            }
            if (k - j + 1 > len){
                start = j;
                len = k - j + 1;
            }
        }
        return s.substr(start, len);
    }
};

//O(n^2)