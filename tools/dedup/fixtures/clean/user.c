/* Synthetic fixture: a null-based pointer is allowed. */
#include "types.h"
void f(void) {
    Alpha* p = 0;
    p->b = 1;
}
