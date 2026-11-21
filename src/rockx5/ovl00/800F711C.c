#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"

extern void func_800F6D58_ovl00(s32);
extern u16 D_80093E68;
extern u16 D_8009A42E;
extern u16 D_800D50DE;
extern s32 D_800FB694_ovl00;
extern s32 D_800FB698_ovl00;

void func_800F711C_ovl00(u8* arg0) {
    s16 t;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        if (++D_800FB694_ovl00 == 3) {
            play_sound(0, 5, arg0);
        }
        switch (D_800FB694_ovl00) {
        case 0:
            *(s16*)(arg0 + 0x7C) = 0x5A;
            break;
        case 1:
            *(s16*)(arg0 + 0x7C) = 0x46;
            break;
        case 2:
            *(s16*)(arg0 + 0x7C) = 0x32;
            break;
        default:
            *(s16*)(arg0 + 0x7C) = 0x78;
            break;
        }
    }
    if (D_800FB694_ovl00 == 0) {
        if (*(s16*)(arg0 + 0x7C) < 0x28) {
            func_800F6D58_ovl00(0);
            if (!(D_800FB698_ovl00 & 1)) {
                play_sound(2, 3, arg0);
                D_800FB698_ovl00 |= 1;
            }
        }
    } else if (D_800FB694_ovl00 >= 0 && D_800FB694_ovl00 < 3) {
        func_800F6D58_ovl00(0);
    }
    if (D_800FB694_ovl00 == 1) {
        if (*(s16*)(arg0 + 0x7C) < 0x46) {
            func_800F6D58_ovl00(1);
            if (!(D_800FB698_ovl00 & 2)) {
                play_sound(2, 3, arg0);
                D_800FB698_ovl00 |= 2;
            }
        }
    } else if (D_800FB694_ovl00 >= 1 && D_800FB694_ovl00 < 3) {
        func_800F6D58_ovl00(1);
    }
    if (D_800FB694_ovl00 == 2) {
        if (*(s16*)(arg0 + 0x7C) < 0x46) {
            func_800F6D58_ovl00(2);
            if (!(D_800FB698_ovl00 & 4)) {
                play_sound(2, 3, arg0);
                D_800FB698_ovl00 |= 4;
            }
        }
    }
    if (D_800FB694_ovl00 == 3) {
        func_800F6D58_ovl00(3);
    }
    if (D_800FB694_ovl00 >= 3) {
        if (!(*(u16*)(arg0 + 0x7E) & 7)) {
            func_8004FD90(arg0, 1, 0x3F, 0x3F);
        }
        t = ++*(s16*)(arg0 + 0x7E);
        if (t % 5 == 0) {
            D_800D50DE++;
            D_8009A42E += 0x20;
            D_80093E68 += 0x400;
            if (D_800D50DE == 0x1F) {
                *(s16*)(arg0 + 0x7C) = 0x78;
                *(s16*)(arg0 + 0xA) += 0x20;
                arg0[6] += 3;
            }
        }
    }
}

extern u8 D_800D1C00[];

void func_800F741C_ovl00(u8* obj) {
    u8* p;

    if (*(s16*)(obj + 0xE) >= 0x11C) {
        *(s16*)(obj + 0xE) = 0x11C;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        D_800D1C00[0x24] = 1;
        *(s16*)(obj + 0x7C) = 3;
        obj[6]++;
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x37;
        }
        func_8002385C(1, 0xFF, D_800D1C00[0x2E]);
        D_800D1C00[0x2E] = 1;
        D_800D1C00[0x16] = 1;
        D_800D1C00[0x13] = 1;
        D_800D1C00[0x19] = 1;
        D_800D1C00[0x18] = 1;
        D_800D1C00[0x17] = 1;
        D_800D1C00[0x14] = 1;
        D_800D1C00[0x15] = 1;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}

extern s32 func_80044DE0();
extern u8 D_80091C44;
extern u8 D_8009A240;
extern u8 D_800D1C00[];
extern u8 D_800FB3D8_ovl00[];

void func_800F74FC_ovl00(u8* obj) {
    s32 t;

    func_8002D9EC(obj, 0xFF, 0xFF);
    if (D_80091C44 == 0 && func_80044DE0() == 0) {
        D_800D1C00[0x16] = 0;
        D_800D1C00[0x13] = 0;
        D_800D1C00[0x19] = 0;
        D_800D1C00[0x18] = 0;
        D_800D1C00[0x17] = 0;
        D_800D1C00[0x14] = 0;
        D_800D1C00[0x15] = 0;
        if (*(s8*)(obj + 0x5C) < *(s8*)(D_800D1C00 + 0xA2)) {
            t = *(u16*)(obj + 0x7C) - 1;
            *(u16*)(obj + 0x7C) = t;
            if ((t << 16) == 0) {
                play_sound(0, 0xE, 0);
                *(u16*)(obj + 0x7C) = 3;
            }
            obj[0x5C]++;
            func_8002D9EC(obj, 0xFF, 0xFF);
            return;
        }
        set_animation(obj, 0);
        *(u8**)(obj + 0x68) = D_800FB3D8_ovl00;
        func_8003D2C4();
        D_8009A240 = 4;
        func_8002D9EC(obj, 0xFF, 0xFF);
        obj[5] = 4;
        obj[6] = 0;
    }
}
