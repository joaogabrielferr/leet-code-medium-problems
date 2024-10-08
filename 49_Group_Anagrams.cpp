class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<string>originals(strs.size());

        for(int i = 0;i<strs.size();i++){
            originals[i] = strs[i];
            sort(strs[i].begin(),strs[i].end());
        }

        map<string,int>m;
        vector<vector<string>>ans;
        
        for(int i = 0;i<strs.size();i++){

            if(m.find(strs[i]) == m.end()){
                ans.push_back(vector<string>());
                m[strs[i]] = ans.size() - 1;
            }
            ans[m[strs[i]]].push_back(originals[i]);
        }

        return ans;



    }
};
