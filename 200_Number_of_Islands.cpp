//start dfs from each position with value '1', all positions hit with that dfs call with be an island

class Solution {

    void dfs(vector<vector<char>>&grid,vector<vector<bool>>&visited,int i,int j){

        
        visited[i][j] = true;

        if(i - 1 >= 0 && grid[i-1][j] == '1' && !visited[i-1][j] ){
            dfs(grid,visited,i-1,j);
        }
        if(j - 1 >= 0 && grid[i][j - 1] == '1' && !visited[i][j - 1]){
            dfs(grid,visited,i,j-1);
        }
        if(i + 1 < grid.size() && grid[i+1][j] == '1'  && !visited[i+1][j]){
            dfs(grid,visited,i+1,j);
        }
        if(j + 1 < grid[0].size() && grid[i][j+1] == '1' && !visited[i][j+1]){
            dfs(grid,visited,i,j+1);
        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        int ans = 0;

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    ans++;
                    dfs(grid,visited,i,j);
                }
            }
        }

        return ans;

    }
};
