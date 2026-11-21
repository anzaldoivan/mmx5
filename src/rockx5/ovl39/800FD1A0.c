#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

void func_800FD1A0_ovl39(u8* obj) {
    set_animation(obj, 6);
    obj[6]++;
}

extern u8* find_free_visual_obj(void);
extern u8 D_800FEC1C_ovl39[];
extern u8 D_800FEC20_ovl39[];

void func_800FD1D4_ovl39(u8* obj) {
    s8 state;
    u8* child;

    animate_object(obj);
    state = *(s8*)(obj + 0x45);
    if (state == 1) {
        *(u8**)(obj + 0x54) = D_800FEC20_ovl39;
        *(s32*)(obj + 0x50) = 0;
        *(u8**)(obj + 0x68) = D_800FEC1C_ovl39;
        *(s8*)(obj + 0x8A) = state;
        child = find_free_visual_obj();
        if (child != 0) {
            child[0] = 0x61;
            child[1] = 0x15;
            child[2] = 2;
            *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            child[0x15] = obj[0x15];
            *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
            *(u16*)(child + 0xE) = *(u16*)(obj + 0xE) - 0x28;
            *(u8**)(child + 0x50) = obj;
        }
        obj[6]++;
    }
}

void func_800FD2B4_ovl39(u8* obj) {
    u8* p;
    u8 f;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x61;
            p[1] = 0x28;
            p[2] = 0;
            *(s16*)(p + 0x40) = *(s16*)(obj + 0x40);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(s16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            f = obj[0x15];
            p[0x15] = f;
            if (f == 0) {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) - 0x10;
            } else {
                *(s16*)(p + 0xA) = *(s16*)(obj + 0xA) + 0x10;
            }
            *(s16*)(p + 0xE) = *(s16*)(obj + 0xE) - 0x28;
            *(u8**)(p + 0x7C) = obj;
        }
        set_animation(obj, 8);
        obj[6]++;
    }
}

extern u8 D_800FEC18_ovl39[];
extern u8 D_800FEC14_ovl39[];

void func_800FD398_ovl39(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        *(u8**)(obj + 0x54) = D_800FEC18_ovl39;
        *(s32*)(obj + 0x50) = 0;
        *(u8**)(obj + 0x68) = D_800FEC14_ovl39;
        obj[0x8A] = 0;
        set_animation(obj, 3);
        obj[6]++;
    }
}

extern u8 D_800FEB3C_ovl39[][4];

void func_800FD404_ovl39(EntFD404* e) {
    animate_object(e);
    if (e->unk45 == 1) {
        u8 t = e->unk7C->unk89;
        if (t == e->unk45) {
            e->unk87 = 6;
            e->unk88 = t;
        }
        if (e->unk7C->unk7 != 0x11) {
            e->unk5 = 7;
        } else {
            e->unk88++;
            e->unk5 = D_800FEB3C_ovl39[e->unk87][e->unk88];
        }
        if (e->unk5 == 2) {
            e->unk82 = 180;
        }
        e->unk6 = 0;
    }
}
