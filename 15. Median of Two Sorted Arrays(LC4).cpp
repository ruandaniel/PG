class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);  //make sure n1 is shorter
        int n1 = nums1.size(), n2 = nums2.size();
        //virtually add # between every two nums and head and tail
        if (n1 == 0) return double(nums2[(n2 - 1) / 2] + nums2[n2 / 2]) / 2;
        int left = 1, right = n1 * 2 + 1;
        while (left <= right){
            int cut1 = left + (right - left) / 2;
            int cut2 = n1 + n2 + 2 - cut1; 
            auto p1 = getSides(nums1, cut1);
            auto p2 = getSides(nums2, cut2);
            if (p1.first > p2.second) right = cut1 - 1;
            else if (p2.first > p1.second) left = cut1 + 1;
            else return double(max(p1.first, p2.first) + (min(p1.second, p2.second))) / 2;
        }
    }
    
    pair<int, int> getSides(vector<int> &nums, int pos){
        if (pos == 1) return {INT_MIN, nums[0]};
        else if (pos == nums.size() * 2 + 1) return {nums.back(), INT_MAX};
        if (pos % 2 == 0) return {nums[pos / 2 - 1], nums[pos / 2 - 1]};
        else return {nums[pos / 2 - 1], nums[(pos + 1) / 2 - 1]};
    }
};