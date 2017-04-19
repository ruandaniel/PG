//num is in 1 - 25000
//use bitmap
class Solution{
public:
	vector<int> findDup(vector<int> nums){
		vector<int> res;
		vector<long> m((25000 / 32) + 1, 0);
		for (auto num : nums){
			int a = num / 32, b = num % 32;
			long mask = 1 << b;
			if (m[a] & mask) res.push_back(num);
			else m[a] |= mask;
		}
		return res;
	}
};