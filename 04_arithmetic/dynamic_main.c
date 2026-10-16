#include <stdio.h>
#include <dlfcn.h>

typedef double (*CalcFunc)(double, double);

int main(void)
{
    void *handle;
    CalcFunc functions[4];

    const char *names[] = {
        "add", "subtract", "multiply", "divide"
    };

    double a = 10.0;
    double b = 3.0;

    handle = dlopen("./lib/libcalc.so", RTLD_NOW);

    if (handle == NULL) {
        fprintf(stderr, "dlopen error: %s\n", dlerror());
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        dlerror();

        functions[i] = (CalcFunc)dlsym(handle, names[i]);

        const char *error = dlerror();

        if (error != NULL) {
            fprintf(stderr, "dlsym error: %s\n", error);
            dlclose(handle);
            return 1;
        }
    }

    printf("Add: %.2f\n", functions[0](a, b));
    printf("Subtract: %.2f\n", functions[1](a, b));
    printf("Multiply: %.2f\n", functions[2](a, b));

    if (b != 0.0)
        printf("Divide: %.2f\n", functions[3](a, b));
    else
        printf("Cannot divide by zero.\n");

    dlclose(handle);

    return 0;
}
