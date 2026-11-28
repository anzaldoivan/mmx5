#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#include "mmx5/title.h"

extern u16 D_800FA620_ovl09[3][8][2];

void func_800EEA68_ovl09(u8* obj) {
    u8* p;
    u8* e;
    u8* e2;
    u8* p2;
    s32 d2;
    s32 d;
    s32 i;
    s32 r;
    s32 q;

    r = random_byte() & 7;
    q = random_byte() & 0xF;
    if (((s8*)obj)[7] != 0) {
        for (i = 0; i < 8; i++) {
            e = D_8009A1F8.u;
            p = g_Player;
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
            ((s32(*)())func_8002FB58)(obj);
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
            e2 = D_8009A1F8.u;
            p2 = g_Player;
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
            ((s32(*)())func_8002FB58)(obj);
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

extern void func_80054440(u8* a0, s32 a1);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern int func_8002D7A0();
extern u8 D_8009A197;
extern u8 D_800FA614_ovl09[];
extern u8 D_800FA618_ovl09[];
extern u8 D_800FA760_ovl09[];
extern void* D_800FA79C_ovl09[];

void func_800EEE50_ovl09(u8* a0) {
    s32 r;

    if (*(s8*)(a0 + 2) != 0 && *(s8*)(a0 + 5) != 2) {
        *(u8**)(a0 + 0x50) = D_800FA614_ovl09;
        *(u8**)(a0 + 0x54) = D_800FA618_ovl09;
    } else {
        *(u8**)(a0 + 0x50) = 0;
        *(u8**)(a0 + 0x54) = 0;
    }
    r = func_80031DD0(a0);
    if (*(s8*)(a0 + 2) != 0) {
        if (r < 0) {
            *(s8*)(a0 + 5) = 0;
            a0[4]++;
            *(u16*)(a0 + 0x42) &= 0x7FFF;
            func_8004FD24(a0);
            func_80054440(a0, 0x12);
            func_8004D4F4(3, D_800FA760_ovl09, a0);
            return;
        }
    } else {
        *(s8*)(a0 + 5) = 5;
    }
    if (D_8009A197 == 0) {
        ((void (*)(u8*))D_800FA79C_ovl09[*(s8*)(a0 + 5)])(a0);
    }
    ((void (*)())func_800317B8)(a0);
    if (*(s8*)(a0 + 2) != 0) {
        if (is_off_screen(a0, 0x40, 0x40) == 0) {
            func_8002D9EC(a0, 0x40, 0x40);
        } else {
            *(s8*)(a0 + 5) = 0;
            a0[4]++;
        }
    } else {
        *(s8*)(a0 + 3) = 0;
        if (is_off_screen(a0, 0x60, 0x40) == 1) {
            func_8002D7A0(a0);
            *(s8*)(a0 + 0x95) = 0;
        }
    }
    if (*(s8*)(a0 + 2) != 0 && *(s8*)(a0 + 0x95) != 0) {
        *(s8*)(a0 + 0x95) = (*(u8**)(a0 + 0x80))[0x15];
    }
}
