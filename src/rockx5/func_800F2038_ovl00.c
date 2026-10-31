#include "types.h"
#include "addr.h"

extern s32 func_8002DF78(void);
extern u8 D_800FAC90_ovl00[][5][5];

void func_800F2038_ovl00(u8* arg0) {
    u8 v;

    D_1F80004C.bytes[0x85]++;
    v = D_800FAC90_ovl00[((s8*)arg0)[2]][D_1F80004C.bytes[0x84]]
                        [D_1F80004C.bytes[0x85]];
    if (v == 0x80) {
        D_1F80004C.bytes[0x84] = func_8002DF78() & 3;
        D_1F80004C.bytes[0x85] = 0;
        arg0[5] = D_800FAC90_ovl00[((s8*)arg0)[2]][D_1F80004C.bytes[0x84]]
                                  [D_1F80004C.bytes[0x85]];
    } else {
        arg0[5] = v;
    }
    arg0[6] = 0;
}
