#include "types.h"
#include "addr.h"

extern s32 func_8002DF78(void);

void func_800FA258_ovl27(u8* arg0) {
    s16 t;

    t = --*(s16*)(arg0 + 0x7C);
    if (t == -1) {
        D_1F80004C.bytes[0x88] = 1;
        D_1F80004C.bytes[0x8B] = (u32)func_8002DF78() % 3 + 1;
        arg0[6]++;
    }
}
