#include "types.h"

extern Unk800770CC D_800770CC[];
extern s32 D_800770B0[];

extern void func_80017248(Ent487F8*);
extern void func_8002DF54(Ent487F8*);
extern void* func_8003157C(Ent487F8*, s16, s16);
extern s32 func_80031630(void*);
extern void func_80017214(Ent487F8*, s32, s32);

void func_80048AE0(Ent487F8* p) {
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
    end = (p->unkE + e->b) - e->d;
    r = 0;
    for (; end < y; y--) {
        if (func_80031630(func_8003157C(p, x, y))) {
            goto found; // !FAKE: goto kept for the matching branch layout
        }
        if (func_80031630(func_8003157C(p, x + p->unk68->c - 1, y))) {
            goto found; // !FAKE: goto kept for the matching branch layout
        }
        r = func_80031630(func_8003157C(p, x - p->unk68->c, y));
        if (r) {
            goto found; // !FAKE: goto kept for the matching branch layout
        }
    }
    if (r != 0) {
    found:
        s = p->unk45 & 0x3F;
        d = p->unk92 - y;
        if (d >= 0 ? d >= 0x22 : y - p->unk92 >= 0x22) {
            func_80017214(p, 5, 0);
        } else {
            func_80017214(p, 5, 1);
        }
        if (s == 6) {
            p->unk90 = y + 9;
            p->unkE = y + 4;
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
        Unk800770CC* f = p->unk68;
        p->unk90 = (p->unkE + f->b) - f->d;
        p->unk94 = p->unk45 & 0x3F;
    }
}
