//Greedy, always connect the shortest two
class Solution{
public:
	int robConnection(vector<int> robs){
		priority_queue<int, vector<int>, std::greater<int>> pq;
		int res = 0;
		for (auto r : robs) 
			pq.push(r);
		while (pq.size() > 1){
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			pq.push(a + b);
			res += a + b;
		}
		return res;
	}
};

//O(nlogn) time