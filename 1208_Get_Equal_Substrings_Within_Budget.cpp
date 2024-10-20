class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.size();

        int ans = 0;
        int sum = 0;
        int l = -1;
        int length = 0;
        for(int i = 0;i<n;i++){
            
            int a = s[i] - '0';
            int b = t[i] - '0';
            sum += abs(a - b);
            length++;
            if(sum > maxCost){

                while(sum > maxCost){

                    l++;
                    int a = s[l] - '0';
                    int b = t[l] - '0';
                    sum -= abs(a - b);
                    length--;
                }
                ans = max(ans,length);
            }else{
                ans = max(ans,length);
            }
        }

        return ans;


    }
};
