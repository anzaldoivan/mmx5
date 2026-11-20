#include "types.h"
#include "mmx5/system.h"
#include "addr.h"

extern void func_800FAD04_ovl27(u8* o, s32 a, s32 b);

void func_800F81A4_ovl27(u8* o) {
    u8* s = D_1F80004C.bytes;
    u8 r;

    if (s[0x88] != 1) {
        return;
    }
    s[0x88] = 0;
    switch (D_1F80004C.bytes[0x8C] & 0xE) {
    case 14:
        r = ((u32(*)())random_byte)() % 3;
        if (r == 0) {
            func_800FAD04_ovl27(o, 1, ((s8*)D_1F80004C.bytes)[0x84]);
        } else if (r == 1) {
            func_800FAD04_ovl27(o, 2, ((s8*)D_1F80004C.bytes)[0x86]);
        } else if (r == 2) {
            func_800FAD04_ovl27(o, 3, ((s8*)D_1F80004C.bytes)[0x85]);
        }
        break;
    case 12:
        if (((u32(*)())random_byte)() & 1) {
            func_800FAD04_ovl27(o, 1, ((s8*)D_1F80004C.bytes)[0x84]);
        } else {
            func_800FAD04_ovl27(o, 2, ((s8*)D_1F80004C.bytes)[0x86]);
        }
        break;
    case 10:
        if (((u32(*)())random_byte)() & 1) {
            func_800FAD04_ovl27(o, 1, ((s8*)D_1F80004C.bytes)[0x84]);
        } else {
            func_800FAD04_ovl27(o, 3, ((s8*)D_1F80004C.bytes)[0x85]);
        }
        break;
    case 8:
        func_800FAD04_ovl27(o, 1, ((s8*)D_1F80004C.bytes)[0x84]);
        break;
    case 6:
        if (((u32(*)())random_byte)() & 1) {
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
    case 0: // !FAKE: empty case keeps the jump table based at index 0
        break;
    }
}
