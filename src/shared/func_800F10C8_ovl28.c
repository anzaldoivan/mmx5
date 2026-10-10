/* Shared body (DK-5), from the banked draft of func_800F10C8_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

typedef struct Scr10C8 {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ s8 unk80;
    /* 0x81 */ u8 pad81[2];
    /* 0x83 */ s8 unk83;
} Scr10C8;

#define SCR10C8 (*(Scr10C8**)0x1F80004C)

void DEDUP_NAME(Ent08D8* e) {
    Scr10C8* s = SCR10C8;

    if (s->unk80 == 0) {
        if (++s->unk83 >= 2) {
            e->unk5 = 5;
            e->unk6 = 0;
            SCR10C8->unk83 = 0;
        } else {
            e->unk5 = 3;
            e->unk6 = 0;
        }
    } else {
        s->unk80--;
    }
}
