class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<pair<int,int>> pairs;
        unordered_map<long long, vector<int>> sums;
        vector<vector<int>> ans;

        for(int c = 1; c < n-1; c++){
            int b = c-1;

            for(int a = 0; a < b; a++){
                if(a > 0 && nums[a] == nums[a-1])
                    continue;

                long long sum = (long long)nums[a] + nums[b];
                sums[sum].push_back(pairs.size());
                pairs.push_back({nums[a], nums[b]});
            }

            for(int d = c+1; d < n; d++){
                if(d > c+1 && nums[d] == nums[d-1])
                    continue;

                long long need = (long long)target - nums[c] - nums[d];
                auto it = sums.find(need);

                if(it == sums.end())
                    continue;

                for(int idx : it->second){
                    auto [x, y] = pairs[idx];
                    ans.push_back({x, y, nums[c], nums[d]});
                }
            }
        }

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};