#include "types.h"
#include "mmx5/globals.h"

extern void func_8003AA4C(u8* arg0);

void func_80040460(u8* obj) {
    animate_object(obj);
    if (((s8*)obj)[0x45] & 0x80) {
        obj[0x45] &= 0x7F;
    }
    if (((s8*)obj)[0x46] == 0) {
        func_8003AA4C(obj);
    }
}
