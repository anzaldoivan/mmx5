#include "types.h"
#include "mmx5/object.h"
#include "addr.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

void func_800FC214_ovl39(u8* arg0) {
    if ((s16)(++*(s16*)(arg0 + 0x7C) % 5) == 0) {
        D_800D50DE++;
        D_8009A42E += 0x20;
        D_80093E68 += 0x400;
        if (D_800D50DE == 0x1F) {
            *(u16*)(arg0 + 0x7C) = 0x78;
            *(u16*)(arg0 + 0x7E) = 0;
            arg0[6]++;
            D_8009A1F8.u[0x3] = 0;
            D_8009A1F8.u[0x57] = 0;
            D_8009A1F8.u[0xAB] = 0;
        }
    }
}

extern u8* alloc_class3_slot(void);
extern signed char D_8009A0A5;

void func_800FC2CC_ovl39(Obj3DD4* a) {
    u8* p;

    if (D_8009A0A5 == 0x14) {
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(u8**)(D_1F80004C.bytes + 0x80) = p;
        }
    }
    a->unk6++;
}

void func_800FC338_ovl39(u8* a0) {
    if (D_8009A0AA >= 0x1211) {
        func_8003D29C(0x1D, 0);
    } else {
        func_8003D29C(0x1D, 0x40);
    }
    a0[6]++;
}

void func_800FC394_ovl39(u8* a0) {
    u8* p = g_Player;

    if ((p[0x15] == 0 && *(s16*)(p + 0xA) < 0x1211) ||
        (p[0x15] == 0x40 && *(s16*)(p + 0xA) >= 0x1210)) {
        ((s32(*)())func_8003D29C)(0x14, g_Player[0x15]);
        a0[6]++;
    }
}

void func_800FC41C_ovl39(u8* arg0) {
    u8* p;

    if (**(s8**)(D_1F80004C.bytes + 0x80) == 0) {
        p = D_1F80009C;
        p += *(s32*)p;
        arg0[6]++;
        *(u8**)(arg0 + 0x3C) = p;
    }
}

void func_800FC468_ovl39(u8* obj) {
    u8* p = g_playthrough_state.u;
    func_8002385C(0x49, 0xFF, p[0x2F]);
    p[0x2F] = 1;
    obj[6]++;
}

#define func_800FBC24_ovl38 func_800FC4BC_ovl39
#include "shared/func_800FBC24_ovl38.c"
#undef func_800FBC24_ovl38

extern s32 func_80044DE0();
extern u8 D_800FEB60_ovl39[];

void func_800FC500_ovl39(u8* arg0) {
    if (func_80044DE0() == 0) {
        func_80028B18(0, 0x1170, 0x790, D_800FEB60_ovl39);
        D_8009A1F8.u[0x3] = 1;
        D_8009A1F8.u[0x57] = 1;
        D_8009A1F8.u[0xAB] = 1;
        D_8009A1F8.u[0x58] = 2;
        *(s16*)(D_8009A1F8.u + 0x94) = 0;
        *(s16*)(D_8009A1F8.u + 0x96) = 0;
        D_8009A1F8.u[0xA0] = 1;
        D_8009A1F8.u[0x4C] = 1;
        arg0[6]++;
    }
}

void func_800FC580_ovl39(u8* arg0) {
    if ((s16)(++*(s16*)(arg0 + 0x7C) % 5) == 0) {
        D_800D50DE--;
        D_8009A42E -= 0x20;
        D_80093E68 -= 0x400;
        if (D_800D50DE == 0) {
            D_800C9310.b = 1;
            arg0[6]++;
        }
    }
}

void func_800FC624_ovl39(u8* obj) {
    u8* p = g_playthrough_state.u;
    func_8002385C(0x54, 0xFF, p[0x30]);
    p[0x30] = 1;
    obj[6]++;
}

extern s32 func_80024548(s32);
extern u8 D_80091C44;

void func_800FC678_ovl39(u8* obj) {
    u8* p;
    if (D_80091C44 == 0) {
        p = g_playthrough_state.u;
        p[0x24] = 1;
        p[0x25] = 1;
        *(u8**)(p + 0x20) = obj;
        p[0xA2] = 0x60;
        func_80024548(-1);
        obj[6]++;
    }
}

extern u8* func_8002D210();

void func_800FC6DC_ovl39(u8* a0) {
    s32 i;
    u8* o;

    for (i = 0; i < 2; i++) {
        o = func_8002D210();
        if (o != 0) {
            o[0] = 0x61;
            o[1] = 0x1D;
            o[2] = i;
            *(u16*)(o + 0x40) = *(u16*)(a0 + 0x40);
            *(s32*)(o + 0x30) = *(s32*)(a0 + 0x30);
            *(s32*)(o + 0x3C) = *(s32*)(a0 + 0x3C);
            *(u16*)(o + 0x42) = *(u16*)(a0 + 0x42) & 0x7FFF;
            *(u8**)(o + 0x7C) = a0;
            o[4] = 0;
        }
    }
    a0[7] = 0x11;
    *(s16*)(a0 + 0x7C) = 2;
    a0[6]++;
}

#define func_800FA09C_ovl27 func_800FC7A0_ovl39
#include "shared/func_800FA09C_ovl27.c"
#undef func_800FA09C_ovl27

void func_800FC830_ovl39(u8* arg0) {
    D_1F80004C.bytes[0x85] = 1;
    D_1F80004C.bytes[0x88] = 1;
    arg0[5] = 6;
    arg0[6] = 0;
}

#define D_800EEC60_ovl00 func_800FC85C_ovl39
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

#define D_800EEC60_ovl00 func_800FC864_ovl39
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
