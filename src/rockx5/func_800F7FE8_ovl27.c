#include "types.h"
#include "addr.h"

extern u32 func_8002DF78(void);
extern void func_800FAD04_ovl27(u8* o, s32 a, s32 b);

void func_800F7FE8_ovl27(u8* o) {
    u8* s = D_1F80004C.bytes;
    u8* t;
    u8 r;

    if (s[0x88] != 1) {
        return;
    }
    s[0x88] = 0;
    t = D_1F80004C.bytes;
    if (((s8*)t)[0x8B] != 0) {
        switch (t[0x8C] & 0xE) {
        case 14:
            r = func_8002DF78() % 3;
            if (r == 0) {
                func_800FAD04_ovl27(o, 1, ((s8*)D_1F80004C.bytes)[0x84]);
            } else if (r == 1) {
                func_800FAD04_ovl27(o, 2, ((s8*)D_1F80004C.bytes)[0x86]);
            } else if (r == 2) {
                func_800FAD04_ovl27(o, 3, ((s8*)D_1F80004C.bytes)[0x85]);
            }
            break;
        case 12:
            if (func_8002DF78() & 1) {
                func_800FAD04_ovl27(o, 1, ((s8*)D_1F80004C.bytes)[0x84]);
            } else {
                func_800FAD04_ovl27(o, 2, ((s8*)D_1F80004C.bytes)[0x86]);
            }
            break;
        case 10:
            if (func_8002DF78() & 1) {
                func_800FAD04_ovl27(o, 1, ((s8*)D_1F80004C.bytes)[0x84]);
            } else {
                func_800FAD04_ovl27(o, 3, ((s8*)D_1F80004C.bytes)[0x85]);
            }
            break;
        case 8:
            func_800FAD04_ovl27(o, 1, ((s8*)D_1F80004C.bytes)[0x84]);
            break;
        case 6:
            if (func_8002DF78() & 1) {
                func_800FAD04_ovl27(o, 2, ((s8*)D_1F80004C.bytes)[0x86]);
            } else {
                func_800FAD04_ovl27(o, 3, ((s8*)D_1F80004C.bytes)[0x85]);
            }
            break;
        case 4:
            func_800FAD04_ovl27(o, 2, ((s8*)D_1F80004C.bytes)[0x86]);
            break;
        case 2:
            func_800FAD04_ovl27(o, 3, ((s8*)D_1F80004C.bytes)[0x85]);
            break;
        case 0:
            o[6]++;
            break;
        }
        D_1F80004C.bytes[0x8B]--;
    } else {
        o[6]++;
    }
}
