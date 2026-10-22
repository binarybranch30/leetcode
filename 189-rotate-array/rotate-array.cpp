class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        if (k == 0) return;

        std::rotate(nums.begin(), nums.end() - k, nums.end());
    }
};