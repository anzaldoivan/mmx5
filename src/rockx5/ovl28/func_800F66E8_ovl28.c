#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

#define G D_1F80004C.bytes

void func_800F66E8_ovl28(u8* obj) {
    animate_object(obj);
    if (G[0x8C] == 2) {
        obj[6]++;
    }
}
