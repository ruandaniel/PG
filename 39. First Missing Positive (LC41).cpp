//assume from 0
class Solution{
public:
	int firstMissing(vector<int> nums){
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] != i && nums[i] < nums.size() && nums[i] >= 0 && nums[nums[i]] != nums[i])
				swap(nums[i], nums[nums[i]]);
		}
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] != i) return i;
		}
		return nums.size();
	}
};

/*
有一个很长的array，里面的数字不是出现1次就是3次，找出出现3次的。hashmap不满意，用了bit存
有一个很长的array，里面的数字不是出现2次就是4次，找出出现4次的
use bit, 2 bits for one number

有一个很长的array，1-n, 其中有一个number missing了怎么做？

*/