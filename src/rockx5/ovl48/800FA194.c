#include "types.h"
#include "mmx5/globals.h"

#define func_800FA078_ovl43 func_800FA194_ovl48
#include "shared/func_800FA078_ovl43.c"
#undef func_800FA078_ovl43

extern void func_800177B0(s32, s32);

void func_800FA214_ovl48(u8* arg0) {
    func_800177B0(0x1A, 0x7F);
    arg0[1]++;
}

#define func_800FA128_ovl43 func_800FA24C_ovl48
#include "shared/func_800FA128_ovl43.c"
#undef func_800FA128_ovl43

extern u8 D_8009A2A3;

void func_800FA2D4_ovl48(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        D_8009A2A3 = 1;
        func_8002385C(0x23, 0xFF, 0);
        arg0->unk1++;
    }
}

extern u8 D_80091C44;

void func_800FA32C_ovl48(UnkObj* arg0) {
    u8* p;

    if (D_80091C44 == 0) {
        p = D_8009A1F8.u;
        *(s32*)(p + 0x5C) = 0;
        *(s32*)(p + 0x60) = 0;
        p[0x57] = 1;
        p[0xA0] = 1;
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

void func_800FA374_ovl48(Ovl45State* arg0) {
    D_8009A1F8.w[0x5C / 4] += 0xB3333;
    arg0->unk4++;
    if (arg0->unk4 >= 10) {
        D_8009A1F8.w[0x5C / 4] = 0x700000;
        func_8002385C(0x24, 0xFF, 0);
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}

#define func_800FA2C0_ovl43 func_800FA3F8_ovl48
#include "shared/func_800FA2C0_ovl43.c"
#undef func_800FA2C0_ovl43

extern void func_800FA004_ovl48(u8* obj);
extern s8 D_8009A424;
extern u8 D_800D1F3C;

void func_800FA444_ovl48(u8* obj) {
    s32 i;
    s32 a;
    s32 b;
    s32 c;

    if (D_800D1F3C == 0 && D_8009A424 == 0) {
        func_8001E668();
        D_8009A1F8.u[3] = 0;
        D_8009A1F8.u[0x57] = 0;
        D_8009A1F8.u[0xAB] = 0;
        func_8002C50C();
        for (i = 0; i < 16; i++) {
            obj[0x26 + i] = 0;
        }
        func_800FA004_ovl48(obj);
        if (obj[0xCB] & 0x80) {
            a = 9;
            b = 0xB;
            c = 0xFF;
        } else {
            a = 0xA;
            b = 0xC;
            c = 0xFF;
        }
        obj[0x194] = a;
        ((volatile u8*)obj)[0x195] =
            b; // !FAKE: volatile chain keeps the 0x1D store after 0x196
        ((volatile u8*)obj)[0x196] =
            c; // !FAKE: volatile chain keeps the 0x1D store after 0x196
        ((volatile u8*)obj)[0x1D] =
            a; // !FAKE: volatile chain keeps the 0x1D store after 0x196
        obj[0] = 0x13;
        obj[1] = 0;
        obj[2] = 0;
        obj[3] = 0;
    }
}
