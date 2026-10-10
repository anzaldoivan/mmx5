/* Shared body (DK-5), from the banked draft of func_800F150C_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

typedef struct {
    /* 0x00 */ Obj4FE0 b;
    /* 0x30 */ u8 pad30[0x7C - 0x30];
    /* 0x7C */ s16 unk7C;
    /* 0x7E */ s16 unk7E;
} Obj150C;

extern s16 D_8009A0AA;
extern void func_800171E8(Obj150C*, s32);
extern void func_80017248(Obj150C*);

void DEDUP_NAME(Obj150C* s) {
    if (D_8009A0AA - s->b.unkA > 0) {
        s->b.unk15 = 0x40;
    }
    func_800171E8(s, 1);
    func_80017248(s);
    s->unk7C = 0x28;
    s->unk7E = 0x20;
    s->b.unk20 = 0;
    s->b.unk28 = 0;
    s->b.unk24 = 0xFFFE0000;
    s->b.unk2C = 0;
    s->b.unk6++;
}
