/* Shared body (DK-5), from the banked draft of func_800EEE50_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_80054440(u8* a0, s32 a1);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_800317B8(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern int func_8002D7A0();
extern u8 D_8009A197;
extern u8 D_800FA614_ovl09[];
extern u8 D_800FA618_ovl09[];
extern u8 D_800FA760_ovl09[];
extern void* D_800FA79C_ovl09[];

void DEDUP_NAME(u8* a0) {
    s32 r;

    if (*(s8*)(a0 + 2) != 0 && *(s8*)(a0 + 5) != 2) {
        *(u8**)(a0 + 0x50) = D_800FA614_ovl09;
        *(u8**)(a0 + 0x54) = D_800FA618_ovl09;
    } else {
        *(u8**)(a0 + 0x50) = 0;
        *(u8**)(a0 + 0x54) = 0;
    }
    r = func_80031DD0(a0);
    if (*(s8*)(a0 + 2) != 0) {
        if (r < 0) {
            *(s8*)(a0 + 5) = 0;
            a0[4]++;
            *(u16*)(a0 + 0x42) &= 0x7FFF;
            func_8004FD24(a0);
            func_80054440(a0, 0x12);
            func_8004D4F4(3, D_800FA760_ovl09, a0);
            return;
        }
    } else {
        *(s8*)(a0 + 5) = 5;
    }
    if (D_8009A197 == 0) {
        ((void (*)(u8*))D_800FA79C_ovl09[*(s8*)(a0 + 5)])(a0);
    }
    func_800317B8(a0);
    if (*(s8*)(a0 + 2) != 0) {
        if (func_8002D938(a0, 0x40, 0x40) == 0) {
            func_8002D9EC(a0, 0x40, 0x40);
        } else {
            *(s8*)(a0 + 5) = 0;
            a0[4]++;
        }
    } else {
        *(s8*)(a0 + 3) = 0;
        if (func_8002D938(a0, 0x60, 0x40) == 1) {
            func_8002D7A0(a0);
            *(s8*)(a0 + 0x95) = 0;
        }
    }
    if (*(s8*)(a0 + 2) != 0 && *(s8*)(a0 + 0x95) != 0) {
        *(s8*)(a0 + 0x95) = (*(u8**)(a0 + 0x80))[0x15];
    }
}
