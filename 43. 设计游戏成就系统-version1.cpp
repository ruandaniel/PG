class Attribute{
public:
	string name;
	int amount;

	Attribute(string str, int n) : name(str), amount(n) {}

	bool attrSatisfy(int target){
		return amount >= target;
	}

	void changeAmount(int x){
		amount += x;
	}
};

class Player{
public:
	vector<Attribute*> attrs;

	unordered_map<string, Attribute*> attrsDic; //so we can access the attr by the name

	Player(vector<Attribute*> a = {}) : attrs(a) {
		for (auto i : a){
			attrsDic[i->name] = i;
		}
		this->print();
	}

	void addAttr(Attribute* attr){
		attrs.push_back(attr);
		attrsDic[attr->name] = attr;
		this->print();
	}

	void print(){
		for (auto i : attrs){
			cout << i->name << " = " << i->amount << " | ";
		}
		cout << endl;
	}
};

class Requirement{
public:
	vector<pair<string, int>> reqs;

	Requirement(vector<pair<string, int>> r = {}) : reqs(r) {};

	void addReq(pair<string, int> newReq){
		reqs.push_back(newReq);
	}

	bool reqSatisfy(Player *player){
		for (auto req : reqs){
			if (player->attrsDic.count(req.first) == 0) return false; //player doens't have this attribute
			Attribute *playerAttr = player->attrsDic[req.first];
			if (playerAttr->amount < req.second) return false;
		}
		return true;
	}
};

class Reward{
public:
	vector<pair<string, int>> rews;

	Reward(vector<pair<string, int>> r = {}) : rews(r) {};

	void addReq(pair<string, int> newRew){
		rews.push_back(newRew);
	}

	void assignReward(Player *player){
		for (auto rew : rews){
			Attribute *playerAttr = player->attrsDic[rew.first];
			playerAttr->changeAmount(rew.second);
		}
	}
};

class Achievement{
public:
	Requirement *myReq;
	Reward *myRew;
	unordered_set<Player*> unlockedList;

	Achievement(Requirement *a, Reward *b) : myReq(a), myRew(b){}

	void checkPlayer(Player *player){
		if (unlockedList.find(player) != unlockedList.end()) {
			cout << "This player has already unlocked this achievement!" << endl;
			return;
		}
		if (myReq->reqSatisfy(player)){
			cout << "Achievement unlocked successfully!" << endl;
			myRew->assignReward(player);
			cout << "Rewards assigned successfully!" << endl;
			unlockedList.insert(player);
			player->print();
		}
		else{
			cout << "Requirements not satisfied!" << endl;
		}
	}
};

void main(){

	Attribute *money = new Attribute("Money", 0);

	Attribute *level = new Attribute("Level", 1);

	Player *player = new Player(vector<Attribute*>({ money, level }));

	Requirement *achievement1Req = new Requirement(vector<pair<string, int>>({ { "Level", 2 } }));
	Reward *achievement1Rew = new Reward(vector<pair<string, int>>({ { "Money", 10 } }));
	Achievement *achievement1 = new Achievement(achievement1Req, achievement1Rew);

	Attribute *animal = new Attribute("Animal", 1);
	Attribute *HP = new Attribute("HP", 200);

	Requirement *achievement2Req = new Requirement(vector<pair<string, int>>({ { "Level", 2 }, { "Money", 3 }, { "Animal", 5 }, { "HP", 100 } }));
	Reward *achievement2Rew = new Reward(vector<pair<string, int>>({ { "Money", 10 }, { "Animal", 5 }, { "HP", 100 } }));
	Achievement *achievement2 = new Achievement(achievement2Req, achievement2Rew);

	achievement1->checkPlayer(player);
	achievement2->checkPlayer(player);
	player->attrsDic["Level"]->changeAmount(1);
	player->print();
	achievement1->checkPlayer(player);
	player->addAttr(animal);
	player->addAttr(HP);
	achievement2->checkPlayer(player);
	player->attrsDic["Animal"]->changeAmount(10);
	player->print();
	achievement2->checkPlayer(player);

	system("pause");
}