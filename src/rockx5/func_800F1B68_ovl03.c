#include "types.h"
#include "addr.h"

#define SCR D_1F80004C.scr80
extern s8 D_800F9B94_ovl03[][32];

void func_800F1B68_ovl03(Ent2* e) {
    switch (D_800F9B94_ovl03[e->unk2][SCR->unk86]) {
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
