class Solution{
public:
	vector<pair<int, int>> sumToZero(vector<int> nums){
		vector<int> sum(nums.size() + 1, 0);
		unordered_map<int, vector<int>> m;
		vector<pair<int, int>> res;
		m[0].push_back(0);
		for (int i = 1; i < sum.size(); i++){
			sum[i] = sum[i - 1] + nums[i - 1];
			if (m.count(sum[i])){
				auto pre = m[sum[i]];
				for (int j = 0; j < pre.size(); j++){
					res.push_back({pre[j], i - 1});
				}
			}
			m[sum[i]].push_back(i);
		}
		return res;
	}
};

//T <= O(n^2)
