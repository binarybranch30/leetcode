class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<long long, set<pair<int,int>>> sums;
        set<vector<int>> unique;

        for(int c = 1; c < n-1; c++){
            int b = c-1;

            for(int a = 0; a < b; a++){
                long long sum = (long long)nums[a] + nums[b];
                sums[sum].insert({nums[a], nums[b]});
            }

            for(int d = c+1; d < n; d++){
                long long need = (long long)target - nums[c] - nums[d];

                auto it = sums.find(need);
                if(it != sums.end()){
                    for(auto [x, y] : it->second)
                        unique.insert({x, y, nums[c], nums[d]});
                }
            }
        }

        return vector<vector<int>>(unique.begin(), unique.end());
    }
};