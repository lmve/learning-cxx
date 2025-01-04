#include "../exercise.h"

unsigned long long fibonacci(auto i) {
    switch (i) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return fibonacci(i - 1) + fibonacci(i - 2);
    }
}

int main(int argc, char **argv) {
    auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    auto ANS_N = 90;
    auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}


/*
 * 1. constexpr 修饰的函数时函数体尽量只包含一个 return 语句，包含多个可能会触发编译错误
      函数体可以包含其他语句，但是不能是运行期的语句，
      编译器会将 constexpr 函数视为内联函数，在编译时若能求出其值，则会把函数调用替换成结果值
   2. 在类的构造函数中使用 constexpr 关键字，保证传递给该构造函数的所有参数都是 constexpr, 
      产生的对象的所有成员都是 constexpr, 该对象只可用于 constexpr 的场合。
      cosntexpr 的函数体必须为空，所有的成员变量的初始化都放到初始化列表中。 

 * * cosnt 与 constexpr 的区别
   1. const 变量的初始化可以延迟到运行时，而 cosntexpr 变量必须在编译时进行初始化，
      所有 constexor 变量均为常量，因此必须使用常量表达式初始化
   2. 在 constexpr 声明中如果定义了指针，限定符仅对指针有效， 与指针所指对象无关
*/