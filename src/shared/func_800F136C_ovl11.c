/* Shared body (DK-5), from the banked draft of func_800F136C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A197;
extern void (*D_800F9918_ovl11[])(u8*);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8002FB58(u8* obj);
extern s32 func_8004FD24(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* a0) {
    *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
    *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
    if (D_8009A197 == 0) {
        D_800F9918_ovl11[*(s8*)(a0 + 5)](a0);
        func_80017248(a0);
        func_8002DED4(a0);
    }
    func_800317B8(a0);
    if (func_80031DD0(a0) < 0 ||
        ((*(u8*)(a0 + 0x70) != 0 ||
          (func_8002FB58(a0), *(u8*)(a0 + 0x70) != 0)) &&
         *(u8*)(a0 + 0x93) == 1)) {
        func_8004FD24(a0);
        *(u8*)(a0 + 4) += 1;
        return;
    }
    *(u8*)(a0 + 0x70) = 0;
    if (__builtin_abs(*(s32*)(a0 + 0x20)) > 0x40000) {
        *(s32*)(a0 + 0x28) = 0;
    }
    if (func_8002D938(a0, 0x40, 0x20) == 0) {
        func_8002D9EC(a0, 0x20, 0x20);
        return;
    }
    *(u8*)(a0 + 4) += 1;
}
