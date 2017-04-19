class Solution{
public:
	int minTotalDistance(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<int> row(m, 0), col(n, 0);
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				row[i] += grid[i][j];
				col[j] += grid[i][j];
			}
		}
		int res = 0;
		int i = 0, j = m - 1;
		while (i < j){
			int cur = min(row[i], row[j]);
			row[i] -= cur;
			row[j] -= cur;
			res += cur * (j - i);
			while (i < j && row[i] == 0) i++;
			while (i < j && row[j] == 0) j--;
		}
		i = 0; j = n - 1;
		while (i < j){
			int cur = min(col[i], col[j]);
			col[i] -= cur;
			col[j] -= cur;
			res += cur * (j - i);
			while (i < j && col[i] == 0) i++;
			while (i < j && col[j] == 0) j--;
		}
		return res;
	}
};