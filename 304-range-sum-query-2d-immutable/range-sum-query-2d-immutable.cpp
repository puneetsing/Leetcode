class NumMatrix {
public:
    vector<vector<int>>matrix2;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();
        matrix2.resize(rows+1,vector<int>(col+1,0));
        for(int i =1;i<=rows;i++){
            for(int j= 1;j<= col;j++){
                matrix2[i][j] = matrix[i-1][j-1] + matrix2[i-1][j] + matrix2[i][j-1] - matrix2[i-1][j-1]; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        return matrix2[row2][col2] - matrix2[row1-1][col2] - matrix2[row2][col1-1] + matrix2[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */