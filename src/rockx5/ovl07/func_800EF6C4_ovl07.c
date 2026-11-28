#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8* func_8002D078();
extern s32 func_8002B5B4(s32);
extern void func_800F071C_ovl07(u8* p);
extern void func_800F05D8_ovl07(u8* obj);
extern void func_800EFC30_ovl07(u8* obj);
extern void func_800EFCE4_ovl07(u8* obj, s32 arg1);
extern u8 D_801008B0_ovl07[];
extern u8 D_801008B4_ovl07[];
extern u8 D_801008B8_ovl07[];
extern u8 D_801008BC_ovl07[];
extern u8 D_801008C0_ovl07[];
extern u8 D_801008C4_ovl07[];

static inline void func_800EF6C4_ovl07_snd(s32 v) {
    g_Player[6] = 0;
    g_Player[0xD8] = v;
}

static inline void func_800EF6C4_ovl07_snd2(s32 v) {
    g_Player[0xD8] = v;
    g_Player[6] = 0;
}

void func_800EF6C4_ovl07(u8* obj) {
    u8* p;
    s32 r;
    u8 v;
    u16 f;

    if (*(s8*)(obj + 6) != 5 && *(s16*)(obj + 0xA) > 0x1D50) {
        obj[6] = 5;
    }
    switch (*(s8*)(obj + 6)) {
    case 0:
        if (*(u16*)(obj + 0x8E) != 0) {
            obj[6] = 6;
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x2C) = 0;
        } else {
            obj[6] = 1;
        }
        obj[0x7F] = 1;
        *(s32*)(obj + 0x20) = 0x40000;
        *(s32*)(obj + 0x28) = -0x1000;
        obj[0x80] |= 1;
        *(s32*)(obj + 0x90) = 0x1000;
        *(s32*)(obj + 0x94) = 0;
        D_8009A1F8.u[*(s8*)(obj + 0x14) * 0x54 + 0x47] = 8;
        set_animation(obj, D_801008B0_ovl07[obj[0x82]]);
        func_800EF6C4_ovl07_snd(D_801008BC_ovl07[obj[0x82]]);
        apply_object_motion(obj);
        p = func_8002D078();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x39;
            *(u16*)(p + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(p + 0xE) = *(u16*)(obj + 0xE);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            r = func_8002B5B4(0x82);
            *(u16*)(p + 0x42) =
                ((r * 4 + 0x18) % 16) | ((((r + 6) / 4) + 0x1E0) << 6);
            p[0x16] = obj[0x16];
            *(u8**)(p + 0x7C) = obj;
            p[0x15] = obj[0x15];
        }
        break;
    case 1:
        if (*(s32*)(obj + 0x20) <= 0) {
            obj[6] = 4;
            set_animation(obj, D_801008B4_ovl07[obj[0x82]]);
            func_800EF6C4_ovl07_snd(D_801008C0_ovl07[obj[0x82]]);
            obj[0x7F] = 0;
            play_sound(5, 0x11, 0);
        } else if (obj[0x70] & 8) {
            func_800F071C_ovl07(obj);
            if (*(u16*)(obj + 0x8C) & 0x80) {
                obj[6] = 2;
                *(s32*)(obj + 0x24) = 0x68000;
                *(s32*)(obj + 0x2C) = 0x5000;
                *(s32*)(obj + 0x28) = 0;
                obj[0x80] |= 2;
            }
        } else {
            obj[6] = 3;
            *(s32*)(obj + 0x2C) = 0x5000;
        }
        func_800EFC30_ovl07(obj);
        animate_object(obj);
        break;
    case 2:
        func_800F05D8_ovl07(obj);
        break;
    case 3:
        if (obj[0x70] & 8) {
            obj[6] = 4;
            obj[0x67] = 0;
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x2C) = 0;
            *(s32*)(obj + 0x24) = 0;
            obj[0x7F] = 0;
            switch (obj[0x82]) {
            case 0:
                set_animation(obj, 5);
                func_800EF6C4_ovl07_snd2(0x46);
                break;
            case 1:
                set_animation(obj, 4);
                func_800EF6C4_ovl07_snd2(0x44);
                break;
            case 2:
                set_animation(obj, 3);
                func_800EF6C4_ovl07_snd2(0x42);
                break;
            }
        }
        func_800EFC30_ovl07(obj);
        break;
    case 4:
        if (*(s8*)(obj + 0x46) == 0) {
            obj[6] = 5;
        }
        func_800EFC30_ovl07(obj);
        animate_object(obj);
        break;
    case 5:
        obj[0x80] &= 0xFC;
        obj[0x7F] = 0;
        obj[5] = 1;
        obj[6] = 0;
        obj[0x7D] = 0;
        D_8009A1F8.u[*(s8*)(obj + 0x14) * 0x54 + 0x47] = 6;
        set_animation(obj, D_801008B8_ovl07[obj[0x82]]);
        func_800EF6C4_ovl07_snd(D_801008C4_ovl07[obj[0x82]]);
        apply_object_motion(obj);
        break;
    case 6:
        if (obj[0x70] & 8) {
            obj[0x99] = 1;
        } else {
            v = obj[0x81];
            if (v >= 0x38 || (u32)(v - 1) < 0x1F) {
                obj[0x99] = 1;
            }
        }
        if (*(s32*)(obj + 0x20) <= 0) {
            obj[6] = 3;
            *(s32*)(obj + 0x2C) = 0x5000;
            *(u16*)(obj + 0x8E) = 0;
            obj[0x99] = 0;
            play_sound(5, 0x11, 0);
        } else if (obj[0x99] == 0) {
            f = *(u16*)(obj + 0x8A);
            if (f & 4) {
                *(s32*)(obj + 0xC) -= 0x8000;
            } else if (f & 8) {
                *(s32*)(obj + 0xC) += 0x8000;
            }
        }
        func_800EFC30_ovl07(obj);
        animate_object(obj);
        break;
    }
    if (obj[0x7F] != 0) {
        func_800EFCE4_ovl07(obj, 3);
    } else {
        func_800EFCE4_ovl07(obj, 2);
    }
}
