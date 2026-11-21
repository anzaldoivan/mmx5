#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/ovl07.h"
#include "mmx5/ovl26.h"
#include "mmx5/system.h"
#include "addr.h"
#include "mmx5/movement.h"
#include "mmx5/ovl02.h"

#define D_800F4844_ovl05 D_80101508_ovl07

#define func_800EEA80_ovl05 func_800F6D80_ovl07
#include "shared/func_800EEA80_ovl05.c"
#undef func_800EEA80_ovl05
#undef D_800F4844_ovl05

#define D_800F3D88_ovl08 D_80101500_ovl07
#define D_800F3D8C_ovl08 D_80101504_ovl07

#define func_800F0E20_ovl08 func_800F6DBC_ovl07
#include "shared/func_800F0E20_ovl08.c"
#undef func_800F0E20_ovl08
#undef D_800F3D88_ovl08
#undef D_800F3D8C_ovl08

#define func_800F0EB8_ovl08 func_800F6E54_ovl07
#include "shared/func_800F0EB8_ovl08.c"
#undef func_800F0EB8_ovl08

#define D_800EEBA0_ovl00 func_800F6F40_ovl07
#define func_8002D720 clear_object_slot
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

#define D_800F9214_ovl26 D_80101578_ovl07
#define D_800F9238_ovl26 D_8010159C_ovl07
#define D_800F923C_ovl26 D_801015A0_ovl07
#define D_800F9240_ovl26 D_801015A4_ovl07
#define D_800F927C_ovl26 D_801015E0_ovl07
#define func_800F0318_ovl26 func_800F7EAC_ovl07

#define func_800EF3CC_ovl26 func_800F6F60_ovl07
#include "shared/func_800EF3CC_ovl26.c"
#undef func_800EF3CC_ovl26
#undef D_800F9214_ovl26
#undef D_800F9238_ovl26
#undef D_800F923C_ovl26
#undef D_800F9240_ovl26
#undef D_800F927C_ovl26
#undef func_800F0318_ovl26

#define D_800F44C0_ovl02 D_801016B8_ovl07

#define func_800EF0C8_ovl02 func_800F7218_ovl07
#include "shared/func_800EF0C8_ovl02.c"
#undef func_800EF0C8_ovl02
#undef D_800F44C0_ovl02

#define D_800F43AC_ovl02 D_801015A4_ovl07

#define func_800EF5D8_ovl02 func_800F7728_ovl07
#include "shared/func_800EF5D8_ovl02.c"
#undef func_800EF5D8_ovl02
#undef D_800F43AC_ovl02

#define D_800F43AC_ovl02 D_801015A4_ovl07

#define func_800EF714_ovl02 func_800F7864_ovl07
#include "shared/func_800EF714_ovl02.c"
#undef func_800EF714_ovl02
#undef D_800F43AC_ovl02

#define D_800F43AC_ovl02 D_801015A4_ovl07

#define func_800EF81C_ovl02 func_800F796C_ovl07
#include "shared/func_800EF81C_ovl02.c"
#undef func_800EF81C_ovl02
#undef D_800F43AC_ovl02

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
