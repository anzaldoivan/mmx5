#include "types.h"
#include "addr.h"

void func_800FB270_ovl27(ObjFAF38* arg0, u8 arg1);

void func_800FA33C_ovl27(ObjFAF38* arg0) {
    D_1F80004C.bytes[0x8A] = 0;
    func_800FB270_ovl27(arg0, 0);
    func_800FB270_ovl27(arg0, 1);
    ((u8*)arg0)[6]++;
}

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
