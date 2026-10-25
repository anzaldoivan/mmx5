#include "types.h"
#include "addr.h"

extern s32 func_8002DF78(void);
extern void func_8002DED4(u8* obj);
extern signed char D_800D1CA2;

void func_800FC240_ovl38(u8* obj) {
    if (obj[0x70] & 8) {
        if (D_1F80004C.bytes[0x91] == 0 &&
            ((signed char*)obj)[0x5C] <= D_800D1CA2 / 2 &&
            (func_8002DF78() & 1)) {
            obj[5] = 9;
        } else {
            obj[5] = 3;
        }
        obj[6] = 0;
    } else {
        func_8002DED4(obj);
    }
}
