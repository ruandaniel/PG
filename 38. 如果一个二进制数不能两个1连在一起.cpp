//dp[i][0] means ith digit is 0, how many possibilities so far
//dp[i][1] means ith digit is 1, how many so far
//dp[i][0] = dp[i - 1][0] + dp[i - 1][1]
//dp[i][1] = dp[i - 1][0]
class Solution{
public:
	int function(int n){
		if (n == 0) return 0;
		int zero = 1, one = 1;
		for (int i = 2; i <= n; i++){
			int t = zero;
			zero += one;
			one = t;
		}
		return zero + one;
	}
};