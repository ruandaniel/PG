class Solution {
public:
    //use HashSet, put all nums into it
    //second pass, for each num, enlarge to find longest range, erase these nums in set
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;
        unordered_set<int> s;
        int maxlen = 1;
        for (auto num : nums) s.insert(num);
        for (auto num : nums){
            int up = num+1;
            while (s.find(up) != s.end()){
                s.erase(up);
                up++;
            }
            int down = num-1;
            while (s.find(down) != s.end()){
                s.erase(down);
                down--;
            }
            s.erase(num);
            maxlen = max(maxlen, up - down - 1);
        }
        return maxlen;
    }
};

//O(n) time