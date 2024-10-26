class Solution {
public:
    string convert(string s, int numRows) {
    
    if(numRows == 1)return s;

    int n = s.size();

    int going_up = false;

    int current_row = 0;

    vector<string>rows(numRows);
    int idx = 0;
    for(char c : s){
        if(going_up){
            rows[current_row].push_back(c);
            current_row--;
            if(current_row <= 0){
                going_up = false;
                if(current_row < 0)current_row = 1;
            }
        }else{
            rows[current_row].push_back(c);
            current_row++;
            if(current_row == numRows){
                current_row-=2;
                going_up = true;
            }
        }
        idx++;
    }
    
    string ans = "";
    for(string i : rows)ans+=i;

    return ans;
    }
   
};
