/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
bool isMatch(string s, string p)
*/

//recursive
/*
1. p[1] != '*'
	return (p[0] == '.' || p[0] == s[0]) && isMatch(s[1:], p[1:])
2. p[1] == '*'
	return isMatch(s, p[2:]) || !s.empty() && (p[0] == '.' || p[0] == s[0]) && isMatch(s[1:], p)
*/

//DP, O(n * m)
/*
dp[i][j] means s[0, i) match p[0, j)
1. p[j - 1] != '*'
	dp[i][j] = (p[j - 1] == '.' || p[j - 1] == s[i - 1]) && dp[i - 1][j - 1]
2. p[j - 1] == '*'
	dp[i][j] == dp[i][j - 2] || (p[j - 2] == '.' || p[j - 2] == s[i - 1]) && dp[i - 1][j]
init:
	dp[0][0] = true, dp[0][0:] depends
*/

class Solution{
public:
	bool isMatch(string s, string p){
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		dp[0][0] = true;
		for (int j = 2; j < p.size() + 1; j++)
			if (dp[0][j - 2] && p[j - 1] == '*') dp[0][j] = true;
		for (int i = 1; i < s.size() + 1; i++){
			for (int j = 1; j < p.size() + 1; j++){
				if (p[j - 1] == '*'){
					dp[i][j] = dp[i][j - 2] || (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j];
				}
				else
					dp[i][j] = (p[j - 1] == s[i - 1] || p[j - 1] == '.') && dp[i - 1][j - 1]; 
			}
		}
		return dp[s.size()][p.size()];
	}
};