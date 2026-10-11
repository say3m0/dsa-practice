class Solution {
public:
    bool threeFibonacciSum(int n) {
        if (n % 2 != 0) {
            return false;
        }
        long long target = n / 2;
        long long a = 0, b = 1;
        if (target == 0 || target == 1) {
            return true;
        }
        while (b <= target) {
            if (b == target) {
                return true;
            }
            long long next = a + b;
            a = b;
            b = next;
        }
        return false;
    }
};