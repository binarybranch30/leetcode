class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can = -1, count = 0;
        for(int i : nums){
            if(count == 0) {
                can = i;
                count = 1;
            }
            else if(can == i) 
                count++;
            else 
                count--;
        }
        return can;
    }
};