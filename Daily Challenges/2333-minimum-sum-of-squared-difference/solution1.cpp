class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int>v(1e5+1,0);
        int k=k1+k2;
        for(int i =0;i<nums1.size();i++){
            int diff=abs(nums1[i]-nums2[i]);
            v[diff]++;
        }
        for(int i=1e5;i>0 && k>0;i--){
            int cnt=min(v[i],k);
            v[i]-=cnt;
            v[i-1]+=cnt;
            k-=cnt;
        }
        long long result=0;
        for(long long i=1;i<=1e5;i++){
            result+=(v[i]*i*i);
        }
        return result;
    }
};