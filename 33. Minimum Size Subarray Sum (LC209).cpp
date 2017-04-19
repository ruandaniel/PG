class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (s == 0 || nums.empty()) return 0;
        int i = 0, j = 0, cur = 0;
        int res = INT_MAX;
        while (j < nums.size()){
            cur += nums[j];
            if (cur >= s){
                while(cur - nums[i] >= s){
                    cur -= nums[i];
                    i++;
                }
                res = min(res, j - i + 1);
            }
            j++;
        }
        return res == INT_MAX? 0 : res;
    }
};