#include "types.h"
#include "mmx5/globals.h"

extern void* D_8007722C[];

void func_8004AE50(u8* obj) {
    s8* g = (s8*)g_Player;
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
        animate_object(obj);
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
