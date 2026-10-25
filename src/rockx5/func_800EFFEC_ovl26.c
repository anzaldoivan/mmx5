#include "types.h"

extern s16 D_8009A202;
extern s16 D_8009A0AA;
extern Ent800F43E8 D_800F927C_ovl26[];
extern void func_800171E8(Obj800EFA30*, s32);
extern void func_800F0318_ovl26(Obj800EFA30*);

void func_800EFFEC_ovl26(Obj800EFA30* o) {
    s32 idx;

    if (D_8009A202 + 0x1A0 < o->xA) {
        idx = (D_8009A0AA - 0xD67) / 320;
        switch (idx) {
        case 0:
        case 1:
            o->x85 = 15;
            o->x80 = 0;
            break;
        case 2:
            o->x85 = 0;
            o->x80 = 0;
            o->xA = D_800F927C_ovl26[o->x85 + 1].x;
            o->xE = D_800F927C_ovl26[o->x85 + 1].y;
            break;
        case 3:
        case 4:
            o->x85 = 7;
            o->x80 = 0;
            o->xA = D_800F927C_ovl26[o->x85 + 1].x;
            o->xE = D_800F927C_ovl26[o->x85 + 1].y;
            break;
        }
    }
    if (o->x80 == 0) {
        if (o->x85 == 0 && o->x72 == 0 && D_8009A0AA < o->xA + 0x40) {
            o->x20 = 0;
            o->x24 = 0;
            return;
        }
        o->x85++;
        if (o->x85 == 16) {
            o->x85 = 0;
            func_800171E8(o, 1);
            o->xA = D_800F927C_ovl26[o->x85].x;
            o->xE = D_800F927C_ovl26[o->x85].y;
            func_800F0318_ovl26(o);
            return;
        }
        func_800F0318_ovl26(o);
        if (o->x72 & 8) {
            if (D_800F927C_ovl26[o->x85].a == 0) {
                if (D_800F927C_ovl26[o->x85].b > 0) {
                    func_800171E8(o, 5);
                } else {
                    func_800171E8(o, 6);
                }
            }
            if (D_800F927C_ovl26[o->x85].b == 0) {
                if (D_800F927C_ovl26[o->x85].a > 0) {
                    func_800171E8(o, 8);
                } else {
                    func_800171E8(o, 7);
                }
            }
        } else {
            if (D_800F927C_ovl26[o->x85].a == 0) {
                if (D_800F927C_ovl26[o->x85].b > 0) {
                    func_800171E8(o, 1);
                } else {
                    func_800171E8(o, 2);
                }
            }
            if (D_800F927C_ovl26[o->x85].b == 0) {
                if (D_800F927C_ovl26[o->x85].a > 0) {
                    func_800171E8(o, 4);
                } else {
                    func_800171E8(o, 3);
                }
            }
        }
    }
    o->x80--;
}
