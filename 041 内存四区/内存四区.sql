内存四区 
 1 程序运行前：
   1.1代码区
    1.1.1共享 只读
   1.2数据区
    1.2.1静态变量、全局变量、常量
    1.2.2已初始化 data
    1.2.3未初始化 bss
  
  2 程序运行后：
   2.1 栈区
     2.1.1 先进后出
     2.1.2 编译器观念里数据开辟 释放
     2.1.3 容量有限，不要将大量数据开辟到栈区
   2.2 堆区
     2.2.1 容量远大于栈区
     2.2.2 程序员手动开辟空间，手动释放
        malloc free
  3 栈区注意
    不要返回局部变量的地址，局部变量在函数执行完成后自动释放，再次操作就是非法操作。
  4 堆区 
    4.1 利用malloc将数据创建到堆区
    4.2 利用free释放
    4.3 堆区注意：
      如果主调函数中，一个空指针分配内存，则被调函数中，利用同级指针是分配失败的。
      解决方式：利用高级指针修饰低级指针
    