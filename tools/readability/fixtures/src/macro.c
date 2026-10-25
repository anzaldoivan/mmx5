/* planted: a macro with a statement body */
#define DO_TWICE(x) \
    do {            \
        x;          \
        x;          \
    } while (0)
