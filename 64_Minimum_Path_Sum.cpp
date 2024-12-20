class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>ans(m,vector<int>(n,0));

        ans[0][0] = grid[0][0];

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i + j == 0)continue;
                int left = INT_MAX,up = INT_MAX;

                if(j - 1 >=0)left = ans[i][j - 1];
                if(i - 1 >=0)up = ans[i - 1][j];

                ans[i][j] = grid[i][j] + min(left,up);
            }
        }

        return ans[m - 1][n - 1];

    }
};
