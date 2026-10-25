#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002DF78(void);
extern signed char D_800D1CA2;

void func_800F4658_ovl26(u8* obj) {
    u8 state;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        if (*(s8*)(obj + 0x5C) >= D_800D1CA2 / 2 ||
            (u32)(func_8002DF78() & 0xF) < 8) {
            state = 8;
        } else {
            state = 9;
        }
        obj[5] = state;
        obj[6] = 0;
    }
}
