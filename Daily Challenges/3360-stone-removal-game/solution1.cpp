class Solution {
public:
    bool canAliceWin(int n) {
        int j=10;
        while(n-j>=0){
            n-=j;
            j--;
        }
        if(j%2)return true;
        return false;
    }
};