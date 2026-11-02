#include "types.h"

extern u8* func_8002D27C(void);
extern s32 func_8002DF78(void);
extern u8 D_8009A0A0[];
extern void (*D_80100D98_ovl04[])(u8*);
extern s16 D_80102FD4_ovl04;

void func_800EEBE4_ovl04(u8* arg0) {
    u8* base = D_8009A0A0;
    u8* p;

    if (*(s8*)(base + 0xCC) != 0) {
        return;
    }
    D_80100D98_ovl04[*(s8*)(arg0 + 4)](arg0);
    if (D_80102FD4_ovl04 == 0) {
        if (arg0[0x1D] != 0) {
            if (--arg0[0x1D] != 0) {
                return;
            }
        }
        if (*(s8*)(base + 5) >= 2 && *(s8*)(base + 5) != 0x11) {
            p = func_8002D27C();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x18;
                p[2] = 0xB;
            }
        }
    }
    arg0[0x1D] = func_8002DF78() % 121 + 0x78;
}
