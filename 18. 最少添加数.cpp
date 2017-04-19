//similar to DP
class Solution{
public:
	vector<int> numberToAdd(vector<int> nums, int n){
		int toReach = 1;
		sort(nums.begin(), nums.end());
		vector<int> res;
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] <= toReach){
				toReach += nums[i];
			}
			else{
				res.push_back(toReach);
				toReach *= 2;
			}
			if (toReach >= n) break;
		}
		return res;
	}
};