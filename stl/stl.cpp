#include "stl.h"

/** 构造函数 **/
PerformStl::PerformStl()
{}

/** 析构函数 **/
PerformStl::~PerformStl()
{}

/** 演示vector **/
int32_t PerformStl::PerformVector()
{
    /** vector的构造函数 **/
    std::vector<int32_t> first;               // 创建一个空的vector对象first
    std::vector<int32_t> second(5, 10);       // 创建一个初始化为5个元素均为10的vector对象second
    std::vector<int32_t> third(second.begin(), second.end());            // 直接通过对象second迭代到对象third
    std::vector<int32_t> fourth(third);       // 创建一个vector对象fourth，并对对象third进行拷贝

    int32_t myints[] = {10, 9, 8, 7, 6};
    std::vector<int32_t> fifth(myints, myints + sizeof(myints) / sizeof(int32_t));     // 通过一个数组进行初始化对象
    /** end 构造函数 **/
   
    /** vector的assign函数，给vector对象赋值 **/
    std::vector<int32_t>::iterator it;
    first.assign(7, 100);                     // 给first对象赋值7个相同的元素100
    for (it = first.begin(); it != first.end(); ++it)
    {
        if (*it != 100)
            return STL_FAIL;
    }
    first.clear();                            // 对象清空

    it = second.begin() + 1;
    first.assign(it, second.end() - 1);       // 给first对象赋值second对象的第二个值到倒数第二个元素的值
    if (first.size() != 3)
        return STL_FAIL;
    it = first.begin();
    if (*it != 10 || *(++it) != 10 || *(++it) != 10)
        return STL_FAIL;
    first.clear();                            // 对象清空

    first.assign(myints, myints + 5);         // 将上述的myints数组内的内容赋值给对象first
    it = first.begin();
    if (*it != 10 || *(++it) != 9 || *(++it) != 8 
					|| *(++it) != 7 || *(++it) != 6)
    {
        return STL_FAIL;
    }
    /** end assign **/

    /** vector的clear函数，在上述assign函数也讲过，将vector对象内容清空 **/
    first.clear();
    /** end clear **/

    /** vector的at函数，返回一个指向位置n的引用 **/
    std::vector<int32_t> vec(10);             // 声明一个vector对象vec，初始化为10为0
    for (uint32_t uIndex = 0; uIndex < vec.size(); ++uIndex)
        vec.at(uIndex) = uIndex;
    for (uint32_t uIndex = 0; uIndex < vec.size(); ++uIndex)
    {
        if (vec.at(uIndex) != uIndex)
            return STL_FAIL;
    }
    /** end at **/

    /** vector的size函数，返回对象中元素的个数 **/
    if (vec.size() != 10)
        return STL_FAIL;
    /** end size **/
  
    /** vector的capacity函数，返回对象中真实存储大小，这里需要注意与size的区别 **/
    if (vec.capacity() != 10)
        return STL_FAIL;
    /** end capacity **/

    /** vector的max_size函数，返回vector所能储存的最大的元素数目 **/
    vec.max_size();
    /**end max_size **/

    /** vector的push_back函数，向vector对象中尾部添加元素 **/
    for (uint32_t uIndex = 0; uIndex < 10; ++uIndex)
        first.push_back(uIndex);
    for (uint32_t uIndex = 0; uIndex < first.size(); ++uIndex)
    {
        if (first.at(uIndex) != uIndex)
            return STL_FAIL;
    }
    first.clear();
    /** end push_back **/
  
    /** vector的back函数，返回vector对象的最后一个元素的引用 **/
    first.push_back(10);
    while (first.back() != 0) {
        first.push_back(first.back() - 1);
    }
    if (first.size() != 11)
        return STL_FAIL;
    if (first.back() != 0)
        return STL_FAIL;
    first.clear();
    /** end back **/

    /** vector的begin函数，返回一个指向首元素的迭代器 **/
    it = vec.begin();
    if (*it != 0)
        return STL_FAIL;
    /** end begin **/
    
    /** vector的end函数，返回一个指向尾元素后面的一个元素的迭代器（这里需要区别于back函数） **/
    it = vec.end() - 1;
    if (*it != 9)
        return STL_FAIL;
    if (vec.back() != 9)
        return STL_FAIL;
    /** end end **/

    /*
     * C++11 语法
     * vector的cbegin函数，功能与begin函数相同，但不同的是，cbegin用变量接受
     * cbegin()的返回值时，变量的类型必须为const类型（且修饰指针指向的内容，
     * 其自身的值可以改变，但指向内容的值不允许改变，可用auto简化书写），只
     * 能进行遍历不能对vector中的元素进行修改。
     * 同理，cend函数也是如此。同时，cbegin与cend函数是C++11里面拥有的语法
     */
    for (uint32_t uIndex = 0; uIndex < 10; ++uIndex)
        first.push_back(uIndex);
    uint32_t uTemp = 0;
    for (auto it = first.cbegin(); it != first.cend(); ++it)
    {
        if (uTemp != *it)
            return STL_FAIL;
        ++uTemp;
    }
    /** end cbegin cend **/

    /*
     * C++11 语法
     * vector的crbegin函数，返回值是一个具有const属性的指向序列反向开头的
     * 反向迭代器，同理，crend函数返回一个const_reverse_iterator指向倒序
     * 序列的尾部。
     */
    for (auto it = first.crbegin(); it != first.crend(); ++it)
    {
        --uTemp;
        if (uTemp != *it)
            return STL_FAIL;
    }
    /** end crbegin crend **/

    /** C++11语法 vector的data函数，返回一个直接指向内存中存储vector元素位置的指针 **/
    int32_t *ptr = first.data();
    if (*ptr != 0 || *(++ptr) != 1 || *(++ptr) != 2
					|| *(++ptr) != 3 || *(++ptr) != 4 || *(++ptr) != 5
					|| *(++ptr) != 6 || *(++ptr) != 7 || *(++ptr) != 8
					|| *(++ptr) != 9)
    {
        return STL_FAIL;
    }
    /** end data **/ 

    return STL_OK;
}
