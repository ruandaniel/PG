//DFS + Memory
class Solution{
public:
	vector<string> allPaths(int m, int n){
		unordered_map<string, vector<string>> mp;
		string final = to_string(m) + ':' + to_string(n);
		mp[final] = { final };
		return findPath(0, 0, m, n, mp);
	}

	vector<string> findPath(int a, int b, int m, int n, unordered_map<string, vector<string>> &mp){
		string s = to_string(a) + ':' + to_string(b);
		if (mp.count(s)) return mp[s];
		string ss = s + " | ";
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

//bottom-up DP
class Solution{
public:
    vector<string> allPaths(int m, int n){
        vector<vector<vector<string>>> dp(m+1, vector<vector<string>>(n+1, vector<string>()));
        dp[m][n].push_back(to_string(m) + ':' + to_string(n) + " | ");
        for (int i = m; i >= 0; i--){
            for (int j = min(i, n); j >= 0; j--){
                string str = to_string(i) + ':' + to_string(j) + " | ";
                if ((i == j && i < m) || (i > j && i < m)){
                    for (auto k : dp[i + 1][j]){
                        dp[i][j].push_back(str + k);
                    }
                }
                if (i > j && j < n){
                    for (auto k : dp[i][j + 1]){
                        dp[i][j].push_back(str + k);
                    }
                }
            }
        }
        return dp[0][0];
    }
};