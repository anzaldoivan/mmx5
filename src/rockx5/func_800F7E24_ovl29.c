#include "types.h"

extern s32 func_8002D800(u8* a0);
extern s32 func_8002DED4(u8* obj);
extern void func_8002D89C(u8*);
extern void func_8002D6FC(u8* obj);

void func_800F7E24_ovl29(u8* obj) {
    if (func_8002D800(obj) == 0) {
        func_8002DED4(obj);
        obj[3] ^= 1;
        if (obj[3] != 0) {
            func_8002D89C(obj);
        }
    } else {
        func_8002D6FC(obj);
    }
}
