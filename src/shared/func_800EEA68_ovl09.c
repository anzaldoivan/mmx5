/* Shared body (DK-5), from the banked draft of func_800EEA68_ovl09 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8002DF78(void);
extern s32 func_8002FB58(u8* obj);
extern u8 D_8009A1F8[];
extern u8 D_8009A0A0[];
extern u16 D_800FA620_ovl09[3][8][2];

void DEDUP_NAME(u8* obj) {
    u8* p;
    u8* e;
    u8* e2;
    u8* p2;
    s32 d2;
    s32 d;
    s32 i;
    s32 r;
    s32 q;

    r = func_8002DF78() & 7;
    q = func_8002DF78() & 0xF;
    if (((s8*)obj)[7] != 0) {
        for (i = 0; i < 8; i++) {
            e = D_8009A1F8;
            p = D_8009A0A0;
            d = *(s16*)(p + 0xA) - *(s16*)(e + 0xA);
            if (d < 0x6E) {
                switch (((s8*)obj)[2]) {
                case 1:
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e + 0x5E) + D_800FA620_ovl09[0][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e + 0x62) + D_800FA620_ovl09[0][r][1];
                    break;
                case 2:
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e + 0xB2) + D_800FA620_ovl09[0][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e + 0xB6) + D_800FA620_ovl09[0][r][1];
                    break;
                case 3:
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e + 0xB2) + D_800FA620_ovl09[0][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e + 0xB6) + D_800FA620_ovl09[0][r][1];
                    break;
                }
            } else if (d >= 0xD3) {
                switch (((s8*)obj)[2]) {
                case 1:
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e + 0xA) + D_800FA620_ovl09[0][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e + 0xE) + D_800FA620_ovl09[0][r][1];
                    break;
                case 2:
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e + 0xA) + D_800FA620_ovl09[0][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e + 0xE) + D_800FA620_ovl09[0][r][1];
                    break;
                case 3:
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e + 0x5E) + D_800FA620_ovl09[0][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e + 0x62) + D_800FA620_ovl09[0][r][1];
                    break;
                }
            } else {
                switch (((s8*)obj)[2]) {
                case 1:
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e + 0xA) + D_800FA620_ovl09[0][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e + 0xE) + D_800FA620_ovl09[0][r][1];
                    break;
                case 2:
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e + 0xB2) + D_800FA620_ovl09[0][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e + 0xB6) + D_800FA620_ovl09[0][r][1];
                    break;
                case 3:
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e + 0xB2) + D_800FA620_ovl09[0][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e + 0xB6) + D_800FA620_ovl09[0][r][1];
                    break;
                }
            }
            func_8002FB58(obj);
            if (obj[0x70] == 0) {
                *(s32*)(obj + 0x68) = 0;
                obj[6] = 1;
                obj[7] = 0;
                return;
            }
            r++;
            r &= 7;
        }
    } else {
        for (i = 0; i < 8; i++) {
            e2 = D_8009A1F8;
            p2 = D_8009A0A0;
            d2 = *(s16*)(p2 + 0xA) - *(s16*)(e2 + 0xA);
            if (d2 < 0x6E) {
                if (q < 2) {
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e2 + 0xA) + D_800FA620_ovl09[0][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e2 + 0xE) + D_800FA620_ovl09[0][r][1];
                } else if (q >= 0xD) {
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e2 + 0xA) + D_800FA620_ovl09[2][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e2 + 0xE) + D_800FA620_ovl09[2][r][1];
                } else {
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e2 + 0xA) + D_800FA620_ovl09[1][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e2 + 0xE) + D_800FA620_ovl09[1][r][1];
                }
            } else if (d2 >= 0xD3) {
                if (q < 2) {
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e2 + 0xA) + D_800FA620_ovl09[0][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e2 + 0xE) + D_800FA620_ovl09[0][r][1];
                } else if (q >= 0xB) {
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e2 + 0xA) + D_800FA620_ovl09[2][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e2 + 0xE) + D_800FA620_ovl09[2][r][1];
                } else {
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e2 + 0xA) + D_800FA620_ovl09[1][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e2 + 0xE) + D_800FA620_ovl09[1][r][1];
                }
            } else {
                if (q < 4) {
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e2 + 0xA) + D_800FA620_ovl09[0][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e2 + 0xE) + D_800FA620_ovl09[0][r][1];
                } else if (q >= 9) {
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e2 + 0xA) + D_800FA620_ovl09[2][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e2 + 0xE) + D_800FA620_ovl09[2][r][1];
                } else {
                    *(u16*)(obj + 0xA) =
                        *(u16*)(e2 + 0xA) + D_800FA620_ovl09[1][r][0];
                    *(u16*)(obj + 0xE) =
                        *(u16*)(e2 + 0xE) + D_800FA620_ovl09[1][r][1];
                }
            }
            func_8002FB58(obj);
            if (obj[0x70] == 0) {
                *(s32*)(obj + 0x68) = 0;
                obj[6]++;
                return;
            }
            r++;
            r &= 7;
        }
    }
}
