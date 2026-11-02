class Solution {
public:
    int minMoves2(vector<int>& v) {
        int ans=0;
        int median=nth_element(v.begin(),v.begin()+v.size()/2,v.end());
        for(int i=0;i<v.size();i++){
            ans+=(abs(v[median]-v[i]));
        }
        return ans;
    }
};