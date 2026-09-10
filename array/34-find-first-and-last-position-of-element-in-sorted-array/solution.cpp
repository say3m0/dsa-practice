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
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it=lower_bound(nums.begin(),nums.end(),target);

        if(it!=nums.end()&& *it==target){
            int first_ele_idx=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            int last_ele_idx=upper_bound(nums.begin(),nums.end(),target)-nums.begin();

            return {first_ele_idx,last_ele_idx-1};
        }
        return {-1,-1};
    }
};