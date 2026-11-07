#include "types.h"

extern void func_80013288(s32);
extern void func_800177B0(s32, s32);
extern void func_800EEDE0_ovl20(u8* arg0);

void func_800F0CF4_ovl20(u8* arg0) {
    s32 id;
    s32 i;
    s32 n;
    u8 bits;
    u8 t;

    func_80013288(8);
    id = 0x16;
    if (arg0[0x79] >= 5) {
        id = 0x17;
        if (arg0[0x10F] == 3) {
            bits = arg0[0x4C];
            for (i = 0, n = 0; i < 8; i++) {
                if ((bits >> i) & 1) {
                    n++;
                }
            }
            if (n == 6) {
                t = arg0[0x194];
                if (t == 0xB || t == 0xC || t == 0xF) {
                    id = 0x16;
                }
            }
        }
    }
    func_800177B0(id, 0x73);
    arg0[2] = 0;
    arg0[1]++;
    func_800EEDE0_ovl20(arg0);
}
