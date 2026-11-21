#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;
extern void (*D_801014AC_ovl04[])(u8*);
extern u8 D_80101478_ovl04[];
extern void func_800F1080_ovl04(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);

void func_800F0B80_ovl04(u8* obj) {
    u8 state;

    if (D_8009A197 == 0 || *(signed char*)(obj + 2) != 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_801014AC_ovl04[*(signed char*)(obj + 5)](obj);
        func_800F1080_ovl04(obj);
    }
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_8004D4F4(5, D_80101478_ovl04, obj);
        func_80054440(obj, 0xC);
        state = 2;
    } else {
        if (is_off_screen(obj, 0x40, 0x40) == 0) {
            func_8002D9EC(obj, 0x20, 0x20);
            return;
        }
        state = 3;
    }
    obj[4] = state;
}
