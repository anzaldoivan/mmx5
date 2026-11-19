#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "addr.h"

void func_800F4CD4_ovl26(u8* obj) {
    animate_object(obj);
    if (((s8*)obj)[0x45] != 0) {
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x92] = 0;
        clear_object_slot(obj);
    }
}
