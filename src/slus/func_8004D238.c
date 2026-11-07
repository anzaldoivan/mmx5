#include "types.h"

extern void func_8002D89C(u8*);
extern u16 D_8006FAE4[];
extern u16 D_80073020[];
extern u16 D_80073030[];
extern u8 D_80077538[];

void func_8004D238(u8* obj) {
    u8 i;
    s32 idx;
    u16 v;

    for (i = 0; i < 16; i++) {
        if ((1 << i) == D_80073020[((s8*)obj)[2]]) {
            idx = i;
            break;
        }
    }
    v = D_8006FAE4[idx];
    for (i = 0; i < 8; i++) {
        if (v == D_80073030[i]) {
            obj[0x47] = D_80077538[i];
            break;
        }
    }
    func_8002D89C(obj);
}
