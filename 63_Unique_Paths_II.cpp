class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        

        int m = g.size();
        int n = g[0].size();
        
        if(g[0][0])return 0;

        //unecessary check but my solution runs 5ms faster if i keep it here lol
        if(m == 1 && n == 1){
            if(g[0][0])return 0;
            return 1;
        }

        
        vector<vector<int>>ans(m,vector<int>(n,0));

        ans[0][0] = 1;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i + j == 0)continue;
                if(!g[i][j]){
                    
                    int left = 0,top = 0;
                    if(j - 1 >= 0){
                        left = ans[i][j - 1];
                    }
                    if(i - 1 >= 0){
                        top = ans[i - 1][j];
                    }

                    ans[i][j] = left + top;
                }
            }
        }

        return ans[m - 1][n - 1];










    }
};
