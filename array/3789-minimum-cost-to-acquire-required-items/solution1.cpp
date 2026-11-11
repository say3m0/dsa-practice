class Solution {
public:
    long long minimumCost(int c1, int c2, int cB, int n1, int n2) {

        long long individual=1ll*c1*n1+1ll*c2*n2;
        long long full=1ll*cB*max(n1,n2);
        long long partial=1ll*cB*min(n1,n2);
        if(n1>n2) partial+=1LL*c1*(n1-n2);
        else partial+=1LL*c2*(n2-n1);

        return min({individual,full,partial});
    }
};