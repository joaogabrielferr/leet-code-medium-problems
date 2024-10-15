class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int,vector<int>>pq;

        for(int i : nums){
            pq.push(i);
        }

        long long ans = 0;

        for(int i = 1;i<=k;i++){
            
            
            int x = pq.top();
            pq.pop();

            ans+=x;
            int y = ceil((double)x/3.0);
            pq.push(y);
        
        }

        return ans;

    }
};
