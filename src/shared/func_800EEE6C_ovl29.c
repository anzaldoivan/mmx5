#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_8009A197;
extern void (*D_800F9150_ovl29[])(u8*);
extern u8 D_800F9138_ovl29[];
extern void func_800EFC68_ovl29(u8* a0);
extern void func_800EFCEC_ovl29(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_80054440(u8* a0, s32 a1);

void func_800EEE6C_ovl29(u8* obj) {
    u8 state;

    if (D_8009A197 == 0) {
        if (*(signed char*)(obj + 5) != 8) {
            func_800EEF84_ovl29();
            func_800EFC68_ovl29(obj);
            func_800EF2B8_ovl29(obj);
            func_800EF190_ovl29(obj);
            func_800EFCEC_ovl29(obj);
        }
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        D_800F9150_ovl29[*(signed char*)(obj + 5)](obj);
    }
    ((void (*)())func_800317B8)(obj);
    *(s32*)(obj + 0x90) = (s32) * (signed char*)(obj + 5);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_8004D4F4(7, D_800F9138_ovl29, obj);
        func_80054440(obj, 0x11);
        state = 2;
    } else {
        if (is_off_screen(obj, 0x40, 0x40) == 0) {
            func_8002D9EC(obj, 0x20, 0x20);
            return;
        }
        state = 3;
    }
    obj[4] = state;
}

extern u8 func_80030AE4(ObjEECF8*, s16, s16);
extern s32 D_8009A0A8;

void func_800EEF84_ovl29(ObjEECF8* e) {
    s16 x;
    s32 dx;

    if (e->unk5 != 2) {
        return;
    }
    if (e->unk7C != 0) {
        e->unk7C--;
        return;
    }
    if (e->unk15) {
        x = e->x.i.hi + e->unk68->a + 0x10;
    } else {
        x = e->x.i.hi - e->unk68->a - 0x10;
    }
    if (!func_80030AE4(e, x, e->unk68->d + (e->y.i.hi + e->unk68->b))) {
        e->unk8C = 0x78;
        e->unk5 = 3;
        e->unk6 = 0;
        set_animation(e, 2);
    }
    if (e->unk88 == 0) {
        if (e->unk15) {
            if (e->unk70 & 1) {
                e->unk5 = 3;
                e->unk6 = 0;
                e->unk8C = 0x78;
                set_animation(e, 2);
            }
        } else {
            if (e->unk70 & 2) {
                e->unk5 = 3;
                e->unk6 = 0;
                e->unk8C = 0x78;
                set_animation(e, 2);
            }
        }
    } else {
        dx = e->x.val - D_8009A0A8;
        if (e->unk15) {
            if (dx > 0 || (e->unk70 & 1)) {
                e->unk5 = 3;
                e->unk6 = 0;
                e->unk88 = 0;
                e->unk8C = 0x3C;
                set_animation(e, 2);
            }
        } else {
            if (dx < 0 || (e->unk70 & 2)) {
                e->unk5 = 3;
                e->unk6 = 0;
                e->unk88 = 0;
                e->unk8C = 0x3C;
                set_animation(e, 2);
            }
        }
    }
}
