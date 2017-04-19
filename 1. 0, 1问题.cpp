//Binary Search, O(MlogN)
class Solution{
public:
	int leftMostOne(vector<string> matrix){
		int l = matrix[0].size();
		for (int i = 0; i < matrix.size(); i++){
			int t = BS(matrix[i]);
			l = min(l, t);
		}
		return l;
	}

	int BS(string s){
		int l = 0, r = s.size() - 1;
		while (l < r){
			int mid = l + (r - l) / 2;
			if (s[mid] == '0'){
				l = mid + 1;
			}
			else r = mid;
		}
		return l;
	}
};

//O(N)
class Solution{
public:
	int leftMostOne(vector<string> matrix){
		int l = matrix[0].size();
		for (int i = 0; i < matrix.size(); i++){
			while (l > 0 && matrix[i][l - 1] == '1') l--;
		}
		return l;
	}
};

//test case
void main(){
	Solution s;
	cout << s.leftMostOne({ "00001", "01111", "00011", "00111" }) << endl;

	system("pause");
}