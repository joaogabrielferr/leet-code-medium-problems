class Solution {
public:
    void count(int n,int opened,int closed,string current,vector<string>&ans){
        if(opened == n && closed == n){
            ans.push_back(current);
            return;
        }

        int sum = 0;
        bool added = false;
        if(opened < n){
            current += "(";
            added = true;
            count(n,opened + 1,closed,current,ans);
        }
        if(closed < n && closed < opened){
            if(added)current.pop_back();
            current += ")";
            count(n,opened,closed + 1,current,ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        
        vector<string>ans;
        count(n,1,0,"(",ans);

        return ans;

    }
};
