class Solution {
public:
    //maintain a window to store indexes, each time check the front 
    //when add a new one, from the back, delete all indexes that num smaller than the new one, because it will never be a max of a window
    //so that window is decreasing order, max if the front
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k > nums.size() || k == 0) return {};
        list<int> window;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            while (!window.empty() && nums[window.back()] < nums[i]){
                window.pop_back();
            }
            window.push_back(i);
            if (i - window.front() >= k) window.pop_front();
            if (i >= k - 1) res.push_back(nums[window.front()]);
        }
        return res;
    }
};