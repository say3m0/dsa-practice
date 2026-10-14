class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num<sum) return "";
        int nines=sum/9;
        int rem=sum%9;
        string result(nines,'9');
        if(rem>0)result+='rem'
        else{
            result(num-result.size(),'0');
        }
        return result;
    }
};