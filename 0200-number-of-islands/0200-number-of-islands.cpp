class Solution {
public:
void dfs(vector<vector<char>> &grid,int r,int c)
{
    int n = grid.size();
    int m = grid[0].size();

    grid[r][c] = '0';
    if(r >= 0 && c >=0 && r<n-1 && c<m && grid[r+1][c]=='1')
    dfs(grid , r+1 , c );

    if(r >= 0 && c > 0 && r<n && c<m && grid[r][c-1]=='1')
    dfs(grid , r , c-1 );

    if(r >= 0 && c >=0 && r<n && c<m-1 && grid[r][c+1]=='1')
    dfs(grid , r , c+1 );

    if(r > 0 && c >=0 && r<n && c<m && grid[r-1][c]=='1')
    dfs(grid , r-1 , c );

    return;
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c] == '1') {
                    count++;
                    dfs(grid, r, c);
                }
            }
        }
        return count;
    }
};