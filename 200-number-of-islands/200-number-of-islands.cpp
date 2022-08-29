class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ctr=0;
        int offset[5] = {0, 1, 0, -1, 0};
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1') {
                    grid[i][j] = '0';
                    ctr++;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int k=0; k<4; k++){
                            int r = x + offset[k];
                            int c = y + offset[k+1];
                            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]=='1'){
                                grid[r][c] = '0';
                                q.push({r,c});
                            }
                        }
                    }
                }
            }
        }
        return ctr;
        
    }
};