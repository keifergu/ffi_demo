#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    int (*addFunc)(int, int);
    char *error;

    void *handle = dlopen("./lib.so", RTLD_NOW);

    if (handle == NULL)
    {
        printf("Open library %s error: %s\n", argv[1], dlerror());
        return -1;
    }

    addFunc = dlsym(handle, "add");

    if ((error = dlerror()) != NULL)
    {
        printf("Symbol  not found:%s\n", error);
        goto exit_runso;
    }

    int sum = addFunc(3, 2);

    printf("result: %d\n", sum);
exit_runso:
    dlclose(handle);
}