class Solution{
public:
	int peak(vector<int> nums){
		int i = 0, j = nums.size() - 1;
		while (i < j){
			int l = i + (j - i) / 2;
			int r = l + 1;
			if (nums[l] < nums[r]) i = r;
			else j = l;
		}
		return l;
	}
};