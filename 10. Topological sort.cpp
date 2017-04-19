class Solution{
public:
	string dicOrder(vector<string> words){
		unordered_map<int, unordered_set<int>> neighbors;
		vector<int> indegree(26, -1);
		for (auto w : words){
			for (int i = 0; i < w.size(); i++){
				int b = w[i] - 'a';
				if (indegree[b] == -1) indegree[b] = 0;
				if (i == 0) continue;
				int a = w[i - 1] - 'a';
				if (neighbors[a].find(b) == neighbors[a].end()){
					//below will validate input
					if (neighbors[b].find(a) != neighbors[b].end()) return "Invalid";
					indegree[b]++;
					neighbors[a].insert(b);
				}
			}
		}
		priority_queue<int, vector<int>, std::greater<int>> pq;
		for (int i = 0; i < 26; i++){
			if (indegree[i] == 0) pq.push(i);
		}
		string res = "";
		while (!pq.empty()){
			priority_queue<int, vector<int>, std::greater<int>> temp;
			while (!pq.empty()){
				int t = pq.top();
				pq.pop();
				res += char('a' + t);
				for (auto n : neighbors[t]){
					indegree[n]--;
					if (indegree[n] == 0) temp.push(n);
				}
			}
			pq = temp;
		}
		return res;
	}
};

//O(n), n is number of chars