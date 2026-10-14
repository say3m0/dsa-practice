class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res="";
        int total=0,cnt=0,ref=sum;
        if(sum<=num*9){
            for(int i=0;i<=num;i++){
                if(total==sum)break;
                int left=min(9,ref);
                total+=left;
                ref-=left;
                res+=to_string(left);
            }
            for(int i=res.size();i<num;i++)res+='0';
        }
        return res;
    }
};