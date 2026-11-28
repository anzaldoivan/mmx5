#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

#define func_800F3E90_ovl26 func_800F518C_ovl28
#include "shared/func_800F3E90_ovl26.c"
#undef func_800F3E90_ovl26

extern s8 D_800D1C0F;
extern s8 D_8009A0A5;
extern u8 D_800FEA5C_ovl28;
extern u8* alloc_class3_slot(void);

void func_800F51C4_ovl28(u8* a0) {
    u8* b;
    u8* p;

    if (D_800D1C0F == 0 && D_8009A0A5 == 20) {
        b = D_8009A1F8.u;
        D_800FEA5C_ovl28 = b[0x48];
        b[0x48] = 1;
        b[0x47] = 2;
        func_8003D29C(0x1D, 0x40);
        p = alloc_class3_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0x18;
            *(u16*)(p + 0xA) = *(u16*)(a0 + 0xA);
            *(u16*)(p + 0xE) = *(u16*)(a0 + 0xE);
            *(u8**)(D_1F80004C.bytes + 0x80) = p;
        }
        *(u16*)(a0 + 0x7C) = 0x40;
        a0[6]++;
    }
}

extern void func_80024548(s32);

void func_800F5290_ovl28(u8* arg0) {
    s32 v;
    s16 t;

    v = *(u16*)(arg0 + 0x7C) - 1;
    *(u16*)(arg0 + 0x7C) = v;
    t = v;
    if (t == 0) {
        func_8003D29C(0x14, 0x40);
    } else if (t == 0x30) {
        u8* b = D_8009A1F8.u;
        *(s16*)(b + 0x26) = 0x1910;
        *(s16*)(b + 0x24) = 0x1910;
    }
    if (**(s8**)(D_1F80004C.bytes + 0x80) == 0) {
        u8* o = g_playthrough_state.u;
        o[0x24] = 1;
        o[0x25] = 0;
        *(u8**)(o + 0x20) = arg0;
        o[0xA2] = 0x30;
        func_80024548(1);
        arg0[3] = 1;
        play_sound(1, 0xD, arg0);
        arg0[6]++;
    }
}

extern u8 D_800FDC0C_ovl28[];
extern s8 D_800D1C2E;
extern void func_80044DD0(s32 a0);

void func_800F5370_ovl28(u8* obj) {
    move_object(obj);
    if (*(s16*)(obj + 0xE) >= 0x300) {
        *(u8**)(obj + 0x68) = D_800FDC0C_ovl28;
    }
    if (obj[0x70] & 8) {
        play_sound(2, 0x6E, obj);
        obj[0x67] = 0;
        if (D_800D1C2E != 0) {
            func_80044DD0(0);
            *(s16*)(obj + 0x7E) = 1;
            obj[6] = 8;
        } else {
            obj[6]++;
        }
    }
}

extern u8* find_free_visual_obj(void);

void func_800F5414_ovl28(u8* obj) {
    s32 i;
    u8* p;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 0);
        obj[7] = 0;
        obj[6]++;
        for (i = 0; i < 2; i++) {
            p = find_free_visual_obj();
            if (p != 0) {
                p[0] = 0x61;
                p[1] = 0xB;
                p[2] = i;
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) + (i + 1) * 0x30 - 8;
                *(s16*)(p + 0xE) = 0x240;
                *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
                *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
                *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
                load_palette(0x140, D_1F800030 + 0x320, 1);
                *(s16*)(p + 0x42) = 0x7CCD;
                p[0x15] = obj[0x15];
                *(u8**)(p + 0x50) = obj;
            }
        }
    }
}

void func_800F5520_ovl28(u8* obj) {
    s8 state;
    u8* d;

    animate_object(obj);
    state = ((s8*)obj)[7];
    if (state == 1) {
        d = g_playthrough_state.u;
        func_8002385C(0x42, 0xFF, d[0x2E]);
        d[0x2E] = state;
        obj[6]++;
    }
}

extern u8 D_80091C44;
extern void func_80044DD0(s32 a0);

void func_800F558C_ovl28(u8* obj) {
    animate_object(obj);
    if (D_80091C44 == 0) {
        func_80044DD0(0);
        *(s16*)(obj + 0x7E) = 10;
        obj[6]++;
    }
}

extern s32 func_80044DE0();

void func_800F55E0_ovl28(u8* obj) {
    animate_object(obj);
    if (func_80044DE0() == 0) {
        obj[7] = 2;
        if (*(s16*)(obj + 0x7E) != 0) {
            *(s16*)(obj + 0x7E) -= 1;
        } else {
            set_animation(obj, 0xC);
            obj[6]++;
        }
    }
}

s32 func_80044DE0();

void func_800F564C_ovl28(u8* self) {
    animate_object(self);
    if (*(s16*)(self + 0x7E) != 0) {
        if (func_80044DE0() != 0) {
            return;
        }
        *(s16*)(self + 0x7E) = 0;
    }
    load_palette(0x13C, D_1F800030 + 0x60, 1);
    load_palette(0x13D, D_1F800030 + 0x80, 1);
    *(s16*)(self + 0x42) = 0x7CCC;
    if (*(s8*)(self + 0x45) == 1) {
        set_animation(self, 1);
        *(s16*)(self + 0x7C) = 2;
        self[6]++;
    }
}

extern u8 D_800FEA5C_ovl28;

void func_800F56FC_ovl28(Ent8EF0* obj) {
    animate_object(obj);
    if (--obj->unk7C == 0) {
        play_sound(0, 0xE, 0);
        obj->unk7C = 2;
    }
    D_8009A1F8.t.unk26 = 0x18F0;
    *(u16*)((u8*)&D_8009A1F8.t + 0x24) = 0x1920;
    if (++obj->unk5C == D_800D1CA2) {
        D_8009A1F8.t.unk48 = D_800FEA5C_ovl28;
        D_1F80004C.scr1090->unk87 = 1;
        ((s32(*)())func_8003D2C4)();
        obj->unk5 = 7;
        obj->unk6 = 0;
        ((u8*)obj)[7] = 0;
    }
}
