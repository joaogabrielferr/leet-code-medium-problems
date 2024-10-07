class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        auto is_digit = [](char a){
            return a >= '1' && a <= '9';
        };

        map<char,bool>m;
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board.size();j++){
                
                if(is_digit(board[i][j])){
                    if(m.find(board[i][j]) != m.end()){
                        return false;
                    }
                    m[board[i][j]] = true;
                }

            }
            m.clear();
        }

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board.size();j++){
                if(is_digit(board[j][i])){
                    if(m.find(board[j][i]) != m.end()){
                    
                        return false;
                    }
                    m[board[j][i]] = true;
                }
            }
            m.clear();
        }

        for(int i = 0;i<=board.size() - 3;i+=3){

            for(int j = 0;j<=board.size() - 3;j+=3){
                
                for(int x = i;x<= i + 2;x++){
                    
                    for(int y = j;y<=j + 2;y++){

                        if(is_digit(board[x][y])){
                            
                            if(m.find(board[x][y]) != m.end())return false;
                            m[board[x][y]] = true;
                            
                        }

                    }

                }

                m.clear();

            }
            m.clear();
        }

        return true;




    }
};
