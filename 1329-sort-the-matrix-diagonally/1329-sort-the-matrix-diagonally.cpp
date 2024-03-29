class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i=n-1; i>=0; --i){
            vector<int> diag;
            for(int x = i, y = 0; x<n and y<m; x++, y++){
                diag.push_back(mat[y][x]);
            }
            sort(diag.begin(), diag.end());
            for(int x = i, y = 0, k=0; x<n and y<m; x++, y++, k++){
                mat[y][x] = diag[k];
            }
        }
        for(int i=1; i<m; i++){
            vector<int> diag;
            for(int x = i, y = 0; x<m and y<n; x++, y++){
                diag.push_back(mat[x][y]);
            }
            sort(diag.begin(), diag.end());
            for(int x = i, y = 0, k=0; x<m and y<n; x++, y++, k++){
                mat[x][y] = diag[k];
            }
        }
        return mat;
    }
};