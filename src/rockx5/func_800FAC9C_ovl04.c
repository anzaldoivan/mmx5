#include "types.h"

extern s32 func_800F033C_ovl04(void);
extern void func_8002A600(s32, s32, s32);
extern s32 func_8002DF78(void);
extern u8* func_8002D27C(void);
extern u16 D_8009A22C;
extern s32 D_8009A420;
extern u16 D_80102BFC_ovl04[][4];

static inline u8* func_800FAC9C_ovl04_spawn(u8* arg0) {
    u8* obj;

    obj = func_8002D27C();
    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 0x18;
        obj[2] = 2;
        *(u8**)(obj + 0x50) = arg0;
    }
    return obj;
}

void func_800FAC9C_ovl04(u8* arg0) {
    s32 v;
    s32 r;
    u8* obj;

    if (func_800F033C_ovl04() != 0) {
        v = *(s32*)(arg0 + 0x84);
        if ((v >> 16) != 0x40) {
            if (v > 0x400000) {
                *(s32*)(arg0 + 0x84) = v - 0x10000;
            } else {
                *(s32*)(arg0 + 0x84) = v + 0x10000;
            }
            if (D_8009A22C == 0) {
                func_8002A600(0xA, 3, 2);
            }
            if (!(D_8009A420 & 7)) {
                r = func_8002DF78() & 3;
                obj = func_800FAC9C_ovl04_spawn(arg0);
                if (obj != 0) {
                    *(u16*)(obj + 0xA) =
                        *(u16*)(arg0 + 0xA) + D_80102BFC_ovl04[r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(arg0 + 0xE) + D_80102BFC_ovl04[r][2];
                    if (func_8002DF78() & 1) {
                        *(u16*)(obj + 0xA) -= func_8002DF78() & 3;
                    } else {
                        *(u16*)(obj + 0xA) += func_8002DF78() & 3;
                    }
                }
            }
        }
    }
}
