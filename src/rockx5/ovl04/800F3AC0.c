#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

extern u8 D_801017A8_ovl04[];
extern u8 D_800757A0[];
extern u8 D_80101778_ovl04[];
extern u8 D_80101774_ovl04[];
extern u8 D_8009A0B4;

void func_800F3AC0_ovl04(u8* obj) {
    u8 t;

    obj[0x5C] = 1;
    *(u8**)(obj + 0x30) = D_801017A8_ovl04;
    *(u8**)(obj + 0x58) = D_800757A0;
    obj[0x60] = 0;
    obj[0x61] = 0;
    obj[0x15] = 0;
    t = D_8009A0B4;
    obj[0x16] = 6;
    *(u8**)(obj + 0x54) = D_80101778_ovl04;
    *(u8**)(obj + 0x50) = D_80101778_ovl04;
    *(u8**)(obj + 0x68) = D_80101774_ovl04;
    obj[0x4] = 1;
    obj[0x5] = 2;
    *(s16*)(obj + 0x7C) = 0;
    obj[0x14] = t;
    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    set_animation(obj, 0);
}

extern void (*D_801017D0_ovl04[])(u8*);
extern u8 D_801017BC_ovl04[];
extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);

void func_800F3B5C_ovl04(u8* obj) {
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_8004D4F4(8, D_801017BC_ovl04, obj);
        *(signed char*)(obj + 5) = 3;
        obj[3] = 0;
    } else {
        D_801017D0_ovl04[*(signed char*)(obj + 5)](obj);
        if (*(signed char*)(obj + 5) == 2) {
            func_8002D89C(obj);
        }
    }
}

#define D_800EEBA0_ovl00 func_800F3BEC_ovl04
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEBA0_ovl00 func_800F3C0C_ovl04
#define func_8002D720 animate_object
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern u8 D_8010177C_ovl04[];
extern u8 D_8009A244;

void func_800F3C2C_ovl04(u8* obj) {
    func_80028B18(0, 0x1240, 0x400, D_8010177C_ovl04);
    D_8009A244 = 1;
    obj[4] = 2;
}
