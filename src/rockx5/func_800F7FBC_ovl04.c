#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern void func_8003240C(u8* a0);
extern void func_8003258C(u8* a0);
extern void func_800326BC(u8* a0);
extern s32 func_80032F70(u8* a0);
extern s8 D_8009A0A2;
extern u8 D_800D1C00[];

void func_800F7FBC_ovl04(u8* obj) {
    u8* p = *(u8**)(obj + 0x7C);
    s32 m;
    u8* g;

    *(u16*)(obj + 0xA) = *(u16*)(p + 0xA);
    *(u16*)(obj + 0xE) = *(u16*)(p + 0xE);
    if (D_8009A0A2 == 0) {
        if (func_80032F70(obj) != 0) {
            D_800D1C00[0x27] |= 1;
        }
    } else if ((s8)obj[2] < 0x10) {
        if (func_80031DD0(obj) != 0) {
            D_800D1C00[0x27] |= 1;
        }
    }
    func_8003240C(obj);
    func_800326BC(obj);
    if ((s8)p[2] == 0x10) {
        func_8003258C(obj);
    }
    g = D_800D1C00;
    if ((s8)p[2] >= 0x10) {
        m = g[0x2A] & 8;
    } else {
        m = g[0x2A] & 4;
    }
    if (m != 0) {
        obj[4]++;
    }
}
