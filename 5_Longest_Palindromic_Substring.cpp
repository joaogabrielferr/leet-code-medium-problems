class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
       
        int l = 0,r = 0;
        int best_so_far = 1;

        auto check = [&](int a,int b){
            while(a >= 0 && b < n && s[a] == s[b]){
                if( (b - a) + 1 >= best_so_far){
                    best_so_far = (b - a) + 1;
                    l = a;
                    r = b;
                }
                a--;
                b++;
            }
        };

        for(int i = 0;i<n;i++){

            //i is the center of the palindrome
            
            //how much i can expand to the left and to the right while keeping i as the center
            int a = i;
            int b = i;
            
            check(a,b);

            //if palindrome has even length, then the center is between two indices, so expand from both instead of expanding from just one
            a = i,b = i + 1;
            check(a,b);

        }

        string ans = "";
        for(int i = l;i<=r;i++)ans.push_back(s[i]);

        return ans;

    }
};
