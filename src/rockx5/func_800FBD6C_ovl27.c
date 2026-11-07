#include "types.h"

extern void func_80012BF4(s32);
extern s32 func_80016490(s32, s32, void*);
extern void func_80016D54(s32, s32);
extern void func_8002A600(s32, s32, s32);
extern void func_8002DF54(u8* a0);

void func_800FBD6C_ovl27(u8* a0) {
    s32 t;
    u8 b;

    func_8002DF54(a0);
    if (*(s8*)(a0 + 2) == 0) {
        if (*(s16*)(a0 + 0xA) < 0x1269) {
            func_80016D54(2, 0x68);
            func_80016490(2, 0x69, 0);
            b = a0[6];
            *(s16*)(a0 + 0xA) = 0x1268;
            a0[6] = b + 1;
            return;
        }
        t = *(u16*)(a0 + 0x80) - 1;
        *(u16*)(a0 + 0x80) = t;
        if ((t << 16) == 0) {
            func_80012BF4(7);
            *(u16*)(a0 + 0x80) = 0x20;
            func_8002A600(0x18, 1, 2);
        }
    } else if (*(s16*)(a0 + 0xA) >= 0x1418) {
        *(s16*)(a0 + 0xA) = 0x1418;
        a0[6]++;
    }
}
