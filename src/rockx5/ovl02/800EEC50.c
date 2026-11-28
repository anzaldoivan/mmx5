#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/ovl02.h"
#include "mmx5/ovl26.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/movement.h"
#include "mmx5/title.h"

extern void func_8002C1C8(void);
extern s32 D_80093DD0[];
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;

void func_800EEC50_ovl02(u8* arg) {
    s32 i;
    u8* p;

    *(s16*)(arg + 0x14) = -100;
    arg[4]++;
    g_playthrough_state.u[0x26] = 0;
    g_playthrough_state.u[0x27] = 0;
    *(s8*)(arg + 0x16) = -1;
    func_8002C1C8();
    D_80093E66 = 1;
    D_8009A42C = 1;
    D_800D50DC = 1;
    for (i = 2; i < 10; i++) {
        D_80093DD0[i] = -1;
    }
    D_80093DD0[1] = -0xF01;
    p = alloc_class6_slot();
    if (p != 0) {
        p[0] = 0x51;
        p[1] = 0xD;
    }
}

extern s8 D_800D1C26;

void func_8002B070(s32, s32, s32, s32, s32);

void func_800EED00_ovl02(u8* arg0) {
    if (++*(s16*)(arg0 + 0x14) == 0xB2) {
        func_8002B070(D_8009A1F8.h[5] - 0x30, D_8009A1F8.h[5] + 0x170,
                      D_8009A1F8.h[7] - 0x30, D_8009A1F8.h[7] + 0x120, 0);
    }
    if (*(s16*)(arg0 + 0x14) >= 0xB5) {
        D_800D1C26 = 1;
        *(s16*)(arg0 + 0x14) = 0;
        arg0[4]++;
        D_80093E68 = 0;
        D_8009A42E = 0;
        D_800D50DE = 0;
    }
}

extern X4_BackgroundObj D_8009A24C[3];

void func_800EEDA8_ovl02(u8* a0) {
    if (++*(s16*)(a0 + 0x14) >= 0xC9) {
        D_8009A24C[0].unk3 = 1;
        *(s16*)(a0 + 0x14) = 0;
        a0[4]++;
    }
}

#define D_800EEBA0_ovl00 func_800EEDF0_ovl02
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00

#define D_800F9214_ovl26 D_800F4380_ovl02
#define D_800F9238_ovl26 D_800F43A4_ovl02
#define D_800F923C_ovl26 D_800F43A8_ovl02
#define D_800F9240_ovl26 D_800F43AC_ovl02
#define D_800F927C_ovl26 D_800F43E8_ovl02
#define func_800F0318_ovl26 func_800EFD5C_ovl02

#define func_800EF3CC_ovl26 func_800EEE10_ovl02
#include "shared/func_800EF3CC_ovl26.c"
#undef func_800EF3CC_ovl26
#undef D_800F9214_ovl26
#undef D_800F9238_ovl26
#undef D_800F923C_ovl26
#undef D_800F9240_ovl26
#undef D_800F927C_ovl26
#undef func_800F0318_ovl26

#include "shared/func_800EF0C8_ovl02.c"

#include "shared/func_800EF5D8_ovl02.c"

#include "shared/func_800EF714_ovl02.c"

#include "shared/func_800EF81C_ovl02.c"

extern s16 D_8009A202;
extern Ent800F43E8 D_800F43E8_ovl02[];

void func_800EFA30_ovl02(Obj800EFA30* o) {
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
            o->xA = D_800F43E8_ovl02[o->x85 + 1].x;
            o->xE = D_800F43E8_ovl02[o->x85 + 1].y;
            break;
        case 3:
        case 4:
            o->x85 = 7;
            o->x80 = 0;
            o->xA = D_800F43E8_ovl02[o->x85 + 1].x;
            o->xE = D_800F43E8_ovl02[o->x85 + 1].y;
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
            o->xA = D_800F43E8_ovl02[o->x85].x;
            o->xE = D_800F43E8_ovl02[o->x85].y;
            func_800EFD5C_ovl02(o);
            return;
        }
        func_800EFD5C_ovl02(o);
        if (o->x72 & 8) {
            if (D_800F43E8_ovl02[o->x85].a == 0) {
                if (D_800F43E8_ovl02[o->x85].b > 0) {
                    set_animation(o, 5);
                } else {
                    set_animation(o, 6);
                }
            }
            if (D_800F43E8_ovl02[o->x85].b == 0) {
                if (D_800F43E8_ovl02[o->x85].a > 0) {
                    set_animation(o, 8);
                } else {
                    set_animation(o, 7);
                }
            }
        } else {
            if (D_800F43E8_ovl02[o->x85].a == 0) {
                if (D_800F43E8_ovl02[o->x85].b > 0) {
                    set_animation(o, 1);
                } else {
                    set_animation(o, 2);
                }
            }
            if (D_800F43E8_ovl02[o->x85].b == 0) {
                if (D_800F43E8_ovl02[o->x85].a > 0) {
                    set_animation(o, 4);
                } else {
                    set_animation(o, 3);
                }
            }
        }
    }
    o->x80--;
}
