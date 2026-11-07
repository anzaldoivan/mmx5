#include "types.h"

extern u8 D_8009A0A0[];
extern void* D_8007722C[];
extern void func_80017248(u8* obj);

void func_8004AE50(u8* obj) {
    s8* g = (s8*)D_8009A0A0;
    s32 flag;
    u8* p;
    s8 t;

    flag = (g[0xD3] != 0);
    if (g[0xD4] != 0) {
        flag = 1;
    }
    if (g[0x93] != 8) {
        flag = 1;
    }
    if (((s8*)obj)[2] != 0) {
        func_80017248(obj);
        p = *(u8**)(obj + 0x7C);
        *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
        *(u16*)(obj + 0xE) = *(u16*)(p + 0xE) + ((s8*)obj)[2] * 10;
        t = p[4];
        if (t == 3) {
            obj[4] = t;
        }
    }
    if (flag) {
        obj[4] = 3;
    }
    ((void (*)(u8*))D_8007722C[((s8*)obj)[4]])(obj);
}
