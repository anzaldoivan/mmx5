#include "types.h"
#include "mmx5/object.h"

void func_8002DCD8(Obj8002CC08* p) {
    u8* q;
    s32 i;
    s32 k;
    s32 idx;
    s32 j;
    u32 mask;
    Obj8002CD14* o;
    u32* w;
    u32* b;

    q = (u8*)p;
    for (i = sizeof(Obj8002CC08) - 1; i != -1; i--) {
        *q++ = 0;
    }
    p->unk50 = 0;
    p->unk54.w = 0;
    p->unk68 = 0;
    idx = ((u32)p - (u32)D_80092090) / sizeof(Obj8002CC08);
    j = idx / 32;
    mask = ~(1 << (idx & 31));
    o = g_class4_slots.cd14;
    j *= 4;
    b = (u32*)&o->pad6C[0x2C];
    w = (u32*)((u8*)b + j);
    for (k = 0x3F; k >= 0; k--) {
        *w &= mask;
        w = (u32*)((u8*)w + sizeof(Obj8002CD14));
    }
}
