#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_800F4318_ovl26(u8* obj) {
    u8* scr;

    animate_object(obj);
    if (obj[0x47] == 0x31) {
        scr = D_1F80004C.bytes;
        if (scr[0x93] != 0) {
            scr[0x93] = 0;
        }
    }
    if (((s8*)obj)[0x45] == 1) {
        obj[5] = (((s8*)obj)[0x5C] >= D_800D1CA2 / 2 ||
                  (u32)(random_byte() & 0xF) < 8)
                     ? 5
                     : 10;
        obj[6] = 0;
    }
}
