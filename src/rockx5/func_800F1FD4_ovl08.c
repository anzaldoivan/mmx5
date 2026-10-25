#include "types.h"

extern void func_8002DF54(u8* a0);
extern void func_80016490(s32, s32, void*);
extern u8 D_800D1C00[];

void func_800F1FD4_ovl08(u8* a0) {
    func_8002DF54(a0);
    if (*(s16*)(a0 + 0xE) <= *(s16*)(a0 + 0x7E)) {
        if (a0[0x84] != 0) {
            u8* p = D_800D1C00;
            p[0x27] = p[0x27] - 1;
            if (((s8*)p)[0x27] == 0) {
                func_80016490(5, 0x14, 0);
            }
        }
        *(s16*)(a0 + 0x7C) = 0x78;
        a0[5] = 0;
        a0[6] = 0;
        *(s16*)(a0 + 0xE) = *(s16*)(a0 + 0x7E);
    }
}
