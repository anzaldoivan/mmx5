#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_800F4B98_ovl26(u8* obj) {
    u8* p;

    animate_object(obj);
    if (((s8*)obj)[0x45] != 0) {
        p = *(u8**)(D_1F80004C.bytes + 0x80);
        if (p[0x8F] == 0) {
            p[0x92] = 0;
            (*(u8**)(D_1F80004C.bytes + 0x80))[0x8C] = 0;
            obj[6]++;
        }
    }
}
