//O(nlogn)
//TODO: implement O(nlogk) with priority queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int>m;
        for(int i : nums)m[i]++;
        vector<pair<int,int>>v;
        for(auto &i:m)v.push_back(i);
        
        sort(v.begin(),v.end(),
        [](auto &a,auto &b){
            return a.second > b.second;
        });

        vector<int>ans;
        for(int i = 0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
