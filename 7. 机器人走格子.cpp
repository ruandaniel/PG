/*
Given APIs:
up();
down();
left();
right();
*/

class Solution{
public:
	void robot(vector<vector<bool>> board, int x, int y){
		int m = board.size(), n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool> (n, false));
		vector<vector<int>> dirs({{-1, 0}, {0, -1}, {0, 1}, {1, 0}});
		stack<int> record;
		travel(board, x, y, visited, dirs, record);
	}

	void travel(vector<vector<bool>> &board, int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &dirs, stack<int> &record){
		visited[x][y] = true;
		for (int i = 0; i < 4; i++){
			int xx = x + dirs[i][0], yy = y + dirs[i][1];
			if (xx < 0 || yy < 0 || xx >= board.size() || yy >= board[0].size() || !board[xx][yy] || visited[xx][yy]) continue;
			go(i);
			record.push(i);
			travel(board, xx, yy, visited, dirs, record);
		}
		if (!record.empty()) {
			go(3 - record.top());
			record.pop();
		}
	}

	//0 for up, 3 for down, 1 for left, 2 for right; so that two opposite dirs will add up to 3
	void go(int i){
		if (i == 0) up();
		else if (i == 1) left();
		else if (i == 2) right();
		else down();
	}
};