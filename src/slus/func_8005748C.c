#include "types.h"

extern u8* func_8002D53C(void);
extern s32 func_8002DF78(void);
extern s32 func_8002DFB0(void);
extern void func_8004FE6C(u8* self, s32 a1, s32 a2, s32 a3, s32 a4);
extern u16 D_80093F70;

void func_8005748C(u8* obj) {
    u8* p;
    u8* q;
    u32 i;
    u16 t;

    t = *(u16*)(obj + 0x14);
    if (t != 0) {
        do { // !FAKE: block fence keeps the byte in v1
            *(u16*)(obj + 0x14) = t - 1;
            obj[0x16]--;
        } while (0);
        if (((s8*)obj)[0x16] == 0) {
            obj[0x16] = 4;
            func_8004FE6C(obj, 1, 0x60, 0x60, 2);
        }
        if (!(func_8002DFB0() & 1)) {
            p = func_8002D53C();
            if (p != 0) {
                p[0] = 1;
                p[1] = 4;
                func_8002DF78();
                *(u16*)(p + 8) = D_80093F70 & 0xFFF;
                *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
                *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
            }
        }
        return;
    }
    i = 0;
    do {
        q = func_8002D53C();
        if (q != 0) {
            q[0] = 1;
            q[1] = 6;
            *(u16*)(q + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(q + 0xE) = *(u16*)(obj + 0xE);
            q[6] = i;
        }
        i++;
    } while (i < 0x10);
    obj[4]++;
}
