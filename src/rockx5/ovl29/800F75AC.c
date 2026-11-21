#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

#define D_8007BD4C D_800FA520_ovl29

#define func_800532E0 func_800F75AC_ovl29
#include "shared/func_800532E0.c"
#undef func_800532E0
#undef D_8007BD4C

#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

void func_800F75E8_ovl29(u8* obj) {
    u8* child;
    s32 t;
    s16 y;

    func_800317B8(obj);
    func_8002D9EC(obj, 0x30, 0x30);
    if (D_8009A420_as_s32 & 1) {
        animate_object(obj);
        t = *(u16*)(obj + 0x88) - 1;
        *(u16*)(obj + 0x88) = t;
        if ((t << 16) == 0 && (obj[0x70] & 3) == 0) {
            child = func_8002D1A4();
            if (child != 0) {
                child[0] = 0x41;
                child[1] = 0x29;
                child[2] = 3;
                *(u8**)(child + 0x7C) = obj;
                y = *(s16*)(obj + 0xA);
                *(s16*)(child + 0xA) = obj[0x15] ? y + 0x18 : y - 0x18;
                *(s16*)(child + 0xE) = *(s16*)(obj + 0xE);
                *(s16*)(child + 0x88) = 3;
            }
        }
        if (obj[0x47] == 0x8A) {
            *(s32*)(obj + 0x50) = 0;
        }
    }
    if (*(s8*)(obj + 0x46) == 0) {
        obj[5] = 0;
        obj[6] = 0;
        obj[4]++;
    }
}
#undef D_8009A420_as_s32

void func_800F76F8_ovl29(u8* a0) {
    move_object(a0);
    animate_object(a0);
    func_800317B8(a0);
    ((s32(*)())func_8002D9EC)(a0, 0x30, 0x30);
    if (*(s8*)(a0 + 0x46) < 0) {
        a0[5] = 0;
        a0[6] = 0;
        a0[4]++;
    }
}

extern void func_80044BD8();
#define D_800EEBA0_ovl00 func_800F7760_ovl29
#define func_8002D720 func_80044BD8
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800EEC60_ovl00 func_800F7780_ovl29
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
