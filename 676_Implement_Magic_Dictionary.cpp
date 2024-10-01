
class MagicDictionary {

    vector<string>v;

public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        this->v = dictionary;
    }
    
    bool search(string searchWord) {

        for(string w : v){

            if(searchWord.size() != w.size())continue;

            int mismatch = 0;
            for(int i = 0;i<w.size();i++){
                if(w[i] != searchWord[i])mismatch++;
            }

            if(mismatch == 1)return true;
        }

        return false;


    }
};
