//PQ, O(nlogn)
class Solution{
public:
	vector<int> topK(vector<int> nums, int k){
		unordered_map<int, int> m;
		priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq; //min-heap
		for (auto num : nums) m[num]++;
		for (auto i : m){
			pq.push({i.second, i.first});
			if (pq.size() > k) pq.pop();
		}
		vector<int> res;
		while (!pq.empty()) {
			res.push_back(pq.top().second);
			pq.pop();
		}
		return res;
	}
};

void main(){
	Solution s;
	auto t = s.topK({1,2,3,4,5,6,7,3,3,5,5,5,1,2,1,2,1,1}, 3);
	for (auto i : t) cout<<" "<<i;
}

//using bucket sort can achieve O(n) time