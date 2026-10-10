#include "types.h"

typedef struct Scr80 {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ s16 unk80;
    /* 0x82 */ s16 unk82;
    /* 0x84 */ u8 pad84[2];
    /* 0x86 */ s8 unk86;
} Scr80;

#define SCR (*(Scr80**)0x1F80004C)

extern s8 D_800F4EC0_ovl05[][32];

void func_800EF078_ovl05(Ent2* e) {
    switch (D_800F4EC0_ovl05[e->unk2][SCR->unk86]) {
    case 0:
    case 7:
    case 14:
        SCR->unk80 = -12;
        SCR->unk82 = 0;
        if (e->unk2 == 2) {
            SCR->unk80 *= -1;
        }
        break;
    case 1:
    case 8:
        SCR->unk80 = -12;
        SCR->unk82 = -12;
        if (e->unk2 == 2) {
            SCR->unk80 *= -1;
        }
        break;
    case 2:
    case 9:
        SCR->unk80 = 0;
        SCR->unk82 = -12;
        break;
    case 3:
        SCR->unk80 = 12;
        SCR->unk82 = -12;
        break;
    case 4:
    case 10:
        SCR->unk80 = 12;
        SCR->unk82 = 0;
        break;
    case 5:
    case 12:
        SCR->unk80 = 0;
        SCR->unk82 = 12;
        break;
    case 6:
    case 13:
        SCR->unk80 = -12;
        SCR->unk82 = 12;
        if (e->unk2 == 2) {
            SCR->unk80 *= -1;
        }
        break;
    case 11:
        SCR->unk80 = 12;
        SCR->unk82 = 12;
        break;
    }
}
