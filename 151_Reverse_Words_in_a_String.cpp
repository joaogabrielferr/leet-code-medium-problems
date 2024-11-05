class Solution {
public:
    string reverseWords(string s) {
        
        vector<string>words;

        string word = "";

        for(int i = 0;i<s.size();i++){
            if(s[i] == ' '){
                if(word != ""){
                    words.push_back(word);
                }
                word = "";
            }else{
                word.push_back(s[i]);
            }
        }
        if(word != "")words.push_back(word);
        
        string ans = "";
        for(int i = words.size() - 1;i>=1;i--){
            ans+=words[i] + " ";
        }
        if(words.size() > 1)ans+=words[0];
        else ans = words[0];

        return ans;

    }
};
