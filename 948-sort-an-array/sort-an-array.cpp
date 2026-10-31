class Solution {
public:
    void sortt(vector<int>& no, int start, int end){
        if(start > end)
            return;
        int randomIndex = start + rand() % (end - start + 1);
        swap(no[start], no[randomIndex]);
        int pivot = no[start];
        int s = start;
        for(int i = start+1; i <= end; i++){
            if(no[i] < pivot)
                swap(no[++s], no[i]);
        }
        swap(no[start], no[s]);
        sortt(no, start, s-1);
        sortt(no, s+1, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        sortt(nums ,0 , nums.size() - 1 );
        return nums;
    }
};