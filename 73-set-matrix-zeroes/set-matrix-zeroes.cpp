class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> r;
        set<int> c;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        } // <-- Missing brace was here

        for(int i : r)
            fill(matrix[i].begin(), matrix[i].end(), 0);

        for(int j : c){
            for(int i = 0; i < m; i++){
                matrix[i][j] = 0;
            }
        }
    }
};