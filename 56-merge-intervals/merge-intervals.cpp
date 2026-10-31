class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(vector<int> i : intervals){
            if(i == intervals[0])
                continue;
            if(ans.back()[1] >= i[0]){
                vector<int> start = ans.back();
                ans.pop_back();
                ans.push_back({start[0] , max(i[1] , start[1])});
            }
            else
                ans.push_back(i);
        }
        return ans;
    }
};