class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int CSum = 0, MaxSum = INT_MIN;
        for(int i : nums){
            CSum += i;
            MaxSum = max(CSum , MaxSum);
            if(CSum < 0)
                CSum = 0;
        }
        return MaxSum;
    }
};