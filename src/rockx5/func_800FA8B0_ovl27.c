#include "types.h"
#include "addr.h"

extern void func_800FAE20_ovl27(u8* obj, s32 angle);
extern void func_800171E8(u8* obj, s32 state);

void func_800FA8B0_ovl27(u8* obj) {
    s16 a;

    if (--*(s16*)(obj + 0x7E) == 0) {
        *(s16*)(obj + 0x7E) = 4;
        func_800FAE20_ovl27(obj, (*(s16*)(obj + 0x7C) + 0x400) & 0xFFF);
        func_800FAE20_ovl27(obj, (*(s16*)(obj + 0x7C) + 0xC00) & 0xFFF);
        a = *(s16*)(obj + 0x7C);
        if (__builtin_abs(a) >= 0x1000) {
            D_1F80004C.bytes[0x8A] = 0;
            func_800171E8(obj, 5);
            obj[6]++;
        } else if (D_1F80004C.bytes[0x8B] != 0) {
            *(s16*)(obj + 0x7C) = *(u16*)(obj + 0x7C) + 0x2B;
        } else {
            *(s16*)(obj + 0x7C) = *(u16*)(obj + 0x7C) - 0x2B;
        }
    }
}
