#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_800171E8(u8* obj, s32 state);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern u8 D_800FE744_ovl28[];
extern u8 D_800FE748_ovl28[];

void func_800F7D1C_ovl28(u8* p) {
    func_800317B8(p);
    if (func_80031DD0(p) < 0) {
        func_8004FD24(p);
        p[4] = 2;
        return;
    }
    switch (*(s8*)(p + 5)) {
    case 0:
        if (++*(s32*)(p + 0x8C) == 3) {
            if (p[0x15] != 0) {
                *(s32*)(p + 0x20) = 0x40000;
            } else {
                *(s32*)(p + 0x20) = -0x40000;
            }
            p[5]++;
        }
        break;
    case 1:
        if (++*(s32*)(p + 0x8C) == 12) {
            func_800171E8(p, 12);
            *(u8**)(p + 0x50) = D_800FE744_ovl28;
            *(u8**)(p + 0x54) = D_800FE748_ovl28;
            *(s32*)(p + 0x8C) = 0;
            p[5]++;
        }
        break;
    case 2:
        if (++*(s32*)(p + 0x8C) == 100) {
            p[4] = 2;
        }
        func_8002D9EC(p, 0x30, 0x20);
        break;
    }
    if (*(s8*)(*(u8**)(p + 0x7C) + 4) == 2) {
        p[4] = 2;
    }
    func_80017248(p);
    func_8002DF54(p);
}
