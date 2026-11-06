#include "types.h"

extern s32 func_8002DF78(void);
extern u8 D_800D1C00[];
extern s16 D_8009A202;
extern u8 D_80102AD0_ovl04[];

void func_800FE4C4_ovl04(u8* obj) {
    u8* p = D_800D1C00;
    s32 t;
    s32 r;

    if (*(u16*)(p + 0x28) != 0) {
        return;
    }
    t = D_8009A202;
    if (t < 0x620) {
        if (obj[0x8D] == 0 || --obj[0x8D] == 0) {
            r = func_8002DF78() & 0xF;
            p[0x28] = D_80102AD0_ovl04[r * 2];
            p[0x29] = (&D_80102AD0_ovl04[r * 2])[1];
            obj[0x8D] = 0xB4;
        }
    } else if (t < 0x9FF) {
        if (t == 0x78F || t == 0x858 || t == 0x8B4 || t == 0x92A ||
            t == 0x9A8 || t == 0x9E8) {
            D_800D1C00[0x28] = 0x30;
        }
    }
}
