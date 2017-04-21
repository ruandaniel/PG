class Solution{
public:
	vector<string> allPaths(int m, int n){
		unordered_map<string, vector<string>> mp;
		string final = to_string(m) + ' ' + to_string(n);
		mp[final] = { final };
		return findPath(0, 0, m, n, mp);
	}

	vector<string> findPath(int a, int b, int m, int n, unordered_map<string, vector<string>> &mp){
		string s = to_string(a) + ' ' + to_string(b);
		if (mp.count(s)) return mp[s];
		string ss = s + ",";
		vector<string> cur;
		if (a < m){
			auto t = findPath(a + 1, b, m, n, mp);
			for (auto i : t){
				cur.push_back(ss + i);
			}
		}
		if (a > b && b < n){
			auto t = findPath(a, b + 1, m, n, mp);
			for (auto i : t){
				cur.push_back(ss + i);
			}
		}
		mp[s] = cur;
		return cur;
	}
};