#include "types.h"

extern u8 D_8009A0A0[];
extern void* D_8007B5C0[];
extern int func_8002D6FC();

void func_8004F38C(u8* obj) {
    u8* g = D_8009A0A0;

    if ((s8)g[5] == 0x14) {
        func_8002D6FC(obj);
    } else {
        ((void (*)(u8*, u8*))D_8007B5C0[(s8)obj[4]])(obj, g);
    }
}
