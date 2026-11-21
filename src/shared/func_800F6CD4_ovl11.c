#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

extern u8 D_800D1C00[];
extern signed char D_8009A0A5;
extern u8 D_8009A1F8[];
extern u8 D_800FA064_ovl11[];
extern u8* alloc_class3_slot(void);

void func_800F6CD4_ovl11(u8* obj) {
    u8* g = D_800D1C00;
    u8* child;

    if (((signed char*)g)[0xF] == 0 && D_8009A0A5 == 0x14) {
        D_8009A1F8[0x47] = 2;
        D_800FA064_ovl11[2] = D_8009A1F8[0x48];
        if (((signed char*)g)[0xC] != 0xC) {
            g[0x27] = 1;
            func_8003D29C(0x1D, 0x40);
        }
        child = alloc_class3_slot();
        if (child != 0) {
            child[0] = 1;
            child[1] = 0x18;
            *(u8**)(D_1F80004C.bytes + 0x84) = child;
        }
        *(s16*)(obj + 0x7C) = 0xF0;
        obj[6]++;
    }
}

void func_800F6D98_ovl11(u8* obj) {
    move_object(obj);
    animate_object(obj);
    if (obj[0x70] & 8) {
        set_animation(obj, 13);
        obj[6]++;
    }
}

extern s32 func_8002DC14(void);
extern u8 D_800D1C00[];

void func_800F6DF0_ovl11(u8* obj) {
    animate_object(obj);
    if ((s8)obj[0x45] == 2) {
        obj[0x15] = 0;
        obj[6]++;
        if ((s8)D_800D1C00[0xC] != 12) {
            if (func_8002DC14() == 0) {
                func_8002385C(0x6C, 0xFF, D_800D1C00[0x2E]);
            } else if (func_8002DC14() == 1) {
                func_8002385C(0x32, 0xFF, D_800D1C00[0x2E]);
            } else {
                func_8002385C(0x64, 0xFF, D_800D1C00[0x2E]);
            }
            D_800D1C00[0x2E] = 1;
        }
    }
}

extern u8 D_80091C44;
extern void func_80044DD0(s32 a0);

void func_800F6EA8_ovl11(u8* obj) {
    if (D_80091C44 == 0) {
        func_80044DD0(0);
        *(s16*)(obj + 0x7E) = 10;
        obj[6]++;
    }
}

extern s32 func_80044DE0();
extern signed char D_800D1C0C;
extern u8 D_8009A240;

void func_800F6EF0_ovl11(u8* obj) {
    if (func_80044DE0() == 0) {
        if (D_800D1C0C == 12 && *(s16*)(obj + 0x7E) != 0) {
            *(s16*)(obj + 0x7E) -= 1;
        } else {
            D_8009A240 = 2;
            *(s16*)(obj + 0x7C) = 2;
            obj[6]++;
        }
    }
}
