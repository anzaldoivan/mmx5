#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void func_8002F460(Ent493F0*);

void func_80049608(Ent493F0* p) {
    animate_object(p);
    p->unk68 = &D_800770CC.e[p->unk45 & 0x3F];
    p->unk50 = &D_800770B0.w[p->unk45 & 0x3F];
    if (!(p->unk45 & 0x80)) {
        move_object(p);
    }
    if (p->unk45 & 0x40) {
        p->unk45 &= 0xBF;
        *(s16*)((u8*)p + 0xA) = p->unk90;
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
