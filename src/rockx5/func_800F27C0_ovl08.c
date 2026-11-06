#include "types.h"

extern void func_800F28E8_ovl08(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80028B18(s32, s32, s32, void*);
extern u8 D_8009A244;
extern u8 D_800F3F34_ovl08[];
extern u8 D_800F3F44_ovl08[];

void func_800F27C0_ovl08(u8* obj) {
    obj[3] = 0;
    if (!(*(u16*)(obj + 0x7C) & 3)) {
        obj[3] = 1;
    }
    if (--*(s16*)(obj + 0x7E) == 0) {
        func_800F28E8_ovl08(obj);
        *(s16*)(obj + 0x7E) = 8;
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[3] = 0;
        func_800F28E8_ovl08(obj);
        func_800F28E8_ovl08(obj);
        func_800F28E8_ovl08(obj);
        func_800F28E8_ovl08(obj);
        *(s32*)(obj + 0x20) = 0;
        func_8004D4F4(3, D_800F3F34_ovl08, obj);
        func_80028B18(0, 0x660, 0x110, D_800F3F44_ovl08);
        D_8009A244 = 1;
        obj[4] = 6;
    }
}
