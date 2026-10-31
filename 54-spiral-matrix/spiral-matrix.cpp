class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int total = m * n;
        vector<int> v;
        int top = 0, bottom = n - 1, left = 0, right = m - 1;

        while(v.size() < total){
            for(int i = left; i <= right && v.size() < total; i++)
                v.push_back(matrix[top][i]);
            top++;

            for(int i = top; i <= bottom && v.size() < total; i++)
                v.push_back(matrix[i][right]);
            right--;

            for(int i = right; i >= left && v.size() < total; i--)
                v.push_back(matrix[bottom][i]);
            bottom--;

            for(int i = bottom; i >= top && v.size() < total; i--)
                v.push_back(matrix[i][left]);
            left++;
        }
        return v;
    }
};