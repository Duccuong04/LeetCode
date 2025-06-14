/*
 * Leo cầu thang n bậc, mỗi bước chỉ leo 1 hoặc 2 bậc
 * Sử dụng quy hoạch động, tương tự như bài toán dãy số Fibonacci
 * Số cách để đến bậc n = (số cách đến bậc n-1) + (số cách đến bậc n-2)
 * f(n) = f(n-1) + f(n-2)
*/

int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1; // f(1)
    int b = 2; // f(2)
    for (int i = 3; i <= n; ++i) {
        int temp = b; //   f(2)
        b = a + b;    //   f(3) = f(2) + f(1)
        a = temp;     //   f(2)
    }
    return b; // chính là f(n)
}