/* Shared body (DK-5), from the banked draft of func_800F0418_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"

// from rockx5 800F0418: halves of the s32 at 0x88
typedef struct Half0418 {
    u16 lo;
    s16 hi;
} Half0418;

// from rockx5 800F0418: 0x88 read as s32 (lw) and its high half as s16 (lh 0x8A)
typedef union Fix0418 {
    s32 w;
    Half0418 h;
} Fix0418;

// from rockx5 800F0418
typedef struct Scr0418 {
    /* 0x00 */ u8 pad0[0x86];
    /* 0x86 */ u8 unk86;
    /* 0x87 */ u8 unk87;
    /* 0x88 */ Fix0418 unk88;
    /* 0x8C */ s32 unk8C;
} Scr0418;

#define SCR0418 (*(Scr0418**)0x1F80004C)

void DEDUP_NAME(Obj* o) {
    Scr0418* s = SCR0418;

    if (s->unk88.h.hi >= 0x40 || s->unk87 != 0) {
        s->unk86 = 0x3C;
        o->step++;
        return;
    }
    s->unk88.w += s->unk8C;
    SCR0418->unk8C += 0x4000;
}
