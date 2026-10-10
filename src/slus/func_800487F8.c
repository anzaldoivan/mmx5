#include "types.h"

typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[4];
    s16 unkA;
    u8 padC[2];
    s16 unkE;
    u8 pad10[5];
    u8 unk15;
    u8 pad16[10];
    s32 unk20;
    s32 unk24;
    u8 pad28[0x1D];
    u8 unk45;
    u8 pad46[0xA];
    s32* unk50;
    u8 pad54[0x14];
    Unk800770CC* unk68;
    u8 pad6C[0x23];
    u8 unk8F;
    s16 unk90;
    s16 unk92;
    u8 unk94;
    u8 unk95;
} Ent487F8;

extern Unk800770CC D_800770CC[];
extern s32 D_800770B0[];

extern void func_80017248(Ent487F8*);
extern void func_8002DF54(Ent487F8*);
extern void* func_8003157C(Ent487F8*, s16, s16);
extern s32 func_80031630(void*);
extern void func_80017214(Ent487F8*, s32, s32);

void func_800487F8(Ent487F8* p) {
    Unk800770CC* e;
    s16 x;
    s16 y;
    s16 end;
    s32 r;
    s32 d;
    s32 s;
    s32 v;

    func_80017248(p);
    p->unk68 = &D_800770CC[p->unk45 & 0x3F];
    p->unk50 = &D_800770B0[p->unk45 & 0x3F];
    if (!(p->unk45 & 0x80)) {
        func_8002DF54(p);
    }
    if (p->unk15) {
        x = p->unkA - p->unk68->a;
        e = p->unk68;
    } else {
        x = p->unkA + p->unk68->a;
        e = p->unk68;
    }
    y = p->unk90;
    end = e->d + (p->unkE + e->b) - 1;
    r = 0;
    for (; y < end; y++) {
        if (func_80031630(func_8003157C(p, x, y))) {
            goto found;
        }
        if (func_80031630(func_8003157C(p, x + p->unk68->c - 1, y))) {
            goto found;
        }
        r = func_80031630(func_8003157C(p, x - p->unk68->c, y));
        if (r) {
            goto found;
        }
    }
    if (r != 0) {
    found:
        s = p->unk45 & 0x3F;
        d = p->unk92 - y;
        if (d >= 0 ? d >= 0x20 : y - p->unk92 >= 0x20) {
            func_80017214(p, 4, 0);
        } else {
            func_80017214(p, 4, 1);
        }
        if (s == 4) {
            p->unk90 = y - 8;
            p->unkE = y - 3;
        } else {
            p->unkE = p->unk90;
        }
        if (p->unk15) {
            p->unk95 = 1;
            v = 0x60000;
        } else {
            p->unk95 = 2;
            v = -0x60000;
        }
        p->unk20 = v;
        p->unk24 = 0;
        p->unk8F = 0;
        p->unk5++;
        p->unk50 = &D_800770B0[p->unk45 & 0x3F];
    } else {
        e = p->unk68;
        p->unk90 = (p->unkE + e->b) + e->d - 1;
        p->unk94 = p->unk45 & 0x3F;
    }
}
