#include "types.h"
#include "addr.h"

#define G D_1F80004C.bytes
void func_800F03F4_ovl00(u8* obj) {
    *(s32*)(G + 0x8C) = 0x10000;
    obj[6]++;
}

#define SCR0418 D_1F80004C.scr0418
void func_800F0418_ovl00(Obj* o) {
    Scr0418* s = SCR0418;

    if (s->unk88.h.hi >= 0x40 || s->unk87 != 0) {
        s->unk86 = 0x3C;
        o->step++;
        return;
    }
    s->unk88.w += s->unk8C;
    SCR0418->unk8C += 0x4000;
}

#define G D_1F80004C.bytes
void func_800F0494_ovl00(u8* arg0) {
    if (--G[0x86] == 0xFF) {
        *(s32*)(G + 0x8C) = 0x10000;
        arg0[6]++;
    }
}
