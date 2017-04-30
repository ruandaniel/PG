import java.io.*;
import java.util.*;




/*
0. create attribute lvl, money
1. create player with lvl = 1, money = 0
2. create achievement1(lvl = 2)(rew: money + 10)
3. create attribute animal, HP
4. create achievement2(lvl = 3, money = 3, animal = 5, HP = 100)(rew: money + 10, animal + 5, HP + 100)
5. test achieve1
6. test achieve2
7. player lvl++;
8. test achieve1
9. player add attribute animal = 1, HP = 200
10. test achieve2
11. player animal += 10
12. test achieve2

*/

class Solution {
  public static void main(String[] args) {
        Player player1 = Game.createPlayer();
    
        LvlRequirement Lvl10 = new LvlRequirement(10);
        MoneyRequirement money100 = new MoneyRequirement(100);
        MoneyReward R_money1000 = new MoneyReward(1000);

    
        //第二种方法，直接新建requirement，自动继承requirement interface，重写interface方法    
        // if you want to create a new requirement, that is easy
        requirement animalreq = new requirement() {
            int animal = 10;
            @Override
            public boolean isSatisfied(Player player) {
                return player.annimal >= this.animal;
            }
        };


        List<requirement> firstReq = new ArrayList<requirement>();
        List<reward> firstReward = new ArrayList<reward>();

        firstReq.add(Lvl10);
        firstReq.add(money100);
        firstReward.add(R_money1000);


        Achievement firstAchievment = new Achievement(firstReq, firstReward);

        player1.isSatisified(firstAchievment);

        System.out.println(player1.Lvl);
        System.out.println(player1.money);

        player1.money = 100;
        player1.Lvl = 10;

        player1.isSatisified(firstAchievment);

        System.out.println(player1.Lvl);
        System.out.println(player1.money);
        

    
  }
}


// 第一种重新方法，直接定义新的requirement类，并且继承 requirement interface

class LvlRequirement implements requirement{

    int Lvl;
    public LvlRequirement(int Lvl){
        this.Lvl = Lvl;
    }
    @Override
    public boolean isSatisfied(Player player) {
        return player.Lvl >= this.Lvl;
    }
}


class MoneyRequirement implements requirement{

    int money;
    public MoneyRequirement(int money){
        this.money = money;
    }
    @Override
    public boolean isSatisfied(Player player) {
        return player.money >= this.money;
    }
}


class MoneyReward implements reward{
     int money;

    public MoneyReward(int money){
        this.money = money;
    }
    @Override
    public void update(Player player) {
        player.money = player.money + money;
    }
}

class Game {


   static List<Player> playerList = new ArrayList<Player>();


   public static Player createPlayer(){
       Player player = new Player();
       playerList.add(player);
       return player;
   }
   public static Achievement newAchievement(List<requirement> req, List<reward> rewards){

       return new Achievement(req,rewards);
   }


}


class Player{

    int Lvl;
    Set<Integer> achievement_id;
    int annimal;
    int money;


    public Player(){
        Lvl = 0;
        achievement_id = new HashSet<Integer>();
        annimal = 0;
        money = 0;

    }

    public  void  isSatisified(Achievement newAchievement){
        if(achievement_id.contains(newAchievement.unique_id)){
                return;
        }
        //judge
        boolean ifs = true;
        for(requirement i : newAchievement.req){
              if( !i.isSatisfied(this)){
                  ifs = false;
                  break;
              }
        }

        if(ifs == true){
            for(reward j : newAchievement.rewards){
                        j.update(this);
            }
        }

    }

}


class Achievement {

    List<requirement> req;
    List<reward> rewards;
    UUID unique_id;


    public Achievement(List<requirement> req, List<reward> rewards){
        this.unique_id= UUID.randomUUID();
        this.req = req;
        this.rewards =rewards;
    }

}



interface requirement {
    public boolean isSatisfied(Player player);
}

interface reward {
    public void update(Player player);
}


