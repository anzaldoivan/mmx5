#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_800FAF38_ovl27(u8* arg0);
extern s8 D_800D1C44;

void func_800FAB0C_ovl27(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == 0) {
        D_1F80004C.bytes[0x8A] = 0;
        func_800171E8(obj, 0xF);
        obj[6]++;
    } else if (--*(s16*)(obj + 0x7E) == 0) {
        s16 t;
        func_800FAF38_ovl27(obj);
        t = 9;
        if (D_800D1C44 == 0) {
            t = 5;
        }
        *(s16*)(obj + 0x7E) = t;
    }
}
