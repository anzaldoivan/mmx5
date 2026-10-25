#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800FCAA0_ovl38(u8*);

void func_800FC860_ovl38(u8* obj) {
    if (((s8*)obj)[0x45] == 1) {
        func_800171E8(obj, 0x15);
        *(u16*)(obj + 0xA) = *(u16*)(D_1F80004C.bytes + 0x88);
        *(u16*)(obj + 0xE) = *(u16*)(D_1F80004C.bytes + 0x8A);
        obj[6]++;
        func_800FCAA0_ovl38(obj);
    }
}
