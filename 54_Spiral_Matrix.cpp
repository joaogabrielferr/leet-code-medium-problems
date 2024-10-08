class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        vector<char>dir = {'R','D','L','U'};
        int x = 0;

        auto cant_move = [&](int i,int j){
            if(i < 0 || i >= m || j < 0 || j >= n)return true;
            if(visited[i][j])return true;
            else return false;
            if(dir[x] == 'R' && (j + 1 >= n && i + 1 < m && visited[i + 1][j]))return true;
            if(dir[x] == 'D' && (i + 1 >= n && j - 1 >= 0 && visited[i][j - 1]))return true;
            if(dir[x] == 'L' && (j - 1 < 0 && i - 1 >= 0 && visited[i - 1][j]))return true;
            if(dir[x] == 'U' && visited[i - 1][j] && j + 1 < n && visited[i][j + 1])return true;
            return false;
        };

        int i = 0,j = 0;
        vector<int>ans;
        while(!cant_move(i,j)){
            visited[i][j] = true;
            ans.push_back(matrix[i][j]);
            if(dir[x] == 'R'){
                if(j + 1 >= n || visited[i][j + 1]){
                    x++;
                    i++;
                }else{
                    j++;
                }
            }else if(dir[x] == 'D'){
                if(i + 1 >= m || visited[i + 1][j]){
                    x++;
                    j--;
                }else{
                    i++;
                }
            }else if(dir[x] == 'L'){
                if(j - 1 < 0 || visited[i][j - 1]){
                    x++;
                    i--;
                }else{
                    j--;
                }
            }else if(dir[x] == 'U'){
                if(i - 1 < 0 || visited[i - 1][j]){
                    x = 0;
                    j++;
                }else{
                    i--;
                }
            }
        }

        return ans;


    }
};
