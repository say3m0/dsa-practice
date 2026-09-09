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
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        
        int ans = 0;
        int left = 0;
        int n = nums.size();
        
        for (auto [num, freq] : mp) {
            int right = n - left - freq;
            ans += left * freq * right;
            left += freq;
        }
        
        return ans;
    }
};