class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(),citations.end());

        int ans = 0;

        for(int i = 1;i<=citations.size();i++){

            auto it = lower_bound(citations.begin(),citations.end(),i);
            if(it != citations.end()){
                int idx = distance(citations.begin(),it);
                if(citations.size() - idx >= i)ans = i;
            }
        }

        return ans;


    }
};
