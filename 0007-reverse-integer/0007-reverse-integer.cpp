class Solution {
public:
    int reverse(int x) {
        int reversed = 0;

    while (x != 0) {
        int pop = x % 10;
        
        // Check for integer overflow before updating 'reversed'.
        if(reversed>INT_MAX/10 || reversed<INT_MIN/10)return 0;

        reversed = reversed * 10 + pop;
        x /= 10;
    }

    return reversed;
    }
};