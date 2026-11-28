#include "types.h"
#include "mmx5/ovl01.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/sound.h"

#define D_8007BD4C D_800FDB38_ovl01

#define func_800532E0 func_800FA438_ovl01
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#include "shared/func_800FA474_ovl01.c"

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_800FB418_ovl01(s32, void*, u8*, s32);
extern u8 D_800FD5B0_ovl01[];
extern u8 D_800FD5B4_ovl01[];
extern u8 D_800FD5B8_ovl01[];
extern u8 D_800FD5BC_ovl01[];
extern u8 D_800FD5C0_ovl01[];
extern u8 D_800FD5C4_ovl01[];
extern u8 D_800FD5C8_ovl01[];
extern u8 D_800FD5CC_ovl01[];

void func_800FA7A0_ovl01(u8* obj) {
    u8* a;
    u8* b;

    animate_object(obj);
    switch (obj[0x47]) {
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5A:
        a = D_800FD5B8_ovl01;
        b = D_800FD5BC_ovl01;
        break;
    case 0x5B:
    case 0x5C:
        a = D_800FD5C0_ovl01;
        b = D_800FD5C4_ovl01;
        break;
    case 0x5D:
        a = D_800FD5C8_ovl01;
        b = D_800FD5CC_ovl01;
        break;
    case 0x5E:
    case 0x5F:
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x54) = 0;
        goto done; // !FAKE: goto kept for the matching branch layout
    default:
        a = D_800FD5B0_ovl01;
        b = D_800FD5B4_ovl01;
        break;
    }
    *(u8**)(obj + 0x50) = a;
    *(u8**)(obj + 0x54) = b;
done:
    if ((D_8009A420_as_s32 & 0xF) == 0) {
        func_800FB418_ovl01(4, D_800FD9CC_ovl01, obj, 1);
    }
    if (*(s8*)(obj + 0x45) == 1) {
        obj[5] = 8;
        obj[6] = 0;
    }
}
