#include "types.h"
#include "mmx5/globals.h"

extern void silence_sound(s32, s32);
extern void func_800132F8(s8 arg);
extern s32 func_800272B4(void);

void func_80034B84(u8* arg0) {
    silence_sound(0xFF, 0);
    func_800132F8(8);
    func_800272B4();
    arg0[5] = 1;
}

extern s8 D_8009A424;

void func_80034BC8(u8* a0) {
    s8 v;

    if (D_8009A424 == 0) {
        v = ((s8*)a0)[0x14];
        a0[4] = 1;
        a0[5] = 0;
        if (v >= 13) {
            a0[5] = 2;
        } else if (v >= 10) {
            a0[5] = 1;
        }
    }
    func_800272DC();
}
