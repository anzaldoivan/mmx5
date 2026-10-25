/* Shared body (DK-5), from the banked draft of func_800493F0 by tools/wave/gate.py rescan. */
#include "types.h"

extern Unk800770CC D_800770CC[];
extern s32 D_800770B0[];

extern void func_80017248(Ent493F0*);
extern void func_8002DF54(Ent493F0*);
extern void func_8002F460(Ent493F0*);

void DEDUP_NAME(Ent493F0* p) {
    func_80017248(p);
    p->unk68 = &D_800770CC[p->unk45 & 0x3F];
    p->unk50 = &D_800770B0[p->unk45 & 0x3F];
    if (!(p->unk45 & 0x80)) {
        func_8002DF54(p);
    }
    if (p->unk45 & 0x40) {
        p->unk45 &= 0xBF;
        p->unkE = p->unk90;
    }
    if (!((signed char)p->unk45 & 0x80)) {
        p->unk70 = 0;
        func_8002F460(p);
        if (p->unk8F == 0) {
            if (p->unk70 & p->unk95) {
                p->unk4 = 2;
            }
        } else {
            p->unk8F--;
        }
    }
}
