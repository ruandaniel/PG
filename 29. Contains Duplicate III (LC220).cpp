//maintain a window using a set, BS (num - t) in set, check if it <= num + t 
//if window.size > k, delete nums[i-k]
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        for (int i = 0; i < nums.size(); i++){
            auto it = window.lower_bound(long(nums[i]) - t);
            if (it != window.end() && *it <= long(nums[i]) + t) return true;
            window.insert(nums[i]);
            if (i >= k) window.erase(nums[i - k]);
        }
        return false;
    }
};