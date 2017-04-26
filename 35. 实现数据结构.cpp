class data{
private:
	vector<int> v;
	unordered_map<int, int> m; //<num, index>
public:
	data(){

	}

	void add(int x){
		v.push_back(x);
		m[x] = v.size() - 1;
	}

	void delete(int x){
		if (!search(x)) return;
		if (v.size() == 1) v.clear();
		else{
			int i = m[x];
			m[v.back()] = i;
			v[i] = v.back();
			v.pop_back();
			m.erase(x);
		}
	}

	bool search(int x){
		if (m.count(x)) return true;
		else return false;
	}

	int getRandom(){
		return v[rand() % v.size()];
	}
};