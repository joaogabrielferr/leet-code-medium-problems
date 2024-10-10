class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int ans = INT_MAX;
        int sum = 0;

        int l = -1;

        for(int i = 0;i<nums.size();i++){

            sum+=nums[i];

            if(sum >= target){

                ans = min(ans,i - l);

                while(sum >= target){
                    l++;
                    sum-=nums[l];
                    if(sum >= target){
                        ans = min(ans,i - l);
                    }
                }
            }



        }

        if(ans == INT_MAX)return 0;
        return ans;



    }
};
