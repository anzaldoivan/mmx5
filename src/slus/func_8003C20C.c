#include "types.h"

extern void* func_8003D4C0(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern void func_8003CEAC(s32 arg0, s32 arg1, s32 arg2);
extern void func_8003B65C(u8* arg0);
extern void func_8003CD08(u8* obj);
extern void func_8003A670(u8* arg0);
extern s8 D_800D1C00[];
extern u16 D_80074878[];
extern u8 D_8009A1F8[];

void func_8003C20C(u8* arg0) {
    s8* p = D_800D1C00;
    u8* q;

    switch (p[0xC]) {
    case 6:
        *(u16*)(arg0 + 0xE) = 0x90B;
        break;
    case 9 ... 10:
        *(u16*)(arg0 + 0xE) = 0x18B;
        break;
    case 12:
        if (p[0xD] == 0) {
            *(u16*)(arg0 + 0xE) = D_80074878[p[0x1D]];
        } else {
            *(u16*)(arg0 + 0xE) = 0x1CB;
        }
        break;
    }
    q = (u8*)D_800D1C00;
    arg0[0xFA] = q[0x49];
    *(s32*)(arg0 + 0xFC) = ((D_800D1C00_f88_t*)q)->f88[arg0[0xFA]];
    if (arg0[0xFA] == 3) {
        arg0[0xC9] = 0;
        arg0[0x14A] = 0;
        func_8003D4C0(1, 0x1B, 8, 0);
        func_8003D4C0(1, 0x1B, 9, 0);
        func_8003CEAC(0x49, 0x14, 1);
    } else {
        arg0[0xC9] = q[0x4C];
        arg0[0x14A] = q[0x4B];
    }
    func_8003B65C(arg0);
    if (((s8*)arg0)[2] != 0) {
        *(u16*)(arg0 + 0xE) -= 1;
    }
    *(u16*)(arg0 + 0xC) = 0;
    p[0x1C] = 0;
    func_8003CD08(arg0);
    func_8003A670(arg0);
    D_8009A1F8[0x44] = 1;
    D_8009A1F8[0x98] = 1;
    D_8009A1F8[0xEC] = 1;
}
