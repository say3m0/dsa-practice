
class Solution {
public:
    int findMin(vector<int>& v) {
        int n = v.size();

        if(n == 1) return v[0];
        if(n == 2) return min(v[0], v[1]);

        int left = 0, right = n - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(mid == 0 && v[mid] < v[mid + 1])
                return v[mid];

            if(mid == n - 1 && v[mid] < v[mid - 1])
                return v[mid];

            if(mid > 0 && mid < n - 1 &&
               v[mid] < v[mid - 1] &&
               v[mid] < v[mid + 1])
                return v[mid];

            if(v[mid] >= v[0]) // Minimum at right side(important rotate sorted array property)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return v[0];
    }
};
