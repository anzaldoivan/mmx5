#include "types.h"

extern s32 func_8002DFB0(void);
extern u8* func_8002D53C(void);
extern s16 D_800FB46C_ovl00[][7];
extern X4_BackgroundObj D_8009A1F8[3];

void func_800F6D58_ovl00(s32 arg0) {
    u8* p;
    s16 y;

    y = D_800FB46C_ovl00[arg0][6] += D_800FB46C_ovl00[arg0][5];
    if (!(func_8002DFB0() & 1)) {
        p = func_8002D53C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x11;
            *(s16*)(p + 8) = (D_800FB46C_ovl00[arg0][2] + y) >> 4;
            *(s16*)(p + 0xA) =
                (D_8009A1F8[0].x_pos.i.hi - D_8009A1F8[1].x_pos.i.hi) +
                D_800FB46C_ovl00[arg0][0];
            *(s16*)(p + 0xE) = D_800FB46C_ovl00[arg0][1];
        }
    }
    if (!(func_8002DFB0() & 1)) {
        p = func_8002D53C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x11;
            *(s16*)(p + 8) = D_800FB46C_ovl00[arg0][3];
            *(s16*)(p + 8) = (D_800FB46C_ovl00[arg0][3] + y) >> 4;
            *(s16*)(p + 0xA) =
                (D_8009A1F8[0].x_pos.i.hi - D_8009A1F8[1].x_pos.i.hi) +
                D_800FB46C_ovl00[arg0][0];
            *(s16*)(p + 0xE) = D_800FB46C_ovl00[arg0][1];
        }
    }
    if (!(func_8002DFB0() & 1)) {
        p = func_8002D53C();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x11;
            *(s16*)(p + 8) = (D_800FB46C_ovl00[arg0][4] + y) >> 4;
            *(s16*)(p + 0xA) =
                (D_8009A1F8[0].x_pos.i.hi - D_8009A1F8[1].x_pos.i.hi) +
                D_800FB46C_ovl00[arg0][0];
            *(s16*)(p + 0xE) = D_800FB46C_ovl00[arg0][1];
        }
    }
}
