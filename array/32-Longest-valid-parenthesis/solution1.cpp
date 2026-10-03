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

int check(string &s){
    stack<int>st;
    int max_len=0;
    st.push(-1);
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(i);
        }else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }else{
                max_len=max(max_len,i-st.top());
            }
        }
    }
    return max_len;
}

int main() {
    fast;
    {
        string s;cin>>s;
        cout<<check(s)<<endl;
    }
    return 0;
}