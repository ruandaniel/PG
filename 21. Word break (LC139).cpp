class Solution {
public:
    //dp[i] means s[0, i - 1] can be accessed
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic;
        for (auto w : wordDict) dic.insert(w);
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++){
            for (int j = i - 1; j >= 0; j--){
                if (dp[j]){
                    string word = s.substr(j, i - j);
                    if (dic.find(word) != dic.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            
        }
        return dp[s.size()];
    }
};