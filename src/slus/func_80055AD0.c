#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8003D29C(s32, s32);
extern u8* func_8002D0E4(void);
extern u8 D_8009A0A0[];

void func_80055AD0(u8* obj) {
    u8* g;
    u8* p;

    if (obj[0x72] & 8) {
        func_800171E8(obj, 1);
        g = D_8009A0A0;
        func_8003D29C(0x18, g[0x15]);
        p = func_8002D0E4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x24;
            p[2] = 0;
            {
                u8 t = obj[0x14];
                *(u8**)(p + 0x50) = obj;
                p[0x14] = t;
            }
        }
        {
            s32 v = *(s32*)(obj + 8);
            g[0xF5] = 1;
            *(s32*)(g + 8) = v;
        }
        obj[5]++;
    }
}
