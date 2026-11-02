#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_8002D89C(u8*);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8004FD24(u8* a0);
extern u8 D_8009A197;
extern u8 D_8009A1F8[];
extern u8 D_800F95F0_ovl11[];
extern void* D_800F967C_ovl11[];

void func_800EEBF0_ovl11(u8* arg0) {
    if (func_80031DD0(arg0) < 0 && *(s8*)(arg0 + 5) != 3) {
        func_8004FD24(arg0);
        func_8004D4F4(2, D_800F95F0_ovl11, arg0);
        *(s16*)(arg0 + 0x82) = 0;
        arg0[3] = 0;
        arg0[4] = 2;
        return;
    }
    if (D_8009A197 == 0 && *(s16*)(arg0 + 0x84) != 0) {
        ((void (*)(u8*))D_800F967C_ovl11[*(s8*)(arg0 + 5)])(arg0);
    }
    if (*(s8*)(arg0 + 0x45) == 4) {
        func_80016490(5, 0x19, arg0);
    }
    func_800317B8(arg0);
    if (*(s8*)(arg0 + 5) == 2) {
        func_8002D89C(arg0);
    } else {
        arg0[3] = 0;
    }
    if (*(s16*)(arg0 + 0x84) == 0) {
        u8* d = D_8009A1F8;
        s32 dx = *(u16*)(arg0 + 0xA) - *(u16*)(d + 0xA);
        s16 dy = *(u16*)(arg0 + 0xE) - *(u16*)(d + 0xE);
        if ((u16)dx < 0x140 && (u16)dy < 0xF0) {
            *(s16*)(arg0 + 0x84) = 1;
        }
    }
}
