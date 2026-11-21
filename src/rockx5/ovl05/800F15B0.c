#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;
extern void* D_800F55E4_ovl05[];

void func_800F15B0_ovl05(u8* p) {
    s8 t;

    if (is_off_screen(p, 0x70, 0x70) != 0) {
        p[4] = 3;
        p[0x91] = 0;
        *(s16*)(p + 0x88) = 5;
    } else {
        func_8002D9EC(p, 0x60, 0x60);
        if (D_8009A197 == 0) {
            *(s32*)(p + 0x18) = *(s32*)(p + 8);
            *(s32*)(p + 0x1C) = *(s32*)(p + 0xC);
            animate_object(p);
            ((void (*)(u8*))D_800F55E4_ovl05[(s8)p[5]])(p);
        }
        if ((s8)p[5] != 2) {
            t = p[0x45];
            if (t >= 0x32 || t == 2) {
                func_800317B8(p);
            }
            if (func_80031DD0(p) < 0) {
                p[0x90] = 1;
            }
            return;
        }
    }
    p[3] = 0;
}

#define D_800EEBA0_ovl00 func_800F16A4_ovl05
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern int func_8002D7A0();

void func_800F16C4_ovl05(u8* arg0) {
    if (--*(s16*)(arg0 + 0x88) == 0) {
        func_8002D7A0();
    }
}
