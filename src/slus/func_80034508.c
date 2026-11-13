#include "types.h"
#include "addr.h"

extern void func_800132F8(s8 arg);
extern s32 func_800272DC(void);
extern void func_800183E8(void);
extern s32 func_8002C338(s32, void*, s32);
extern u8* func_8002D2DC(void);
extern u8* func_8002D53C(void);
extern void func_80013288(s32);
extern s32 func_800231B4(void);
extern void func_80011FD4(s8 arg0, s8 arg1);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);
extern void func_8002D6FC(u8* obj);
extern s8 D_8009A424;
extern u8 D_8009A0A0[];
extern u16 D_800733C4[][6];
extern u8* D_800E9538[];
extern u8 D_800C9310;
extern u8 D_800D1C00[];
extern u16 D_800C931C[];

void func_80034508(u8* obj) {
    u8* p;
    s32 i;
    s32 x;
    s8 y;
    s32 t;

    t = *(s8*)(obj + 6);
    switch (t) {
    case 0:
        func_800132F8(8);
        t = obj[6];
        t++;
        obj[6] = t;
        func_800272DC();
        return;
    case 1:
        if (D_8009A424 != 0) {
            func_800272DC();
        } else {
            func_800183E8();
            obj[6]++;
        }
        return;
    case 2:
        func_8002C338(0x15, D_801F3000 + D_801F3004, 2);
        for (i = 0; i < 10; i++) {
            p = func_8002D2DC();
            if (p != 0) {
                p[0] = 1;
                p[1] = 2;
                p[2] = i;
            }
        }
        for (i = 0; i < 4; i++) {
            D_800E9538[i] = func_8002D53C();
            if (D_800E9538[i] != 0) {
                D_800E9538[i][0] = 1;
                D_800E9538[i][1] = 0xB;
                D_800E9538[i][0x36] = 0xFF;
                if ((s8)D_8009A0A0[2] != 0) {
                    *(s16*)(D_800E9538[i] + 0x34) = 0x1F;
                } else {
                    *(s16*)(D_800E9538[i] + 0x34) = 0x7C00;
                }
                *(s8*)(D_800E9538[i] + 0x37) = -1;
                *(s16*)(D_800E9538[i] + 0xA) = 0;
                *(s16*)(D_800E9538[i] + 0xE) = 0;
                D_800E9538[i][3] = 1;
                *(u16*)(D_800E9538[i] + 0x16) = D_800733C4[i][0];
                *(u16*)(D_800E9538[i] + 0x1A) = D_800733C4[i][1];
                *(u16*)(D_800E9538[i] + 0x1E) = D_800733C4[i][2];
                *(u16*)(D_800E9538[i] + 0x22) = D_800733C4[i][3];
                *(u16*)(D_800E9538[i] + 0x26) = D_800733C4[i][2];
                *(u16*)(D_800E9538[i] + 0x2A) = D_800733C4[i][3];
                *(u16*)(D_800E9538[i] + 0x2E) = D_800733C4[i][4];
                *(u16*)(D_800E9538[i] + 0x32) = D_800733C4[i][5];
            }
        }
        func_80013288(8);
        t = obj[6];
        t++;
        obj[6] = t;
        func_800231B4();
        return;
    case 3:
        if (D_8009A424 == 0) {
            obj[6]++;
        }
        func_800231B4();
        D_800C9310 |= 1;
        if (D_8009A0A0[0xF7] == 2) {
            D_8009A0A0[0xF7] = 1;
        }
        func_8002C2C0();
        func_8002BD8C();
        func_800272B4();
        break;
    case 4:
        x = D_800D1C00[0x1B9];
        y = D_800D1C00[0x1B9];
        if (D_800C931C[2] & 0x1000) {
            if (y >= -15) {
                D_800D1C00[0x1B9] = x - 1;
            }
        }
        if (D_800C931C[2] & 0x4000) {
            if ((s8)D_800D1C00[0x1B9] < 16) {
                D_800D1C00[0x1B9]++;
            }
        }
        if (D_800C931C[2] & 0x8000) {
            if ((s8)D_800D1C00[0x1B8] >= -15) {
                D_800D1C00[0x1B8]--;
            }
        }
        if (D_800C931C[2] & 0x2000) {
            if ((s8)D_800D1C00[0x1B8] < 16) {
                D_800D1C00[0x1B8]++;
            }
        }
        if (D_800C931C[2] & 0x40) {
            obj[6]++;
        }
        if (D_800C931C[2] & 0x10) {
            D_800D1C00[0x1B8] = 0;
            D_800D1C00[0x1B9] = 0;
        }
        func_80011FD4(D_800D1C00[0x1B8], D_800D1C00[0x1B9]);
        func_800231B4();
        if (D_8009A0A0[0xF7] == 2) {
            D_8009A0A0[0xF7] = 1;
        }
        func_8002C2C0();
        func_8002BD8C();
        func_800272B4();
        break;
    case 5:
        if (D_800C931C[0] == 0) {
            obj[6]++;
        }
        func_800231B4();
        if (D_8009A0A0[0xF7] == 2) {
            D_8009A0A0[0xF7] = 1;
        }
        func_8002C2C0();
        func_8002BD8C();
        func_800272B4();
        break;
    case 6:
        for (i = 0; i < 4; i++) {
            if (D_800E9538[i] != 0) {
                func_8002D6FC(D_800E9538[i]);
            }
        }
        D_800D1C00[1] = 0;
        obj[4] = 0;
        obj[5] = 0;
        func_800231B4();
        if (D_8009A0A0[0xF7] == 2) {
            D_8009A0A0[0xF7] = 1;
        }
        func_8002C2C0();
        func_8002BD8C();
        func_800272B4();
        return;
    }
}
