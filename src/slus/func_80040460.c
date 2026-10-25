#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8003AA4C(u8* arg0);

void func_80040460(u8* obj) {
    func_80017248(obj);
    if (((s8*)obj)[0x45] & 0x80) {
        obj[0x45] &= 0x7F;
    }
    if (((s8*)obj)[0x46] == 0) {
        func_8003AA4C(obj);
    }
}
