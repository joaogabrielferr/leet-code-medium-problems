class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),[](int x,int y){
            return x > y;
        });

        int c = 1;
        long long ans = happiness[0];
        if(k == 1)return ans;
        while(c <= k - 1){
            
            if(happiness[c] - c <= 0)break;
            ans += (happiness[c] - c);
            c++;
        }

        return ans;

    }
};
