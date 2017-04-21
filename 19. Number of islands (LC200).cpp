class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    spread(grid, i, j, dirs);
                    res++;
                }
            }
        }
        return res;
    }
    
    void spread(vector<vector<char>>& grid, int x, int y, vector<vector<int>> &dirs){
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != '1') return;
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) 
            spread(grid, x + dirs[i][0], y + dirs[i][1], dirs);
    }
};