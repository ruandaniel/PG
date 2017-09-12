struct ItemInfo{
	string name;
	int value;
	int maximum_stack_size;
	ItemInfo(string a, int b, int c) : name(a), value(b), maximum_stack_size(c){}
};

//min-heap version
class Solution{
public:
	int maxValue(int size, vector<string> items, vector<ItemInfo> item_infos){
		unordered_map<string, pair<int, int>> itemIf;
		for (auto i : item_infos){
			itemIf[i.name] = { i.value, i.maximum_stack_size };
		}
		priority_queue<int, vector<int>, greater<int>> pq; //min-heap
		sort(items.begin(), items.end());
		int i = 0, j = 0;
		for (; j <= items.size(); j++){
			if (j < items.size() && items[i] == items[j]) continue;
			int num = j - i;
			int stSize = itemIf[items[i]].second;
			while (num > 0){
				pq.push(min(stSize, num) * itemIf[items[i]].first);
				if (pq.size() > size) pq.pop();
				num -= stSize;
			}
			i = j;
		}
		int sum = 0;
		while (!pq.empty()){
			sum += pq.top();
			pq.pop();
		}
		return sum;
	}
};
//T: worst: O(nlog(size)) best: O(n/x *log(size))

//greedy version
class Solution{
public:
	int maxValue(int size, vector<string> items, vector<ItemInfo> item_infos){
		unordered_map<string, pair<int, int>> itemIf;
		for (auto i : item_infos){
			itemIf[i.name] = { i.value, i.maximum_stack_size };
		}
		priority_queue<int, vector<int>, greater<int>> pq; //min-heap
		sort(items.begin(), items.end());
		vector<int> slots;
		int i = 0, j = 0;
		for (; j <= items.size(); j++){
			if (j < items.size() && items[i] == items[j]) continue;
			int num = j - i;
			int stSize = itemIf[items[i]].second;
			while (num > 0){
				slots.push_back(min(stSize, num) * itemIf[items[i]].first);
				num -= stSize;
			}
			i = j;
		}
		int sum = 0;
		for (int k = 0; k < size; k++){
			int maxV = INT_MIN, index = -1;
			for (int l = 0; l < slots.size(); l++){
				if (slots[l] > maxV){
					maxV = slots[l];
					index = l;
				}
			}
			sum += maxV;
			slots[index] = 0;
		}
		return sum;
	}
};
// T: worst :O(n/x *size) 

void main(){
	ItemInfo a("diamond", 10, 5), b("ruby", 5, 5), c("armor", 25, 1);
	Solution s;
	auto t = s.maxValue(3,
	{ "diamond", "ruby", "armor", "diamond", "diamond", "ruby", "diamond", "diamond", "diamond", "diamond", "diamond", "armor" },
	{ a, b, c });
	cout << t << endl;
}

