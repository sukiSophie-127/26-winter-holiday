#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 20000 

struct BigInt {
    int d[MAXN];
    int len;

    // 1. 初始化
    BigInt(int v = 0) {
        memset(d, 0, sizeof(d));
        if (v == 0) {
            len = 1;
        } else {
            len = 0;
            while (v > 0) {
                d[len++] = v % 10;
                v /= 10;
            }
        }
    }

    // 2. 加法：BigInt = BigInt + BigInt
    void add(BigInt b) {
        len = max(len, b.len);
        int carry = 0;
        for (int i = 0; i < len || carry; i++) {
            if (i == len) len++;
            int cur = d[i] + b.d[i] + carry;
            d[i] = cur % 10;
            carry = cur / 10;
        }
        while (len > 1 && d[len - 1] == 0) len--;
    }

    // 3. 乘法：BigInt = BigInt * int
    void multiply(int v) {
        if (v == 0) {
            memset(d, 0, sizeof(d));
            len = 1;
            return;
        }
        int carry = 0;
        for (int i = 0; i < len || carry; i++) {
            if (i == len) len++;
            int cur = d[i] * v + carry;
            d[i] = cur % 10;
            carry = cur / 10;
        }
        while (len > 1 && d[len - 1] == 0) len--;
    }

    // 4. 大整数 * 大整数 
    void multiplyBig(BigInt b) {
        BigInt res(0);
        res.len = len + b.len; // 乘积的最大可能长度

        // 模拟竖式乘法
        for (int i = 0; i < len; i++) {
            if (d[i] == 0) continue; // 优化：当前位为0则跳过
            int carry = 0;
            for (int j = 0; j < b.len || carry; j++) {
                // res 中的位置为 i + j
                int cur = res.d[i + j] + d[i] * b.d[j] + carry;
                res.d[i + j] = cur % 10;
                carry = cur / 10;
            }
        }
        
        // 更新当前对象
        while (res.len > 1 && res.d[res.len - 1] == 0) res.len--;
        len = res.len;
        memcpy(d, res.d, sizeof(d));
    }

    // 5. 打印
    void print() {
        for (int i = len - 1; i >= 0; i--) {
            printf("%d", d[i]);
        }
        printf("\n");
    }
};

// 5. 阶乘函数
BigInt factorial(int n) {
    BigInt res(1);
    for (int i = 2; i <= n; i++) {
        res.multiply(i);
    }
    return res;
}

int main() {
    int n, a;
    // 示例：输入 n 求阶乘并统计数字 a 出现次数
    while (scanf("%d %d", &n, &a) != EOF) {
        BigInt res = factorial(n);
        
        int cnt = 0;
        for (int i = 0; i < res.len; i++) {
            if (res.d[i] == a) cnt++;
        }
        
        printf("Count of %d: %d\n", a, cnt);
        // res.print(); // 取消注释可查看完整阶乘结果
    }
    return 0;
}