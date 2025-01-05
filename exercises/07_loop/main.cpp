#include "../exercise.h"

// TODO: 改正函数实现，实现正确的缓存优化斐波那契计算
// THINk: 这个函数是一个纯函数（pure function）吗？
// READ: 纯函数 <https://zh.wikipedia.org/wiki/%E7%BA%AF%E5%87%BD%E6%95%B0>
static unsigned long long fibonacci(int i) {
    // TODO: 为缓存设置正确的初始值
    static unsigned long long cache[96]{0,1}, cached = 2;
    // TODO: 设置正确的循环条件
    for (; cached <= (unsigned long long)i; ++cached) {
     
        cache[cached] = cache[cached - 1] + cache[cached - 2];
    }
    return cache[i];
}

/*
 * 纯函数
 * 在相同的输入条件下，总是返回相同的输出值，并且没有任何副作用的函数。
 * 副作用是指对函数外部环境造成任何改变，比如修改全局变量、修改传入参数等
 * 
*/

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    ASSERT(fibonacci(0) == 0, "fibonacci(0) should be 0");
    ASSERT(fibonacci(1) == 1, "fibonacci(1) should be 1");
    ASSERT(fibonacci(2) == 1, "fibonacci(2) should be 1");
    ASSERT(fibonacci(3) == 2, "fibonacci(3) should be 2");
    ASSERT(fibonacci(10) == 55, "fibonacci(10) should be 55");

    auto fib90 = fibonacci(90);
    std::cout << "fibonacci(90) = " << fib90 << std::endl;
    ASSERT(fib90 == 2880067194370816120, "fibonacci(90) should be 2880067194370816120");
    return 0;
}
