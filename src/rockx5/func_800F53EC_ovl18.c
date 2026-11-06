#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern int func_8002D7A0();
extern u8 D_8009A197;
extern void* D_800F7ED0_ovl18[];
extern u8 D_800F7EBC_ovl18[];

void func_800F53EC_ovl18(u8* o) {
    if (D_8009A197 == 0) {
        ((void (*)(u8*))D_800F7ED0_ovl18[*(s8*)(o + 5)])(o);
    }
    func_800317B8(o);
    if (func_80031DD0(o) < 0) {
        o[5] = 0;
        o[4]++;
        *(u16*)(o + 0x42) &= 0x7FFF;
        func_8004FD24(o);
        func_8004D4F4(6, D_800F7EBC_ovl18, o);
        return;
    }
    if (func_8002D938(o, 0x20, 0x20) == 0) {
        func_8002D9EC(o, 0x20, 0x20);
        return;
    }
    func_8002D7A0(o);
}
