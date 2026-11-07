#include "types.h"

extern void func_8002DF54(u8* a0);
extern u8 D_800FEC1C_ovl39[];
extern u8 D_800FEC20_ovl39[];

void func_800FD558_ovl39(u8* a0) {
    s32 t;
    u8* p;
    u8* q;
    u8 v;
    s32 c;

    func_8002DF54(a0);
    t = ((s8*)a0)[2];
    if ((t == 0 && *(s16*)(a0 + 0xA) >= 0x12F0) ||
        (t == 1 && *(s16*)(a0 + 0xA) < 0x1131)) {
        if (((s8*)a0)[2] == 0) {
            q = D_800FEC20_ovl39;
            *(u8**)(a0 + 0x54) = q;
            q = D_800FEC1C_ovl39;
            *(u8**)(a0 + 0x68) = q;
            *(s32*)(a0 + 0x50) = 0;
            a0[0x8A] = 1;
            c = a0[6];
            c++;
            a0[6] = c;
        } else {
            *(u8**)(a0 + 0x54) = 0;
            *(s32*)(a0 + 0x50) = 0;
            *(u8**)(a0 + 0x68) = 0;
            a0[6] = 0xC;
        }
        p = *(u8**)(a0 + 0x7C);
        v = p[0x89];
        if (v) {
            v = 2;
        } else {
            v = 1;
        }
        p[0x89] = v;
        *(s16*)(a0 + 0x82) = 0x1E;
        a0[0x47] = 0;
    }
}
