#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern s32 func_80016490(s32, s32, void*);
extern s16 D_8009A0AA;

void func_800FA5C0_ovl27(u8* obj) {
    s16 t;

    t = --*(s16*)(obj + 0x7C);
    if (t == 0) {
        func_800171E8(obj, 0x19);
        *(s32*)(obj + 0x24) = 0;
        if (D_8009A0AA < *(s16*)(obj + 0xA)) {
            func_80016490(2, 0x66, obj);
            *(s32*)(obj + 0x20) = -0x20000;
            obj[6]++;
        } else {
            func_80016490(2, 0x66, obj);
            *(s32*)(obj + 0x20) = 0x20000;
            obj[6]++;
        }
    }
}
