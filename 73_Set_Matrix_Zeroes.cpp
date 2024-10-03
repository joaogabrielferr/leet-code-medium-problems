class Solution {

    
public:
    void setZeroes(vector<vector<int>>& m) {
        
        vector<bool>r(m.size(),false);
        vector<bool>c(m[0].size(),false);

        unordered_map<int,bool>row_set;
        unordered_map<int,bool>col_set;

        for(int i = 0;i<m.size();i++){
            for(int j = 0;j<m[i].size();j++){
                if(m[i][j] == 0){
                    r[i] = true;
                    c[j] = true;
                }
            }
        }

        for(int i = 0;i<m.size();i++){
            for(int j = 0;j<m[i].size();j++){
                if(r[i] && c[j]){
                    if(!row_set[i]){
                        row_set[i] = true;
                        for(int k = 0;k<m[i].size();k++)m[i][k] = 0;
                    }
                    if(!col_set[j]){
                        col_set[j] = true;
                        for(int k = 0;k<m.size();k++)m[k][j] = 0;
                    }
                }
            }
        }
    }
};
