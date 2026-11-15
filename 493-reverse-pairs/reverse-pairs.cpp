
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += j - (mid + 1);
        }

        return count;
    }

    void merge(vector<int>& nums, vector<int>& temp,
               int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        int k = low;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp[k++] = nums[left++];
            } else {
                temp[k++] = nums[right++];
            }
        }

        while (left <= mid) {
            temp[k++] = nums[left++];
        }

        while (right <= high) {
            temp[k++] = nums[right++];
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i];
        }
    }

    int mergeSort(vector<int>& nums, vector<int>& temp,
                  int low, int high) {
        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        int count = 0;

        count += mergeSort(nums, temp, low, mid);
        count += mergeSort(nums, temp, mid + 1, high);

        count += countPairs(nums, low, mid, high);

        merge(nums, temp, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return 0;

        vector<int> temp(n);

        return mergeSort(nums, temp, 0, n - 1);
    }
};
