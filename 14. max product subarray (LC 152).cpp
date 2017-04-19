//DP
class Solution{
public:
	int maxProduct(vector<int>& nums){
		vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
		dp[0][0] = dp[0][1] = nums[0];
		int res = nums[0];
		for (int i = 1; i < nums.size(); i++){
			int a = dp[i - 1][0] * nums[i];
			int b = dp[i - 1][1] * nums[i];
			dp[i][0] = max(nums[i], max(a, b));
			dp[i][1] = min(nums[i], min(a, b));
			res = max(res, dp[i][0]);
		}
		return res;
	}
};

//to save space:
class Solution{
public:
	int maxProduct(vector<int>& nums){
		int cur0, cur1, res;
		res = cur0 = cur1 = nums[0];
		for (int i = 1; i < nums.size(); i++){
			int a = cur0 * nums[i];
			int b = cur1 * nums[i];
			cur0 = max(nums[i], max(a, b));
			cur1 = min(nums[i], min(a, b));
			res = max(res, cur0);
		}
		return res;
	}
};