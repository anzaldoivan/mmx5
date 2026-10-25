/* Shared body (DK-5), from the banked draft of func_800EF81C_ovl02 by tools/wave/gate.py rescan. */
#include "types.h"

extern Ent43AC D_800F43AC_ovl02[];

extern void func_8005019C(s32 a0, s32 a1, void* a2, s32 a3, s32 a4);
extern s32 func_8002DF78(void);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(Obj800EF81C* p) {
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
