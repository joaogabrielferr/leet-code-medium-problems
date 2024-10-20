class Solution {


void step(int idx,vector<int>&nums,vector<int>v,vector<vector<int>>&ans){
    if(idx == nums.size()){
        ans.push_back(v);
        return;
    }
    step(idx + 1,nums,v,ans);
    v.push_back(nums[idx]);
    step(idx + 1,nums,v,ans);
}


public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int idx = 0;

        vector<vector<int>>ans;
        vector<int>v = {};

        step(idx,nums,v,ans);

        return ans;

    }
};
