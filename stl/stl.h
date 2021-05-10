#ifndef _STL_H_
#define _STL_H_

#include <iostream>
#include <vector>
#include <stdint.h>

namespace
{
     // 演示成功
     const int32_t STL_OK = 0;
     // 演示失败
     const int32_t STL_FAIL = -1;
}

// 封装演示stl的类
class PerformStl
{
    public:
        /**
         * @brief 构造函数
         */
        PerformStl();

        /**
         * @brief 析构函数
         */
        ~PerformStl();

        /**
         * @brief 演示vector
         *
         * @return STL_OK 成功；STL_FAIL 失败
         */ 
        int32_t PerformVector();
};

#endif
