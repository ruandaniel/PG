class Player{
public:
	int level;
	int money;
	int animal;
	unordered_set<Achievement*> finished;
	
	Player(int l = 1, int m = 0, int a = 0) : level(l), money(m), animal(a){}

	void satisfy(Achievement *achieve){
		if (finished.find(achieve) != finished.end()){
			cout << "Achievement already finished" << endl;
			return;
		}
		for (auto i : achieve->reqs){
			if (!i->isSatisfied(this)){
				cout << "Requirement not satisfied" << endl;
				return;
			}
		}
		for (auto j : achieve->rews){
			j->assign(this);
		}
		cout << "Rewards assigned" << endl;
		finished.insert(achieve);
	}
	
	void levelup(int x){
		level += x;
	}

	void moneyup(int x){
		money += x;
	}

	void animalup(int x){
		animal += x;
	}
};

class Achievement{
public:
	vector<Requirement*> reqs;
	vector<Reward*> rews;
	Achievement(vector<Requirement*> a, vector<Reward*> b) : reqs(a), rews(b){}
};

class Requirement{
public:
	virtual bool isSatisfied(Player *palyer) = 0;
};

class LevelReq : public Requirement{
public:
	int targetLevel;
	LevelReq(int x) : targetLevel(x){}
	bool isSatisfied(Player *player){
		return player->level >= targetLevel;
	}
};

class MoneyReq : public Requirement{
public:
	int targetMoney;
	MoneyReq(int x) : targetMoney(x){}
	bool isSatisfied(Player *player){
		return player->money >= targetMoney;
	}
};

class AnimalReq : public Requirement{
public:
	int targetAnimal;
	AnimalReq(int x) : targetAnimal(x){}
	bool isSatisfied(Player *player){
		return player->animal >= targetAnimal;
	}
};

class Reward{
public:
	virtual void assign(Player *palyer) = 0;
};

class LevelRew : public Reward{
public:
	int bonusLevel;
	LevelRew(int x) : bonusLevel(x){};
	void assign(Player *player){
		player->level += bonusLevel;
	}
};

class MoneyRew : public Reward{
public:
	int bonusMoney;
	MoneyRew(int x) : bonusMoney(x){};
	void assign(Player *player){
		player->money += bonusMoney;
	}
};

class AnimalRew : public Reward{
public:
	int bonusAnimal;
	AnimalRew(int x) : bonusAnimal(x){};
	void assign(Player *player){
		player->animal += bonusAnimal;
	}
};

void main(){

	LevelReq *lvl10 = new LevelReq(10);
	MoneyReq *lvl20 = new MoneyReq(20);

	

	system("pause");
}