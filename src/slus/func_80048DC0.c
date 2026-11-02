#include "types.h"

extern Unk800770CC D_800770CC[];
extern s32 D_800770B0[];

extern void func_80017248(Ent487F8*);
extern void func_8002DF54(Ent487F8*);
extern void* func_8003157C(Ent487F8*, s16, s16);
extern s32 func_80031630(void*);
extern void func_80017214(Ent487F8*, s32, s32);

void func_80048DC0(Ent487F8* p) {
    Unk800770CC* e;
    s16 x;
    s16 y;
    s16 end;
    s32 step;
    s32 r;
    s32 d;
    s16 t;
    s16 u;

    func_80017248(p);
    p->unk68 = &D_800770CC[p->unk45 & 0x3F];
    p->unk50 = &D_800770B0[p->unk45 & 0x3F];
    if (!(p->unk45 & 0x80)) {
        func_8002DF54(p);
    }
    e = p->unk68;
    x = p->unk90;
    y = p->unkE + e->b;
    if (p->unk15) {
        t = e->c + (p->unkA - e->a) - 1;
    } else {
        t = (p->unkA + e->a) - e->c;
    }
    end = t;
    t = 0; // !FAKE: dead reset keeps the end copy (C0070)
    step = -1;
    if (x < end) {
        step = 1;
    }
    r = 0;
    for (; x != end; x += step) {
        if (func_80031630(func_8003157C(p, x, y))) {
            goto found; // !FAKE: goto kept for the matching branch layout
        }
        if (func_80031630(func_8003157C(p, x, y - p->unk68->d))) {
            goto found; // !FAKE: goto kept for the matching branch layout
        }
        r = func_80031630(func_8003157C(p, x, p->unk68->d + y - 1));
        if (r) {
            goto found; // !FAKE: goto kept for the matching branch layout
        }
    }
    if (r != 0) {
    found:
        d = p->unk92 - x;
        if (d >= 0 ? d >= 0x18 : x - p->unk92 >= 0x18) {
            func_80017214(p, 3, 0);
        } else {
            func_80017214(p, 3, 1);
        }
        p->unk95 = 4;
        if (p->unk15) {
            p->unk90 = x - 9;
        } else {
            p->unk90 = x + 9;
        }
        p->unk24 = 0x60000;
        p->unkA = x;
        p->unk20 = 0;
        r = 1; // !FAKE: the 1 shares r's pseudo (a0), keeps the sb 0x8F late
        p->unk8F = r;
        p->unk5++;
        p->unk50 = &D_800770B0[p->unk45 & 0x3F];
    } else {
        if (p->unk15) {
            u = p->unk68->c + (p->unkA - p->unk68->a) - 1;
        } else {
            u = (p->unkA + p->unk68->a) - p->unk68->c;
        }
        p->unk90 = u;
        p->unk94 = p->unk45 & 0x3F;
    }
}
