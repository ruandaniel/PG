class Requirement;class Requirement;
class Reward;
class Achievement;

class Player{
public:
    int level;
    int money;
    int animal;
    unordered_set<int> finished;
    
    Player(int l = 1, int m = 0, int a = 0) : level(l), money(m), animal(a){}
    
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

class Achievement{
public:
    vector<Requirement*> reqs;
    vector<Reward*> rews;
    static int idGenerator;
    int id;
    
    Achievement(vector<Requirement*> a = {}, vector<Reward*> b = {}){
        reqs = a;
        rews = b;
        id = idGenerator++;
    }

    void addReq(Requirement* newReq){
    	reqs.push_back(newReq);
    }

    void addRew(Reward* newRew){
    	rews.push_back(newRew);
    }
    
    void check(Player* player){
        if (player->finished.find(id) != player->finished.end()){
            cout << "Achievement already finished" << endl;
            return;
        }
        for (auto i : this->reqs){
            if (!i->isSatisfied(player)){
                cout << "Requirement not satisfied" << endl;
                return;
            }
        }
        for (auto j : this->rews){
            j->assign(player);
        }
        cout << "Achievement finished and rewards assigned" << endl;
        player->finished.insert(id);
        
    }
};

int Achievement::idGenerator = 0;

void main(){

	LevelReq *lvl10 = new LevelReq(10);
	MoneyReq *money20 = new MoneyReq(20);
	MoneyRew *moneyRew20 = new MoneyRew(20);
	vector<Requirement*> r1({ lvl10 });
	vector<Reward*> w1({ moneyRew20 });
	Achievement *reachLvl10 = new Achievement(r1, w1);
	vector<Requirement*> r2({ lvl10, money20 });
	Achievement *ac1 = new Achievement(r2, w1);
	Player *player = new Player(1, 5, 0);

	reachLvl10->check(player);
	ac1->check(player);

	player->levelup(9);

	reachLvl10->check(player);
	ac1->check(player);
	ac1->check(player);

	system("pause");
}