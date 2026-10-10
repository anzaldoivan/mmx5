/* Shared body (DK-5), from the banked draft of func_800F0F18_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

typedef struct Ent0F18 {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
    u8 pad7[0x67 - 7];
    signed char unk67;
} Ent0F18;

#define SCRATCH_CTX (*(Ctx0F18**)0x1F80004C)

extern void func_80017248(Ent0F18*);
extern void func_8002DF54(Ent0F18*);

void DEDUP_NAME(Ent0F18* a0) {
    Ctx0F18* c;

    func_80017248(a0);
    func_8002DF54(a0);
    c = SCRATCH_CTX;
    if (--c->unk80 == 0) {
        a0->unk67 = -1;
        a0->unk5 = 6;
        a0->unk6 = 0;
    }
}
