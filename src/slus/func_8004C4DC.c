#include "types.h"
#include "addr.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_80017348(u8* a0, s32 a1, s32 a2);
extern void func_8002D6FC(u8* obj);
extern u8 D_8007B3D8[];
extern u8 D_8009A0A0[];

void func_8004C4DC(u8* arg0) {
    u8* g = D_8009A0A0;
    u8* s;
    u8* t;
    s32 flag;
    s32 n;

    flag = FX(g, s8, 0x5C) == 0;
    if (FX(g, s8, 0xD3) != 0) {
        flag = 1;
    }
    if (FX(g, u8, 0x17) != 0x60) {
        flag = 1;
    }
    if (flag != 0) {
        func_8002D6FC(arg0);
        return;
    }
    if (FX(arg0, s8, 0x4) == 0) {
        FX(arg0, u8, 0x3) = 1;
        s = D_1F80001C.bytes;
        FX(arg0, u8*, 0x3C) = s + FX(s, s32, 0x28);
        t = D_1F800014;
        n = FX(t, s32, 0x14);
        FX(arg0, u8*, 0x30) = D_8007B3D8;
        FX(arg0, s16, 0x40) = 0x560;
        FX(arg0, s16, 0x42) = 0x7804;
        FX(arg0, u8, 0x16) = 0;
        FX(arg0, u8*, 0x38) = t + n;
        FX(arg0, u8, 0x14) = FX(g, u8, 0x14);
        FX(arg0, u8, 0x15) = FX(g, u8, 0x15);
        func_800171E8(arg0, 4);
        FX(arg0, u8, 0x48) = 0xFF;
        FX(arg0, u8, 0x49) = 0;
        func_80017348(arg0, 0x140, 0x60);
        FX(arg0, u8, 0x4)++;
    } else {
        func_80017248(arg0);
    }
    FX(arg0, s16, 0xA) = FX(g, s16, 0xA);
    FX(arg0, s16, 0xE) = FX(g, s16, 0xE);
}
