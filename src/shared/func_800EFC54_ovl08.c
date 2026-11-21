#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

extern u8 D_80074EE0[];
extern u8 D_800750C0[];
extern void* D_800F3D30_ovl08[];
extern s32 D_800F4000_ovl08;
extern s32 D_800F4004_ovl08;
extern s32 D_800F4008_ovl08;
extern s32 D_800F400C_ovl08;
extern u8 D_800F3B68_ovl08[];
extern u8 D_800F3B80_ovl08[];
extern u8 D_800F3B84_ovl08[];
extern u8 D_800F3B88_ovl08[];
extern u8 D_800F3D18_ovl08[];
extern void func_80054440(u8* a0, s32 a1);
extern void silence_sound(s32, s32);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);

void func_800EFC54_ovl08(u8* obj) {
    u8* g = g_Player;
    s32 st;
    s32 r;
    u8* q;

    if (g[0xF7] == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        ((void (*)(u8*))D_800F3D30_ovl08[((s8*)obj)[5]])(obj);
    }
    st = ((s8*)obj)[5];
    if (st != 3) {
        *(s32*)(obj + 0x84) = *(s32*)(g + 0x8);
        *(s32*)(obj + 0x94) = st;
        if (((s8*)obj)[4] != 2) {
            if (obj[0x8B] == 0) {
                *(s32*)(obj + 0x50) = D_800F4000_ovl08;
            } else {
                *(s32*)(obj + 0x50) = D_800F4004_ovl08;
            }
            ((void (*)())func_800317B8)(obj);
            *(s32*)(obj + 0x50) = D_800F400C_ovl08;
            ((void (*)())func_800317B8)(obj);
        }
        if (obj[0x8B] == 0) {
            *(u8**)(obj + 0x58) = D_80074EE0;
            *(u8**)(obj + 0x54) = D_800F3B80_ovl08;
            *(u8**)(obj + 0x68) = D_800F3B68_ovl08;
        } else {
            *(u8**)(obj + 0x58) = D_80074EE0;
            *(u8**)(obj + 0x54) = D_800F3B84_ovl08;
            *(u8**)(obj + 0x68) = D_800F3B88_ovl08;
        }
        r = func_80031DD0(obj);
        if (r >= 0) {
            q = D_800750C0;
            *(s32*)(obj + 0x54) = D_800F4008_ovl08;
            *(u8**)(obj + 0x58) = q;
            r = func_80031DD0(obj);
        }
        if (r < 0) {
            if (r != -0x38) {
                func_80054440(obj, 0x11);
            }
            goto dead; // !FAKE: goto kept for the matching branch layout
        }
        if (((s8*)obj)[4] != 2) {
            if (is_off_screen(obj, 0x60, 0x60) != 0) {
                silence_sound(2, 0x51);
                obj[4] = 4;
                return;
            }
            func_8002D9EC(obj, 0x40, 0x40);
        }
    }
    if ((obj[0x70] & 0xC) == 0xC || (obj[0x70] & 3) == 3) {
    dead:
        *(s32*)(obj + 0x68) = 0;
        func_8004FD24(obj);
        func_8004D4F4(4, D_800F3D18_ovl08, obj);
        *(s16*)(obj + 0x7C) = 0x20;
        *(s16*)(obj + 0x7E) = 6;
        obj[3] = 0;
        silence_sound(2, 0x51);
        obj[4] = 2;
        return;
    }
    func_8002FB58(obj);
}

extern void silence_sound(s32, s32);

void func_800EFE9C_ovl08(u8* obj) {
    u8 mode;

    if (!(obj[2] & 0x10)) {
        move_object(obj);
    }
    animate_object(obj);
    if (--*(s32*)(obj + 0x8C) == 0) {
        set_animation(obj, 3);
        *(s32*)(obj + 0x20) = 0;
        silence_sound(2, 0x51);
        obj[5] = 5;
        obj[6] = 0;
        return;
    }
    mode = obj[0x90];
    if (mode != 0) {
        if (--obj[0x91] == 0) {
            if (mode == 2) {
                obj[0x91] = 0x30;
                if (--obj[0x92] == 0) {
                    obj[0x92] = mode;
                    set_animation(obj, 3);
                    *(s32*)(obj + 0x20) = 0;
                    silence_sound(2, 0x51);
                    obj[5] = 5;
                    obj[6] = 0;
                    return;
                }
            } else {
                obj[0x91] = 0x60;
            }
            *(s16*)(obj + 0x7C) = 0x14;
            *(s32*)(obj + 0x24) = 0;
            obj[5] = 4;
            obj[6] = 0;
        }
    }
    if (obj[0x15] == 0) {
        if (obj[0x70] & 2) {
            goto tail; // !FAKE: goto kept for the matching branch layout
        }
    } else if (obj[0x70] & 1) {
    tail:
        *(s16*)(obj + 0x7C) = 0x14;
        *(s32*)(obj + 0x24) = 0;
        obj[5] = 4;
        obj[6] = 0;
    }
}
