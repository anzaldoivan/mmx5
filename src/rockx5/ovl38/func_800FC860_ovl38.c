#include "types.h"
#include "mmx5/ovl38.h"
#include "mmx5/graphics.h"
#include "addr.h"

void func_800FC860_ovl38(u8* obj) {
    if (((s8*)obj)[0x45] == 1) {
        set_animation(obj, 0x15);
        *(u16*)(obj + 0xA) = *(u16*)(D_1F80004C.bytes + 0x88);
        *(u16*)(obj + 0xE) = *(u16*)(D_1F80004C.bytes + 0x8A);
        obj[6]++;
        func_800FCAA0_ovl38(obj);
    }
}
