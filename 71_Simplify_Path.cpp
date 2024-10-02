class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string>s;

        int idx = 0;
        auto get_next_item = [&](){
            idx++;
            string next_dir = "";
            while(idx < path.size() && path[idx] != '/'){
                next_dir+=path[idx++];
            }

            while(idx < path.size() - 1 && path[idx] == '/' && path[idx + 1] == '/')idx++;
            
            

            return next_dir;
        };

        bool flag = false;
        while(!flag){

            string next_dir = get_next_item();
            if(next_dir == "" && idx >= path.size())break;
            if(next_dir == ".")continue;
            if(next_dir == ".."){
                if(!s.empty())s.pop();
            }else if(next_dir != "") s.push(next_dir);
        }

        vector<string>aux;
        while(!s.empty()){
            aux.push_back(s.top());
            s.pop();
        }
        reverse(aux.begin(),aux.end());
        string ans = "/";
        for(int i = 0;i<aux.size();i++){
            ans+=aux[i];
            if(i < aux.size() - 1)ans+="/";
            
        }


        return ans;        




    }
};
