#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
#define tt int t; cin >> t; while(t--)
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define pll pair<long long,long long>
#define input(x) for(int i = 0; i < n; i++) cin >> x[i]
#define srt(x) sort(x.begin(), x.end())
#define fast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            int n=nums.size();
    vector<vector<int>>s;
    srt(nums);
    for(int i=0;i<n-2;i++){
        if(i>0&&nums[i]==nums[i-1])continue;
        for(int j=i+1, k=n-1 ;j<k ;){
            if(nums[i]+nums[j]+nums[k]==0){
                    s.pb({nums[i],nums[j],nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
            else if(nums[i]+nums[j]+nums[k]<0)j++;
            else k--;
        }
    }
    return s;
}
};