#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F14DC_ovl07(u8* obj) {
    u8* p = *(u8**)(obj + 0x7C);
    s8 v;

    if (((s8*)p)[4] < 2) {
        v = ((s8*)p)[5];
        if (v == 5 || v == 0) {
            obj[3] = 0;
            if (p[0x47] == 3) {
                *(s32*)(obj + 0x8) = *(s32*)(p + 0x8);
                *(s32*)(obj + 0xC) = *(s32*)(p + 0xC);
                func_80017248(obj);
                func_8002D9EC(obj, 0x10, 0x10);
            }
            return;
        }
    }
    obj[4] = 2;
    obj[3] = 0;
}
