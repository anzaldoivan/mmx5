#include "types.h"

#define SCR4C (*(u8**)0x1F80004C)

extern u8 D_8009A0A0[];
extern u8 D_800FD9D4_ovl28[];
extern void (*D_800FDA10_ovl28[])(u8*);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_80054440(u8* a0, s32 a1);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_800F092C_ovl28(u8* a0);
extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_8002D800(u8* a0);
extern void func_8002D89C(u8* a0);

void func_800F0344_ovl28(u8* obj) {
    u8 state;
    u8* p;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_80054440(obj, 0x12);
        func_8004D4F4(5, D_800FD9D4_ovl28, obj);
        state = 2;
    } else {
        p = D_8009A0A0;
        if (p[0xF7] == 0) {
            if (*(signed char*)(obj + 2) == 3) {
                if (*(s32*)(obj + 8) > *(s32*)(p + 8)) {
                    obj[0x15] = 0;
                } else {
                    obj[0x15] = 0x40;
                }
            }
            func_800F092C_ovl28(obj);
            if (SCR4C[0x89] < 0x3C) {
                D_800FDA10_ovl28[*(signed char*)(obj + 5)](obj);
            } else {
                func_80017248(obj);
            }
        }
        func_800317B8(obj);
        if (func_8002D800(obj) == 0) {
            func_8002D89C(obj);
            return;
        }
        state = 4;
    }
    obj[4] = state;
}
