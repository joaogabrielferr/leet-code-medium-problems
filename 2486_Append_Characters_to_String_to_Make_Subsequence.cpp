class Solution {
public:
    int appendCharacters(string s, string t) {

      int sidx = 0,tidx = 0;

      while(tidx < t.size()){ 

        char current = t[tidx];
        bool found = 0;
        while(sidx < s.size()){
            
            if(s[sidx] == t[tidx]){
                tidx++;
                sidx++;
                found = 1;
                break;
            }
            sidx++;
        }

        if(!found){
            break;
        }
      }

      return t.size() - tidx;


    }
};
