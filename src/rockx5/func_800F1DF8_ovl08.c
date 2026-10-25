#include "types.h"

extern void func_8002DF54(u8* a0);
extern void func_8001296C(s32);
extern void func_80016490(s32, s32, void*);

void func_800F1DF8_ovl08(u8* a0) {
    func_8002DF54(a0);
    if (*(s16*)(a0 + 0xE) >= *(s16*)(a0 + 0x7E) + *(s16*)(a0 + 0x80)) {
        if (((s8*)a0)[3] != 0) {
            func_8001296C(5);
            func_80016490(5, 0x15, a0);
        }
        *(s16*)(a0 + 0x7C) = 0x78;
        *(s16*)(a0 + 0xE) = *(s16*)(a0 + 0x7E) + *(s16*)(a0 + 0x80);
        a0[6]++;
    }
}
