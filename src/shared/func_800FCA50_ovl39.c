#include "types.h"
#include "addr.h"

void func_800FCE1C_ovl39(u8* arg0, u8 arg1, u8* arg2);

void func_800FCA50_ovl39(u8* arg0) {
    D_1F80004C.bytes[0x88] = 0;
    func_800FCE1C_ovl39(arg0, D_1F80004C.bytes[0x88], D_1F80004C.bytes);
    *(s16*)(arg0 + 0x7C) = 1;
    *(s16*)(arg0 + 0x7E) = 0;
    arg0[6]++;
}
