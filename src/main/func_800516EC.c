#include "types.h"

extern u8 D_80091C44;
extern void (*D_8007B91C[])(u8*);

void func_800516EC(u8* obj) {
    if (D_80091C44 == 0) {
        obj[4]++;
    } else {
        D_8007B91C[((s8*)obj)[5]](obj);
    }
}
