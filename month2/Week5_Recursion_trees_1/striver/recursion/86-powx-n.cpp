#include <iostream>
using namespace std;

// inside this instead of direct recursion which has O(n) TC, 
// but instead of ruducing the n by 1 we divided it by two and 
// changee x to x*x which significantly improve my TC to log(n)
class Solution {
public:
    void func(double x, long long n, double &ans){
        if(n == 0) return;
        if(n % 2 == 1){
            ans = ans * x;
        }
        func(x * x, n / 2, ans);
    }

    double myPow(double x, int n) {
        double ans = 1;
        long long N = n;

        if(N < 0){
            x = 1 / x;
            N = -N;
        }

        func(x, N, ans);
        return ans;
    }
};

int main() {
    Solution obj;

    // 🔥 Hardcoded inputs
    double x = 2.0;
    int n = 5;

    double result = obj.myPow(x, n);

    cout << "x = " << x << ", n = " << n << endl;
    cout << "Result: " << result << endl;

    return 0;
}