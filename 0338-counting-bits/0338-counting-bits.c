/*
Dynamic Programming:

Bài toán có thể chia nhỏ thành các bài toán con.

Các bài toán con này bị lặp lại nhiều lần.

Có sự phụ thuộc giữa các bài toán con.

result[i] = result[i/2] + (i%2); // dựa vào kết quả đã tính trước đó và xét bit cuối là 0 hay 1

Ví dụ: 10 = 1010; Xét 10/2 = 5 -> result[5] + 1010 & 0001 (xét thêm bit cuối là 0 hay 1)
*/

#include <stdlib.h>

int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int* result = (int*) malloc((n + 1) * sizeof(int));
    result[0] = 0;
    for (int i = 1; i <= n; i++) {
        result[i] = result[i >> 1] + (i & 1);
    }
    return result;
}
