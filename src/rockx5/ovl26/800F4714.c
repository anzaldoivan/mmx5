#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern u8* func_8002C938();

void func_800F4714_ovl26(u8* obj) {
    u8* child;

    animate_object(obj);
    child = func_8002C938();
    if (child != 0) {
        child[0] = 0x41;
        child[1] = 0x3A;
        child[2] = 1;
        *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
        *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
        *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
        *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
        child[0x5C] = obj[0x5C];
        *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
        *(u16*)(child + 0xE) = *(u16*)(obj + 0xE);
        child[0x15] = obj[0x15];
        *(u8**)(child + 0x80) = obj;
    }
    obj[6]++;
}

void func_800F47D0_ovl26(u8* obj) {
    animate_object(obj);
    if (D_1F80004C.bytes[0x92] == 0) {
        obj[5] = 4;
        obj[6] = 0;
    }
}

#define D_800EEC60_ovl00 func_800F4818_ovl26
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800EEC60_ovl00 func_800F4820_ovl26
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800EEC60_ovl00 func_800F4828_ovl26
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800EEC60_ovl00 func_800F4830_ovl26
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800EEC60_ovl00 func_800F4838_ovl26
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800EEC60_ovl00 func_800F4840_ovl26
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
