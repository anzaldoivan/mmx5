#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern void func_800EF04C_ovl03(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);
extern u8 D_8009A197;
extern void* D_800F9580_ovl03[];
extern u8 D_800F956C_ovl03[];

void func_800EEB64_ovl03(u8* p) {
    s32 three;
    u8 f;

    if (D_8009A197 == 0) {
        *(s32*)(p + 0x18) = *(s32*)(p + 0x8);
        *(s32*)(p + 0x1C) = *(s32*)(p + 0xC);
        func_800EF04C_ovl03(p);
        ((void (*)(u8*))D_800F9580_ovl03[*(s8*)(p + 5)])(p);
    }
    func_800317B8(p);
    if (func_80031DD0(p) < 0) {
        func_8004FD24(p);
        func_8004D4F4(4, D_800F956C_ovl03, p);
        func_80054440(p, 0x11);
        p[4] = 2;
        return;
    }
    f = p[0x70];
    if ((f & 0xC) == 0xC || (f & 3) == (three = 3)) {
        func_8004FD24(p);
        func_8004D4F4(4, D_800F956C_ovl03, p);
        p[4] = 2;
        return;
    }
    if (is_off_screen(p, 0x40, 0x40) == 0) {
        func_8002D9EC(p, 0x20, 0x20);
    } else {
        p[4] = three;
    }
    if (p[0x70] & 8) {
        p[0x67] = 0;
        return;
    }
    if (*(s32*)(p + 0x24) < 0) {
        *(s8*)(p + 0x67) = -1;
    } else {
        *(s8*)(p + 0x67) = 1;
    }
}
