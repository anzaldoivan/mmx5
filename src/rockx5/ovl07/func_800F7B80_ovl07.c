#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern s16 D_8009A202;
extern Ent800F43E8 D_801015E0_ovl07[];

void func_800F7B80_ovl07(Obj800EFA30* o) {
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
            o->xA = D_801015E0_ovl07[o->x85 + 1].x;
            o->xE = D_801015E0_ovl07[o->x85 + 1].y;
            break;
        case 3:
        case 4:
            o->x85 = 7;
            o->x80 = 0;
            o->xA = D_801015E0_ovl07[o->x85 + 1].x;
            o->xE = D_801015E0_ovl07[o->x85 + 1].y;
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
            set_animation(o, 1);
            o->xA = D_801015E0_ovl07[o->x85].x;
            o->xE = D_801015E0_ovl07[o->x85].y;
            func_800F7EAC_ovl07(o);
            return;
        }
        func_800F7EAC_ovl07(o);
        if (o->x72 & 8) {
            if (D_801015E0_ovl07[o->x85].a == 0) {
                if (D_801015E0_ovl07[o->x85].b > 0) {
                    set_animation(o, 5);
                } else {
                    set_animation(o, 6);
                }
            }
            if (D_801015E0_ovl07[o->x85].b == 0) {
                if (D_801015E0_ovl07[o->x85].a > 0) {
                    set_animation(o, 8);
                } else {
                    set_animation(o, 7);
                }
            }
        } else {
            if (D_801015E0_ovl07[o->x85].a == 0) {
                if (D_801015E0_ovl07[o->x85].b > 0) {
                    set_animation(o, 1);
                } else {
                    set_animation(o, 2);
                }
            }
            if (D_801015E0_ovl07[o->x85].b == 0) {
                if (D_801015E0_ovl07[o->x85].a > 0) {
                    set_animation(o, 4);
                } else {
                    set_animation(o, 3);
                }
            }
        }
    }
    o->x80--;
}
