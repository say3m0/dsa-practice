//BINARY SEARCH

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
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count=0;
        if(binarySearch(nums, nums[0]+diff) && binarySearch(nums, nums[0]+2*diff)){
                    count++;
        }
        for(int i=1;i<nums.size();i++){
            if( nums[i]!=nums[i-1]){
                if(binarySearch(nums, nums[i]+diff) && binarySearch(nums, nums[i]+2*diff)){
                    count++;
                }
            }
        }
        return count;
    }

    bool binarySearch(vector<int>&nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid] == target){
                return true;
            }
            else if (nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
};