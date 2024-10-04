class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        sort(skill.begin(),skill.end());

        vector<pair<int,int>>teams;

        int idx1 = 0,idx2 = skill.size() - 1;
        while(idx1 < idx2){
            teams.push_back({skill[idx1++],skill[idx2--]});
        } 

        int x = teams[0].first + teams[0].second;
        long long ans = 0;
        for(auto &p : teams){
            if(p.first + p.second != x)return -1;
            ans += (p.first * p.second);
        }

        return ans;

    }
};
