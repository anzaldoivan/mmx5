/* Shared body (DK-5), from the banked draft of func_800EFE60_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern u8 D_800FA758_ovl00[];

void DEDUP_NAME(Ent85* e) {
    if (--D_1F80004C.scr->unk86 == 0xFF) {
        D_1F80004C.scr->unk91 = 0;
        switch (e->unk2) {
        case 0:
            e->unk54 = D_800FA758_ovl00;
            e->unk5 = 5;
            e->unk6 = 0;
            break;
        case 1:
        case 2:
        case 3:
            e->unk5 = 6;
            e->unk6 = 0;
            break;
        case 16:
            e->unk5 = 2;
            e->unk6 = 0;
            break;
        }
    }
}
