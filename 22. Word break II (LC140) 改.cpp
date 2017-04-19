//output a word break that has most components
class Solution {
public:
    //dp[i] means s[0, i - 1] can be accessed
    vector<string> wordBreak(string s, vector<string> wordDict) {
        unordered_set<string> dic;
        for (auto w : wordDict) dic.insert(w);
        vector<vector<string>> dp(s.size() + 1, vector<string>());
        dp[0].push_back("");
        for (int i = 1; i <= s.size(); i++){
            int index = -1, number = 0;
            string word;
            for (int j = 0; j < i; j++){
                if (!dp[j].empty()){
                    word = s.substr(j, i - j);
                    if (dic.find(word) != dic.end()) {
                        if (index == -1 || dp[j].size() > number){
                            number = dp[j].size();
                            index = j;
                        }
                    }
                }

            }
            if (index != -1){
                dp[i] = dp[index];
                dp[i].push_back(s.substr(index, i - index));
            }
        }
        auto res = dp[s.size()];
        if (!res.empty()){
            res.erase(res.begin());
        }
        return res;
    }
};