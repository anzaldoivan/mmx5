#include "types.h"
#include "addr.h"

extern s32 func_800171E8(u8* obj, s32 state);
extern void func_8002D89C(u8* obj);
extern u32* D_80098118;
extern u8 D_800C9310;
extern u8 D_800EFD14_ovl21[];

void func_800EF570_ovl21(u8* obj) {
    u32 i;
    u16* q;
    u32* t;
    u32* u;

    i = 0;
    if (((s8*)obj)[2] != 0) {
        *(u8**)(obj + 0x30) = D_800EFD14_ovl21;
        t = D_80098118;
        *(s32*)(obj + 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[0];
        *(s16*)(obj + 0x40) = t[0] >> 7;
        *(s16*)(obj + 0x42) = 0x7880;
        q = (u16*)(D_1F800028 + 0x402);
        do {
            *q = 0x8000;
            i++;
            q++;
        } while (i < 15);
        i = 0;
        q = (u16*)(D_1F800028 + 0x422);
        do {
            *q = 0x8000;
            i++;
            q++;
        } while (i < 15);
        i = 0;
        q = (u16*)(D_1F800028 + 0x442);
        do {
            *q = 0x8000;
            i++;
            q++;
        } while (i < 15);
        i = 0;
        q = (u16*)(D_1F800028 + 0x462);
        do {
            *q = 0x8000;
            i++;
            q++;
        } while (i < 15);
        D_800C9310 |= 1;
        func_800171E8(obj, ((s8*)obj)[2] - 1);
        obj[4] = 1;
        obj[0x16] = 0x10;
    } else {
        u = D_80098118;
        *(s32*)(obj + 0x3C) = (s32)D_1F800020.s32s + D_1F800020.s32s[1];
        *(s16*)(obj + 0x40) = u[1] >> 7;
        *(s16*)(obj + 0x42) = 0x784C;
        *(s16*)(obj + 0xE) = 0x78;
        *(s16*)(obj + 0xA) = 0x88;
        obj[0x47] = 0;
        obj[4] = 2;
        obj[0x16] = 0x11;
    }
    ((s8*)obj)[0x14] = -1;
    obj[0x15] = 0;
    func_8002D89C(obj);
}
