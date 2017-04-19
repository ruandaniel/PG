//DP, dp[i] means max chars in i steps
//for ith step, we can repeat dp[i-3] 2 times, or dp[i-4] 3 times, ..., or dp[2] i-3 times
class Solution{
public:
	int copyPaste(int n){
		if (n <= 6) return n;
		vector<int> dp(n + 1, 0);
		for (int i = 1; i <= 6; i++) dp[i] = i;
		for (int i = 7; i <= n; i++){
			for (int j = i - 3; j >= 2; j--){
				int rpt = i - j - 1;
				dp[i] = max(dp[i], dp[j] * rpt);
			}
		}
		return dp[n];
	}
};