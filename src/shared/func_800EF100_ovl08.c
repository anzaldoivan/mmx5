/* Shared body (DK-5), from the banked draft of func_800EF100_ovl08 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl08.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern void func_800EE9BC_ovl08(u8* a0);
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
        /* the definition takes a pointer, this call passes none */
        ((void (*)())func_800EEAF8_ovl08)();
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
    if (is_off_screen(a0, 0x40, 0x40) != 0) {
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
