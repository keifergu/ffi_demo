#include <stdio.h>

typedef int (*fun_ptr)(char *, int);

fun_ptr global_callback;

void regisiterCallback(fun_ptr func)
{
    printf("called register: %p\n", func);
    global_callback = func;
}

void triggerAdd(int a, int b)
{
    printf("called add");
    global_callback("add", a + b);
}
