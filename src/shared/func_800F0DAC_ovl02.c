#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/title.h"

#define g_Player_as_X4_Obj (*(X4_Obj*)&g_Player)

#define SCR D_1F80004C.scr4c
#define SCRB D_1F80004C.bytes

extern void func_800F2B54_ovl02(Obj0DAC*);
extern u8 D_80074EE0[];
extern s32 D_800F46E8_ovl02;
extern s32 D_800F462C_ovl02;
extern s32 D_800F4630_ovl02;
extern u8 D_8009A0B4;
extern s32 D_800F4638_ovl02;
extern s32 D_800F4634_ovl02;
extern Unk800770CC D_800F463C_ovl02;
extern u8 D_80074E40[];

void func_800F0DAC_ovl02(Obj0DAC* e) {
    if (e->unk2 < 0x10) {
        e->unk5C = 0x2D;
        e->unk60 = 5;
        e->unk58 = D_80074EE0;
        e->unk61 = 0;
        e->unk14 = g_Player_as_X4_Obj.bg_offset;
        e->unk67 = 0;
        e->unk68 = 0;
        e->unk30 = &D_800F46E8_ovl02;
        e->unk16 = 6;
        e->unk50 = &D_800F462C_ovl02;
        e->unk18 = e->x.val;
        e->unk1C = e->y.val;
        set_animation(e, 0);
        e->unk70 = 0;
        e->unk68 = &D_800F4630_ovl02;
        if (g_Player_as_X4_Obj.x_pos.val <= e->x.val) {
            e->unk15 = 0;
        } else {
            e->unk15 = 0x40;
        }
        SCRB[0x80] = 1;
        SCRB[0x81] = 8;
        SCRB[0x82] = 0;
        e->unk67 = 1;
        e->f20 = 0;
        e->f24 = 0;
        e->f28 = 0;
        e->f2C = 0x4200;
        e->unk5 = 5;
        e->unk4 = 1;
        e->unk6 = 0;
    } else {
        e->unk3 = 1;
        e->unk5C = 1;
        e->unk60 = 4;
        e->unk14 = D_8009A0B4;
        set_animation(e, 5);
        e->unk50 = &D_800F4638_ovl02;
        e->unk54 = &D_800F4634_ovl02;
        e->unk68 = &SCR->box;
        SCR->box = D_800F463C_ovl02;
        SCR->flags83 = 0;
        SCR->cnt88 = 3;
        e->unk58 = D_80074E40;
        e->unk4 = 5;
        e->unk5 = 2;
        e->unk70 = 0;
        e->unk16 = 4;
        e->f20 = 0;
        e->f28 = 0;
        e->f24 = 0;
        e->f2C = 0;
        if (e->unk2 == 0x10) {
            if (e->unk15 == 0) {
                e->x.u.hi -= 12;
            } else {
                e->x.u.hi += 8;
            }
            e->unk5 = 11;
            e->f24 = 0x20000;
            e->y.u.hi -= 16;
        } else {
            if (e->unk15 == 0) {
                e->x.u.hi -= 8;
            } else {
                e->x.u.hi += 8;
            }
            e->unk5 = 2;
            e->f24 = 0xFFFE0000;
            e->y.u.hi += 16;
        }
        func_800F2B54_ovl02(e);
        e->unk4 = 5;
        e->unk6 = 0;
    }
}

extern void (*D_800F4738_ovl02[])(u8*);
extern u8 D_800F4624_ovl02[];
extern u8 D_800F4628_ovl02[];
extern u8 D_800F4620_ovl02[];
extern u8 D_800F4714_ovl02[];
extern u8 D_800753E0[];
extern u8 D_80074EE0[];
extern void func_80054440(u8* a0, s32 a1);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);

void func_800F104C_ovl02(u8* obj) {
    u8* p = g_Player;
    s32 mode;
    s32 r;

    if (p[0xF7] == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        animate_object(obj);
        D_800F4738_ovl02[*(signed char*)(obj + 5)](obj);
        if (--D_1F80004C.bytes[0x81] == 0xFF) {
            D_1F80004C.bytes[0x81] = 8;
            if (*(s16*)(p + 0xA) < *(s16*)(obj + 0xA)) {
                obj[0x15] = 0;
            } else {
                obj[0x15] = 0x40;
            }
        }
    }
    ((void (*)())func_800317B8)(obj);
    mode = D_1F80004C.bytes[0x82];
    if (mode != 0) {
        if (mode == 1) {
            *(u8**)(obj + 0x54) = D_800F4624_ovl02;
        } else if (mode == 2) {
            *(u8**)(obj + 0x54) = D_800F4628_ovl02;
        }
        *(u8**)(obj + 0x58) = D_800753E0;
        r = func_80031DD0(obj);
        if (r < 0) {
            func_80054440(obj, 0x12);
            goto die; // !FAKE: nested branch joins the shared die block as the target does; untested without
        }
        if (r == 0) {
            *(u8**)(obj + 0x54) = D_800F4620_ovl02;
            *(u8**)(obj + 0x58) = D_80074EE0;
            func_80031DD0(obj);
        }
    } else {
        *(u8**)(obj + 0x54) = D_800F4620_ovl02;
        *(u8**)(obj + 0x58) = D_80074EE0;
        func_80031DD0(obj);
    }
    if (is_off_screen(obj, 0x40, 0x40) != 0) {
        obj[4] = 3;
        return;
    }
    func_8002D9EC(obj, 0x20, 0x20);
    if ((obj[0x70] & 0xC) == 0xC || (obj[0x70] & 3) == 3) {
    die:
        func_8004D4F4(5, D_800F4714_ovl02, obj);
        obj[3] = 0;
        *(s16*)(obj + 0x7C) = 0x14;
        *(s16*)(obj + 0x7E) = 5;
        obj[4] = 4;
        return;
    }
    func_8002FB58(obj);
}
