#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/ovl28.h"
#include "mmx5/ovl26.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/movement.h"
#include "mmx5/ovl02.h"
#include "mmx5/title.h"

#define D_800EFA68_ovl21 D_800FE854_ovl28

#define func_800EF26C_ovl21 func_800FBB64_ovl28
#include "shared/func_800EF26C_ovl21.c"
#undef func_800EF26C_ovl21
#undef D_800EFA68_ovl21

#define func_800EF93C_ovl05 func_800FBBB0_ovl28
#include "shared/func_800EF93C_ovl05.c"
#undef func_800EF93C_ovl05

#define D_800EEBA0_ovl00 func_800FBC10_ovl28
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800F9214_ovl26 D_800FE8C4_ovl28
#define D_800F9238_ovl26 D_800FE8E8_ovl28
#define D_800F923C_ovl26 D_800FE8EC_ovl28
#define D_800F9240_ovl26 D_800FE8F0_ovl28
#define D_800F927C_ovl26 D_800FE92C_ovl28
#define func_800F0318_ovl26 func_800FCB7C_ovl28

#define func_800EF3CC_ovl26 func_800FBC30_ovl28
#include "shared/func_800EF3CC_ovl26.c"
#undef func_800EF3CC_ovl26
#undef D_800F9214_ovl26
#undef D_800F9238_ovl26
#undef D_800F923C_ovl26
#undef D_800F9240_ovl26
#undef D_800F927C_ovl26
#undef func_800F0318_ovl26

#define D_800F44C0_ovl02 D_800FEA04_ovl28

#define func_800EF0C8_ovl02 func_800FBEE8_ovl28
#include "shared/func_800EF0C8_ovl02.c"
#undef func_800EF0C8_ovl02
#undef D_800F44C0_ovl02

#define D_800F43AC_ovl02 D_800FE8F0_ovl28

#define func_800EF5D8_ovl02 func_800FC3F8_ovl28
#include "shared/func_800EF5D8_ovl02.c"
#undef func_800EF5D8_ovl02
#undef D_800F43AC_ovl02

#define D_800F43AC_ovl02 D_800FE8F0_ovl28

#define func_800EF714_ovl02 func_800FC534_ovl28
#include "shared/func_800EF714_ovl02.c"
#undef func_800EF714_ovl02
#undef D_800F43AC_ovl02

#define D_800F43AC_ovl02 D_800FE8F0_ovl28

#define func_800EF81C_ovl02 func_800FC63C_ovl28
#include "shared/func_800EF81C_ovl02.c"
#undef func_800EF81C_ovl02
#undef D_800F43AC_ovl02

extern s16 D_8009A202;
extern Ent800F43E8 D_800FE92C_ovl28[];

void func_800FC850_ovl28(Obj800EFA30* o) {
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
            o->xA = D_800FE92C_ovl28[o->x85 + 1].x;
            o->xE = D_800FE92C_ovl28[o->x85 + 1].y;
            break;
        case 3:
        case 4:
            o->x85 = 7;
            o->x80 = 0;
            o->xA = D_800FE92C_ovl28[o->x85 + 1].x;
            o->xE = D_800FE92C_ovl28[o->x85 + 1].y;
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
            o->xA = D_800FE92C_ovl28[o->x85].x;
            o->xE = D_800FE92C_ovl28[o->x85].y;
            func_800FCB7C_ovl28(o);
            return;
        }
        func_800FCB7C_ovl28(o);
        if (o->x72 & 8) {
            if (D_800FE92C_ovl28[o->x85].a == 0) {
                if (D_800FE92C_ovl28[o->x85].b > 0) {
                    set_animation(o, 5);
                } else {
                    set_animation(o, 6);
                }
            }
            if (D_800FE92C_ovl28[o->x85].b == 0) {
                if (D_800FE92C_ovl28[o->x85].a > 0) {
                    set_animation(o, 8);
                } else {
                    set_animation(o, 7);
                }
            }
        } else {
            if (D_800FE92C_ovl28[o->x85].a == 0) {
                if (D_800FE92C_ovl28[o->x85].b > 0) {
                    set_animation(o, 1);
                } else {
                    set_animation(o, 2);
                }
            }
            if (D_800FE92C_ovl28[o->x85].b == 0) {
                if (D_800FE92C_ovl28[o->x85].a > 0) {
                    set_animation(o, 4);
                } else {
                    set_animation(o, 3);
                }
            }
        }
    }
    o->x80--;
}
