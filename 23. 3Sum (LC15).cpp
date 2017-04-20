class Solution{
public:
	vector<vector<int>> threeSum(vector<int> nums){
		if (nums.size() < 3) return {};
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++){
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int j = i + 1, k = nums.size() - 1;
			int target = -nums[i];
			while (j < k){
				if (nums[j] + nums[k] < target)
					j++;
				else if (nums[j] + nums[k] < target)
					k--;
				else{
					res.push_back({nums[i], nums[j++], nums[k--]});
					while (j < k && nums[j] == nums[j - 1]) j++;
					while (j < k && nums[k] == nums[k + 1]) k--;
				}
			}
		}
		return res;
	}
};

//O(n^2) time