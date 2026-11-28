#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void func_8002002C(s32);
extern void func_80013288(s32);
extern s16 func_8001FF18(void*, s32);
extern u8 D_8009A427;
extern u8 D_80070F68[];

void func_8002187C(Obj80021650* arg0) {
    func_8001E668();
    D_8009A427 = 0;
    arg0->unk1F = 0;
    arg0->unk24 = 0;
    func_8002002C(0);
    func_80013288(8);
    arg0->unk8 = func_8001FF18(D_80070F68, 1);
    arg0->unk1++;
}

#define D_8009A420_as_Sel800218E0 (*(Sel800218E0*)&D_8009A420)
#define D_800C931C_as_Pad800218E0 (*(Pad800218E0*)&g_pad1_buttons)

extern void func_800132F8(s8 arg);

void func_800218E0(Arg800218E0* a) {
    s16 lim;
    signed char* p;

    if (D_8009A420_as_Sel800218E0.unk4 == 0) {
        p = &D_8009A420_as_Sel800218E0.unk7.s;
        lim = a->unk8;
        if (D_800C931C_as_Pad800218E0.unk4 & 0x1000) {
            play_sound(0, 0xC, 0);
            if (D_8009A420_as_Sel800218E0.unk7.s == 0) {
                D_8009A420_as_Sel800218E0.unk7.s = lim;
            } else {
                D_8009A420_as_Sel800218E0.unk7.s--;
            }
        }
        if (D_800C931C_as_Pad800218E0.unk4 & 0x4000) {
            play_sound(0, 0xC, 0);
            if (*p == lim) {
                *p = 0;
            } else {
                (*p)++;
            }
        }
        if (D_800C931C_as_Pad800218E0.unk4 & 0x40) {
            play_sound(0, 0x22, 0);
            if (D_8009A420_as_Sel800218E0.unk7.u != 0) {
                func_800132F8(8);
            }
            a->unk1++;
        }
    }
}
#undef D_8009A420_as_Sel800218E0
#undef D_800C931C_as_Pad800218E0

extern void func_8002002C(s32);

void func_80021A1C(u8* arg0) {
    u8* p = D_8009A420;

    if (((signed char*)p)[4] == 0) {
        if (p[7] == 0) {
            arg0[0] = 0x12;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
        } else {
            arg0[0] = 0xC;
            arg0[1] = 5;
            arg0[2] = 2;
            func_8002002C(1);
        }
    }
}

extern s16 func_8001FF18(void*, s32);
extern u8 D_80070F68[];
extern u8 D_8009A427;

void func_80021A90(u8* arg0) {
    ((s32(*)())func_8002C50C)();
    D_8009A427 = 0;
    *(s16*)(arg0 + 8) = func_8001FF18(D_80070F68, 1);
    arg0[1] = 1;
}
