#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern s32 func_8002DF78(void);
extern signed char D_800D1CA2;

void func_800F4318_ovl26(u8* obj) {
    u8* scr;

    func_80017248(obj);
    if (obj[0x47] == 0x31) {
        scr = D_1F80004C.bytes;
        if (scr[0x93] != 0) {
            scr[0x93] = 0;
        }
    }
    if (((s8*)obj)[0x45] == 1) {
        obj[5] = (((s8*)obj)[0x5C] >= D_800D1CA2 / 2 ||
                  (u32)(func_8002DF78() & 0xF) < 8)
                     ? 5
                     : 10;
        obj[6] = 0;
    }
}
