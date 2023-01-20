# My_Vector

    该程序是一个支持迭代器访问的简易Vector  
    该程序创建于2023.1.20  
    项目提供了三个源码文件  
    vector的实现 "_vector.hpp"
    自定义迭代器的实现 "_iterator.hpp"
    测试程序"test.cpp"  
   
## 类接口
#### _vector
    支持大括号初始化的构造函数(具有推导指引)
    用于迭代器访问的begin() end()
    用于判断容器是否为空的empty()
    用于访问的at()
    用于插入数据的push_back()
    用于删除数据的pop_back()
    返回当前已插入的数据个数size()
    返回最大可用长度max_size()
    
#### _iterator
    重载的各种运算符
  
详细说明请参阅代码注释(机翻英语......)

