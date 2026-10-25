#include "types.h"
#include "addr.h"

void func_800FA388_ovl27(u8* arg0) {
    u8* p = D_1F80004C.bytes;
    u8 s = p[0x8A];

    if (s == 1) {
        arg0[5] = 3;
        arg0[6] = 0;
    } else if (s == 2) {
        p[0x88] = 1;
        arg0[6]++;
    }
}
