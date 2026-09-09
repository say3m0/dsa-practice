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
        srt(nums);
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue; // skip duplicate
            unordered_set<int>s;
            for(int j=i+1 ; j<n; j++ ){
                int need=-(nums[i]+nums[j]);
                if(s.count(need)){
                    ans.pb({nums[i], need, nums[j]});
                    while (j + 1 < n && nums[j] == nums[j + 1]) j++; //skip second duplicate
                }
            s.insert(nums[j]);
            }
        }
        return ans;
    }
};