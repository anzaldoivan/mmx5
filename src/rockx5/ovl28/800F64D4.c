#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"
#include "addr.h"

#define func_800F2850_ovl02 func_800F64D4_ovl28
#include "shared/func_800F2850_ovl02.c"
#undef func_800F2850_ovl02

extern void func_800F6A8C_ovl28(u8* obj);

void func_800F6508_ovl28(u8* obj) {
    func_800F6A8C_ovl28(obj);
    animate_object(obj);
    if (((s8*)obj)[7] == 2) {
        obj[7] = 3;
        D_1F80004C.bytes[0x8C] = 0;
        *(s16*)(obj + 0x7C) = 0x1E;
        *(s16*)(obj + 0x7E) = 5;
        set_animation(obj, 9);
        obj[6]++;
    }
}

extern u8 D_800FE198_ovl28[][3];

#define G D_1F80004C.bytes
void func_800F6580_ovl28(u8* obj) {
    animate_object(obj);
    if (G[0x8C] == 1) {
        obj[5] = D_800FE198_ovl28[0][++G[0x8A] + G[0x89] * 3];
        obj[6] = 0;
        obj[7] = 0;
    }
}
