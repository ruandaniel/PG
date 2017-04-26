class Solution{
public:
	bool inTriangle(vector<pair<int, int>> triangle, pair<int, int> point){
		bool inTriangle(vector<pair<int, int>> triangle, pair<int, int> point){
		for (auto t : triangle)
			if (equal(point, t)) return false;
		vector<pair<int, int>> lines;
		for (int i = 1; i < 3; i++)
			lines.push_back({ triangle[i].first - triangle[0].first, triangle[i].second - triangle[0].second });
		for (int i = 0; i < 2; i++)
			lines.push_back({ triangle[i].first - triangle[2].first, triangle[i].second - triangle[2].second });
		vector<pair<int, int>> pointLine;
		pointLine.push_back({ point.first - triangle[0].first, point.second - triangle[0].second });
		pointLine.push_back({ point.first - triangle[2].first, point.second - triangle[2].second });
		for (int j = 0; j < 2; j++){
			if (cross(lines[j * 2], lines[j * 2 + 1]) * cross(lines[j * 2], pointLine[j]) <= 0) return false;
			if (cross(lines[j * 2 + 1], lines[j * 2]) * cross(lines[j * 2 + 1], pointLine[j]) <= 0) return false;
		}
		return true;
	}

	bool equal(pair<int, int> a, pair<int, int> b){
		return a.first == b.first && a.second == b.second;
	}

	int cross(pair<int, int> a, pair<int, int> b){
		return a.first * b.second - a.second * b.first;
	}
};