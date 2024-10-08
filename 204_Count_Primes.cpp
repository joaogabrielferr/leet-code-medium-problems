class Solution {
public:
    int countPrimes(int n) {  
        //Sieve of Eratosthenes
        vector<bool>primes(n + 1,true);

        for(int i = 2;i*i<=n;i++){
            if(primes[i]){
                for(int j = i*i;j<=n;j+=i)primes[j] = false;
            }
        }

        int ans = 0;

        for(int i = 2;i<n;i++)if(primes[i])ans++;
        return ans;

        
    }
};
