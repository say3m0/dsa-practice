class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int prod=1,gcd=0,lcm=1;
            for(int j=i;j<n;j++){
                prod*=nums[j];
                gcd=__gcd(gcd,nums[j]);
                lcm=__lcm(lcm,nums[j]);
                if(prod==gcd*lcm){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};