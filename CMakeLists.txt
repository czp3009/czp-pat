cmake_minimum_required(VERSION 3.17)
project(PAT C)

set(CMAKE_C_STANDARD 11)

add_executable(BasicLevel_1001 "BasicLevel/1001 害死人不偿命的(3n+1)猜想.c")

add_executable(BasicLevel_1002 "BasicLevel/1002 写出这个数.c")

add_executable(BasicLevel_1003 "BasicLevel/1003 我要通过.c")

add_executable(BasicLevel_1004 "BasicLevel/1004 成绩排名.c")

add_executable(BasicLevel_1005 "BasicLevel/1005 继续(3n+1)猜想.c")

add_executable(BasicLevel_1006 "BasicLevel/1006 换个格式输出整数.c")

add_executable(BasicLevel_1007 "BasicLevel/1007 素数对猜想.c")
target_link_libraries(BasicLevel_1007 m)

add_executable(BasicLevel_1008 "BasicLevel/1008 数组元素循环右移问题.c")

add_executable(BasicLevel_1009 "BasicLevel/1009 说反话.c")
