#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];
extern void* D_80077210[];

void func_8004ABA8(u8* obj) {
    u8* g = D_8009A0A0;
    s32 flag;
    s32 n;
    s32 s;
    u8* p;

    flag = ((s8*)g)[0xD3] != 0;
    if (((s8*)g)[0xD4] != 0) {
        flag = 1;
    }
    if (((s8*)g)[0x93] != 8) {
        flag = 1;
    }
    if (((s8*)g)[0x96] == 0x11) {
        flag = 1;
    }
    if (flag) {
        obj[4] = 3;
    }
    n = ((s8*)obj)[2];
    if (n != 0) {
        p = *(u8**)(obj + 0x7C);
        *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
        *(u16*)(obj + 0xE) = *(u16*)(p + 0xE) + n * 10;
        s = ((s8*)p)[4];
        if (s == 3) {
            obj[4] = s;
        } else if (((s8*)obj)[4] == 1 && s == 2) {
            func_800171E8(obj, 1);
            obj[4] = s;
        }
        func_80017248(obj);
    }
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    ((void (*)(u8*))D_80077210[((s8*)obj)[4]])(obj);
}
