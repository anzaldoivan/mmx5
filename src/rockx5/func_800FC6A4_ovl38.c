#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);

void func_800FC6A4_ovl38(u8* obj) {
    if ((s8)obj[0x45] == 1) {
        func_800171E8(obj, 0x17);
        *(s16*)(D_1F80004C.bytes + 0x88) = *(s16*)(obj + 0xA);
        *(s16*)(D_1F80004C.bytes + 0x8A) = *(s16*)(obj + 0xE);
        *(s16*)(obj + 0xA) = 0x1288;
        *(s16*)(obj + 0xE) = 0x7E0;
        obj[0x15] = 0;
        obj[6]++;
    }
}
