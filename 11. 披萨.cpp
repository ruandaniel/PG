//dp[i][j] means max pizza the first person can get when slices[i:j] remained, assume everyone is smart
//dp[i][j] = max(slices[i] + sum[i+1:j] - dp[i+1][j], slices[j] + sum[i:j-1] - dp[i][j-1])
//         = max(sum[i:j] - dp[i+1][j], sum[i:j] - dp[i][j-1])

//dfs with memory
class Solution{
public:
	int pizza(vector<int> slices){
		int n = slices.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			dp[i][i] = slices[i];
		vector<int> sum(n + 1, 0); //sum[j] - sum[i] is sum[i : j - 1]
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + slices[i - 1];
		return helper(slices, dp, sum, 0, n - 1);
	}

	int helper(vector<int> &slices, vector<vector<int>> &dp, vector<int> &sum, int l, int r){
		if (dp[l][r]) return dp[l][r];
		int s = sum[r + 1] - sum[l];
		dp[l][r] = max(s - helper(slices, dp, sum, l + 1, r), s - helper(slices, dp, sum, l, r - 1));
		return dp[l][r];
	}
};

//bottom-up DP
class Solution{
public:
	int pizza(vector<int> slices){
		int n = slices.size();
		vector<int> sum(n + 1, 0); //sum[j] - sum[i] is sum[i : j - 1]
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + slices[i - 1];
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) dp[i][i] = slices[i];
		for (int j = 1; j < n; j++){
			for (int i = 0; i + j < n; i++){
				int s = sum[i + j + 1] - sum[i];
				dp[i][i + j] = max(s - dp[i + 1][i + j], s - dp[i][i + j - 1]);
			}
		}
		return dp[0][n - 1];
	}
};

//O(n^2) time
