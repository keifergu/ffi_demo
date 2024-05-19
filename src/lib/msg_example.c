#include <dlfcn.h>
#include <stdio.h>

typedef int (*fun_ptr)(char *, int);
typedef int (*fun_add_ptr)(int a, int b);
typedef int (*fun_register)(fun_ptr);

int callback(char *data, int res)
{
    printf("revieve: %s %d", data, res);
    return 1;
}

int main()
{
    void *handle = dlopen("./msg.so", RTLD_NOW);
    char *error;

    if (handle == NULL)
    {
        printf("Open library %s error: %s\n", "msg.so", dlerror());
        return -1;
    }

    fun_register funRegister = dlsym(handle, "regisiterCallback");

    if ((error = dlerror()) != NULL)
    {
        printf("Symbol  not found:%s\n", error);
        goto exit_runso;
    }

    funRegister(callback);

    fun_add_ptr funAdd = dlsym(handle, "triggerAdd");

    funAdd(2, 3);
    return 0;

exit_runso:
    dlclose(handle);
}