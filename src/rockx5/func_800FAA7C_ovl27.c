#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800FAF38_ovl27(u8* arg0);
extern s8 D_800D1C44;

void func_800FAA7C_ovl27(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_800171E8(obj, 0x11);
        D_1F80004C.bytes[0x8A] = 1;
        func_800FAF38_ovl27(obj);
        *(s16*)(obj + 0x7C) = 0x78;
        if (D_800D1C44 != 0) {
            *(s16*)(obj + 0x7E) = 9;
        } else {
            *(s16*)(obj + 0x7E) = 5;
        }
        obj[6]++;
    }
}
