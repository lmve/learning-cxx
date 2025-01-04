#include "../exercise.h"

// READ: `static` 关键字 <https://zh.cppreference.com/w/cpp/language/storage_duration>
// THINK: 这个函数的两个 `static` 各自的作用是什么？
static int func(int param) {  // 1
    static int static_ = param; // 2
    std::cout << "static_ = " << static_ << std::endl;
    return static_++;
}

/*
 * 1. 函数定义前，表示该函数具有静态链接属性，
 *    函数 func 只能在定义它的文件中调用而不能被其他文件中的代码所调用，
 *    有助于避免命名冲突和减少编译后的符号表大小

 * 2. 变量前表示这个变量具有静态存储期 
 *    被 static 关键字描述的变量在第一次被初始化后，
 *    其值会在函数的调用之间保持不变，直到程序结束

 * static 在这里分别用于控制函数的作用域和变量的生命周期
*/

int main(int argc, char **argv) {
    // TODO: 将下列 `?` 替换为正确的数字
    ASSERT(func(5) == 5, "static variable value incorrect");
    ASSERT(func(4) == 6, "static variable value incorrect");
    ASSERT(func(3) == 7, "static variable value incorrect");
    ASSERT(func(2) == 8, "static variable value incorrect");
    ASSERT(func(1) == 9, "static variable value incorrect");
    return 0;
}
