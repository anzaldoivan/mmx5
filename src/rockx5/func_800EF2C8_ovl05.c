#include "types.h"

typedef struct Scr85 {
    /* 0x00 */ u8 pad0[0x85];
    /* 0x85 */ s8 unk85;
    /* 0x86 */ s8 unk86;
} Scr85;

#define SCR (*(Scr85**)0x1F80004C)

extern u8 D_8009A0A0[];
extern s8 D_800F4EC0_ovl05[][32];
extern s8 func_8002E024(Ent2*, u8*);
extern void func_800171E8(Ent2*, s32);

void func_800EF2C8_ovl05(Ent2* e) {
    if (SCR->unk85 != 0) {
        SCR->unk85--;
        return;
    }
    SCR->unk86 = func_8002E024(e, D_8009A0A0);
    func_800171E8(e, D_800F4EC0_ovl05[e->unk2][SCR->unk86]);
}
