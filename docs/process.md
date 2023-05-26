# 进度汇报

> 尽量在一个有限的时间里完成这部分的开发

- 5/25
    - 完成了关于 format 部分的代码，这部分在这个项目中并非占有主要位置，但是这个部分是后期进行转化的关键，
    之后如果需要输出这两个方面的内容就需要从这两个接口进入，这部分应该还可以开发一个接口的部分，通过这个
    接口提供一个可以进行 format 的方法，进而得到一种更好的进行格式化的方式。
    - 这里在实现两个 format 的部分分别使用两种不同的方式，在 int 部分通过数组的遍历实现相关部分的内容，但
    是在 float 的部分通过 sprinf 的接口进行字符数组的转化，从而从代码层面上更加优雅的实现了这个过程(主要是
    如果使用这个过程对于 float 类型进行转化，可能涉及到一些类型转化的问题，使用二进制数直接进行类型转换的
    工作我还是不想再这里进行的，想想就感觉头大), 之后的开放接口的方式我想也会通过这种方式进行实现，通过给
    用户开放一个进行遍历的接口，来进行对于可展示序列的构建工作，这样就可以通过一个统一的 char** 的类型接口
    来调用不同的类型的转化工作以及完成输出的任务