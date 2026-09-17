class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix[0].size();
        int n=matrix.size();
        vector<int>ans;
        int left=0,right=m-1,top=0,down=n-1;
        while(left<=right && top<=down){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=down;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(down>=top){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[down][i]);
            }
            down--;
        }
            if(left<=right){
            for(int i=down;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        }
        return ans;
    }
};