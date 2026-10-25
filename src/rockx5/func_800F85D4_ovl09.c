#include "types.h"
#include "addr.h"

extern void func_80016D54(s32, s32);
extern int func_8002D6FC();

void func_800F85D4_ovl09(u8* arg0) {
    if (D_1F80004C.bytes[0x84] == 2) {
        func_80016D54(2, 0x26);
    }
    (*(u8**)(D_1F80004C.bytes + 0x80))[0x85] |= 1 << (((s8*)arg0)[2] - 1);
    (*(u8**)(D_1F80004C.bytes + 0x80))[0x84] |= 1 << (((s8*)arg0)[2] - 1);
    func_8002D6FC(arg0);
}
