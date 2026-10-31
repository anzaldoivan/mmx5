/* Shared body (DK-5), from the banked draft of func_800EF100_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8002FB58(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8004FD24(u8* a0);
extern void func_80054440(u8* a0, s32 a1);
extern void func_800EE9BC_ovl08(u8* a0);
extern void func_800EEAF8_ovl08(void);
extern void func_800EEC98_ovl08(u8* a0);
extern u8 D_8009A197;
extern u8 D_800F3B14_ovl08[];
extern void* D_800F3B18_ovl08[];

void DEDUP_NAME(u8* a0) {
    s32 r;
    u8 f;

    if (D_8009A197 == 0) {
        *(s32*)(a0 + 0x18) = *(s32*)(a0 + 0x8);
        *(s32*)(a0 + 0x1C) = *(s32*)(a0 + 0xC);
        func_800EEAF8_ovl08();
        func_800EE9BC_ovl08(a0);
        func_800EEC98_ovl08(a0);
        ((void (*)(u8*))D_800F3B18_ovl08[*(s8*)(a0 + 5)])(a0);
    }
    func_800317B8(a0);
    r = func_80031DD0(a0);
    if (r < 0) {
        func_8004FD24(a0);
        func_8004D4F4(4, D_800F3B14_ovl08, a0);
        if (r != -0x38) {
            func_80054440(a0, 0x12);
        }
        a0[4]++;
        return;
    }
    if (func_8002D938(a0, 0x40, 0x40) != 0) {
        a0[4] = 4;
        return;
    }
    func_8002D9EC(a0, 0x25, 0x25);
    f = a0[0x70];
    if ((f & 0xC) == 0xC || (f & 3) == 3) {
        func_8004FD24(a0);
        func_8004D4F4(4, D_800F3B14_ovl08, a0);
        a0[3] = 0;
        a0[4]++;
        return;
    }
    func_8002FB58(a0);
}
