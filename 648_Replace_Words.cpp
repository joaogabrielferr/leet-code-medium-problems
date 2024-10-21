class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        vector<string>v;

        map<string,bool>m;

        for(string root : dictionary){
            m[root] = true;
        }

        string current = "";

        int idx = 0;
        while(idx < sentence.size()){
            if(sentence[idx] == ' '){
                v.push_back(current);
                current = "";
                idx++;
            }else{
                current+=sentence[idx];
                if(m.find(current) != m.end()){
                    v.push_back(current);
                    current = "";
                    while( idx < sentence.size() && sentence[idx] != ' '){
                        idx++;
                    }
                    idx++;
                }else idx++;
            }
        }

        if(current != "")v.push_back(current);

        string output = "";

        for(string s : v)output+=(s + " ");

        output.pop_back();

        return output;



        




    }
};
