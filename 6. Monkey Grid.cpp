//BFS, using HashSet<string> to mark visited
class Solution{
public:
	int monkeyGrid(int k){
		int axisMax = 0;
		unordered_set<string> visited;
		queue<pair<int, int>> q;
		q.push({0, 0});
		int count = 0;
		while (!q.empty()){
			int x = q.front().first, y = q.front().second;
			q.pop();
			string str = to_string(x) + " " + to_string(y);
			if (visited.find(str) != visited.end()) continue;
			int sum = 0, a = x, b = y;
			while (a){
				sum += a % 10;
				a /= 10;
			}
			while (b){
				sum += b % 10;
				b /= 10;
			}
			if (sum <= k){
				count++;
				visited.insert(str);
				q.push({x + 1, y});
				q.push({x, y + 1});
				if (x > axisMax) axisMax = x;
			}
		}
		return count;
		//return (count - axisMax) * 4 - 3;
	}
};

//applying the feature that k will decide a bound, use a matrix to store visited or not
//we can't use double loop, e.g. when k = 10, (10, 20) is not accessible but sum <= k

class Solution{
public:
	int monkeyGrid(int k){
		int bound = 0;
		while (1){
			int sum = 0, a = bound;
			while (a){
				sum += a % 10;
				a /= 10;
			}
			if (sum > k) break;
			bound++;
		}
		vector<vector<bool>> visited(bound, vector<bool>(bound, false));

		int axisMax = 0;
		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		int count = 0;
		while (!q.empty()){
			int x = q.front().first, y = q.front().second;
			q.pop();
			if (x >= bound || y >= bound || visited[x][y]) continue;
			int sum = 0, a = x, b = y;
			while (a){
				sum += a % 10;
				a /= 10;
			}
			while (b){
				sum += b % 10;
				b /= 10;
			}
			if (sum <= k){
				count++;
				visited[x][y] = true;
				q.push({ x + 1, y });
				q.push({ x, y + 1 });
				if (x > axisMax) axisMax = x;
			}
		}
		return count;
	}
};