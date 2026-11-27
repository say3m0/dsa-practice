class Solution {
public:
    int countPrimes(int n) {
        vector<bool>notPrime(n,false);

        if(n <= 2) return 0;

        for(int i=2;i*i<n;i++){
            if(notPrime[i]) continue;

            for(int j=i*i;j<n;j+=i){
                notPrime[j]=true;
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(!notPrime[i])cnt++;
        }
        return cnt;
    }
};