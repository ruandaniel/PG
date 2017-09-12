class Solution{
public:
	struct Cell{
		int x, y;
		vector<Cell*> path;
		long keys;
		Cell(int a, int b, vector<Cell*> p, long k) : x(a), y(b), path(p), keys(k){}
		void printStatus(){
			cout << '(' << x << ',' << y << ") with keys '";
			for (int i = 0; i < 26; i++) if (keys & (1 << i)) cout << char('a' + i);
			cout << "'" << endl;
		}
	};

	void findShortestRoute(vector<string> map){
		Cell *start = new Cell(-1, -1, {}, 0), *end = new Cell(-1, -1, {}, 0);
		for (int i = 0; i < map.size(); i++){
			for (int j = 0; j < map[i].size(); j++){
				if (map[i][j] == '2'){
					start->x = i;
					start->y = j;
				}
				else if (map[i][j] == '3'){
					end->x = i;
					end->y = j;
				}
			}
		}
		vector<vector<unordered_set<int>>> prevVisit(map.size(), vector<unordered_set<int>>(map[0].size(), unordered_set<int>()));
		queue<Cell*> q;
		q.push(start);
		vector<Cell*> final;
		int dirs[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		while (!q.empty()){
			auto t = q.front();
			q.pop();
			long curKeys = t->keys;
			auto curPath = t->path;
			curPath.push_back(t);
			if (t->x == end->x && t->y == end->y){
				final = curPath;
				break;
			}
			char c = map[t->x][t->y];
			if (c == '0') continue; //water
			if (prevVisit[t->x][t->y].find(t->keys) != prevVisit[t->x][t->y].end()) continue; //visited with same keys
			if (c >= 'A' && c <= 'Z'){ //door
				if ((t->keys >> c - 'A') == 0) continue;
			}
			if (c >= 'a' && c <= 'z'){ //pick key
				curKeys |= (1 << (c - 'a'));
			}
			for (int k = 0; k < 4; k++){ //try four dirs
				int i = t->x + dirs[k][0];
				int j = t->y + dirs[k][1];
				if (i < 0 || j < 0 || i >= map.size() || j >= map[0].size()) continue;
				q.push(new Cell(i, j, curPath, curKeys));
			}
		}
		for (auto i : final){
			i->printStatus();
		}
			
	}
};

void main(){
	Solution s;
	s.findShortestRoute({ "02a11",
						  "0100A",
						  "0b00B",
						  "11003",
						  "10001",
						  "11111" });

}



//version with *pre
class Solution{
public:
	struct Cell{
		int x, y;
		Cell *pre;
		int keys;
		Cell(int a, int b, Cell* p, int k) : x(a), y(b), pre(p), keys(k){}
		void printStatus(){
			cout << '(' << x << ',' << y << ") with keys '";
			for (int i = 0; i < 26; i++) if (keys & (1 << i)) cout << char('a' + i);
			cout <<"'"<< endl;
		}
	};

	void findShortestRoute(vector<string> map){
		Cell *start = new Cell(-1, -1, NULL, 0), *end = new Cell(-1, -1, NULL, 0);
		for (int i = 0; i < map.size(); i++){
			for (int j = 0; j < map[i].size(); j++){
				if (map[i][j] == '2'){
					start->x = i;
					start->y = j;
				}
				else if (map[i][j] == '3'){
					end->x = i;
					end->y = j;
				}
			}
		}
		vector<vector<unordered_set<int>>> prevVisit(map.size(), vector<unordered_set<int>>(map[0].size(), {}));
		queue<Cell*> q;
		q.push(start);
		Cell *final = NULL;
		int dirs[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		while (!q.empty()){
			auto t = q.front();
			q.pop();
			char c = map[t->x][t->y];
			int curKeys = t->keys;
			if (t->x == end->x && t->y == end->y){
				final = t;
				break;
			}
			if (c == '0') continue; //water
			if (prevVisit[t->x][t->y].find(t->keys) != prevVisit[t->x][t->y].end()) continue; //visited with same keys
			if (c >= 'A' && c <= 'Z'){ //door
				if ((t->keys >> c - 'A') == 0) continue;
			}
			if (c >= 'a' && c <= 'z'){ //pick key
				curKeys |= (1 << (c - 'a'));
			}
			for (int k = 0; k < 4; k++){ //try four dirs
				int i = t->x + dirs[k][0];
				int j = t->y + dirs[k][1];
				if (i < 0 || j < 0 || i >= map.size() || j >= map[0].size()) continue;
				q.push(new Cell(i, j, t, curKeys));
			}
		}
		stack<Cell*> st; //backtrack find path
		st.push(final);
		Cell* temp = final;
		while (temp->pre != NULL){
			temp = temp->pre;
			st.push(temp);
		}
		while (!st.empty()) {
			st.top()->printStatus();
			st.pop();
		}
	}
};