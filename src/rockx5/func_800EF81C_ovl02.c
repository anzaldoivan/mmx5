#include "types.h"

// from rockx5 800EF81C
typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[7];
    /* 0x0C */ s32 unkC; /* 16.16; hi half also stored as s16 at 0x0E */
    /* 0x10 */ u8 pad10[0x14];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[4];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x46];
    /* 0x76 */ s8 unk76;
    /* 0x77 */ u8 pad77[7];
    /* 0x7E */ s16 unk7E;
    /* 0x80 */ u8 pad80[4];
    /* 0x84 */ u8 unk84;
    /* 0x85 */ u8 unk85;
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
    /* 0x88 */ u8 unk88;
    /* 0x89 */ u8 unk89;
} Obj800EF81C;

extern Ent43AC D_800F43AC_ovl02[];

extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);
extern s32 func_8002DF78(void);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);

void func_800EF81C_ovl02(Obj800EF81C* p) {
    p->unk86++;
    p->unk86 = p->unk86 % p->unk89;
    p->unk87 = (p->unk87 + 1) & 0xF;
    p->unk88 = (p->unk88 + 1) & 7;
    if (p->unk76 != 0 && p->unk85 == 0) {
        p->unk2C = 0x1800;
        p->unk84 = 0x3C;
        p->unk85 = 1;
        p->unk24 <<= 1;
    }
    if (p->unk85 != 0) {
        p->unk86 = 0;
        if (p->unk84 == 0) {
            if (p->unk88 == 0) {
                func_8005019C(0x11, 0, p, 0x18, 2);
            }
        } else {
            p->unkC -= p->unk24;
            p->unk24 = -p->unk24;
            if (p->unk88 == 0) {
                func_8005019C(1, 0, p, 0x18, 1);
            }
            if (p->unk84 == 1) {
                p->unk24 = 0;
            }
        }
    } else if (p->unk86 < 0x28) {
        p->unk24 = -p->unk24;
    } else {
        p->unk84++;
        ((s16*)&p->unkC)[1] = p->unk7E;
    }
    if (p->unk87 == 0) {
        func_8005019C(1, 0, p, 0x18, 2);
        p->unk89 = (func_8002DF78() & 0x3F) + 0x20;
    }
    if (func_8002D938((u8*)p, (p->unk2 + D_800F43AC_ovl02)->unk8 + 0xA0,
                      0x30)) {
        p->unk4++;
    }
}
