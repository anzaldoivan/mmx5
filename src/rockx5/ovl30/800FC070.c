#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/sound.h"

#define D_8007BD4C D_800FDD20_ovl30

#define func_800532E0 func_800FC070_ovl30
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_800FD5A8_ovl01 D_800FD790_ovl30
#define D_800FD5AC_ovl01 D_800FD794_ovl30
#define func_800FA474_ovl01 func_800FC0AC_ovl30
#define func_800FA4F8_ovl01 func_800FC130_ovl30
#define D_800FD5B0_ovl01 D_800FD798_ovl30
#define D_800FD5B4_ovl01 D_800FD79C_ovl30
#define D_800FDA5C_ovl01 D_800FDC44_ovl30
#define D_800FDA98_ovl01 D_800FDC80_ovl30
#define func_800FA564_ovl01 func_800FC19C_ovl30
#define D_800FD60C_ovl01 D_800FD7F4_ovl30
#define func_800FA648_ovl01 func_800FC280_ovl30
#define D_800FD9CC_ovl01 D_800FDBB4_ovl30
#define func_800FB418_ovl01 func_800FD050_ovl30
#define func_800FA6BC_ovl01 func_800FC2F4_ovl30
#include "shared/func_800FA474_ovl01.c"
#undef func_800FA474_ovl01
#undef D_800FD5A8_ovl01
#undef D_800FD5AC_ovl01
#undef func_800FA4F8_ovl01
#undef func_800FA564_ovl01
#undef D_800FD5B0_ovl01
#undef D_800FD5B4_ovl01
#undef D_800FDA5C_ovl01
#undef D_800FDA98_ovl01
#undef func_800FA648_ovl01
#undef D_800FD60C_ovl01
#undef func_800FA6BC_ovl01
#undef D_800FD9CC_ovl01
#undef func_800FB418_ovl01

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_800FD050_ovl30(s32, void*, u8*, s32);
extern u8 D_800FD798_ovl30[];
extern u8 D_800FD79C_ovl30[];
extern u8 D_800FD7A0_ovl30[];
extern u8 D_800FD7A4_ovl30[];
extern u8 D_800FD7A8_ovl30[];
extern u8 D_800FD7AC_ovl30[];
extern u8 D_800FD7B0_ovl30[];
extern u8 D_800FD7B4_ovl30[];
extern u8 D_800FDBB4_ovl30[];

void func_800FC3D8_ovl30(u8* obj) {
    u8* a;
    u8* b;

    animate_object(obj);
    switch (obj[0x47]) {
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5A:
        a = D_800FD7A0_ovl30;
        b = D_800FD7A4_ovl30;
        break;
    case 0x5B:
    case 0x5C:
        a = D_800FD7A8_ovl30;
        b = D_800FD7AC_ovl30;
        break;
    case 0x5D:
        a = D_800FD7B0_ovl30;
        b = D_800FD7B4_ovl30;
        break;
    case 0x5E:
    case 0x5F:
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x54) = 0;
        goto done; // !FAKE: goto kept for the matching branch layout
    default:
        a = D_800FD798_ovl30;
        b = D_800FD79C_ovl30;
        break;
    }
    *(u8**)(obj + 0x50) = a;
    *(u8**)(obj + 0x54) = b;
done:
    if ((D_8009A420_as_s32 & 0xF) == 0) {
        func_800FD050_ovl30(4, D_800FDBB4_ovl30, obj, 1);
    }
    if (*(s8*)(obj + 0x45) == 1) {
        obj[5] = 8;
        obj[6] = 0;
    }
}
