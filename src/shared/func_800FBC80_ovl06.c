#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "mmx5/graphics.h"

extern u8 D_800FF684_ovl06[];
extern u8 D_800FF688_ovl06[];

void func_800FBC80_ovl06(ObjBB70* obj) {
    move_object(obj);
    if (obj->unk47 == 0xB) {
        obj->unk50 = D_800FF684_ovl06;
        obj->unk54 = D_800FF688_ovl06;
    }
    if (obj->unk70 == 0) {
        ((s32(*)())func_8002F8FC)(obj);
        if (obj->unk70 == 0) {
            return;
        }
    }
    obj->unk50 = D_800FF684_ovl06;
    obj->unk54 = D_800FF688_ovl06;
    obj->unk4 = 3;
    obj->unk7 = 0;
}

void func_800FBD10_ovl06(u8* self, s16 x, s16 y, u8 sub) {
    u8* p;

    p = func_8002D1A4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x11;
        *(u8**)(p + 0x7C) = self;
        p[2] = sub;
        *(s16*)(p + 0xA) = x;
        *(s16*)(p + 0xE) = y;
        *(u16*)(p + 0x42) = *(u16*)(self + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)(self + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(self + 0x3C);
        *(u16*)(p + 0x40) = *(u16*)(self + 0x40);
        p[0x14] = self[0x14];
    }
}

extern u8 D_800FF724_ovl06[];

void func_800FBDC8_ovl06(u8* obj) {
    u8 sub;
    s32 kind;

    sub = obj[2];
    kind = ((s8*)obj)[2] & 0xF0;
    if (kind == 0) {
        obj[0x16] = D_800FF724_ovl06[sub & 0xF];
        set_animation(obj, 0x12);
        obj[4] = 1;
        obj[3] = 0;
        obj[5] = 0;
        obj[6] = 0;
        *(u16*)(obj + 0x42) &= 0x7FFF;
        *(s16*)(obj + 0x54) = (obj[2] & 0xF) * 7;
    } else if (kind == 0x10) {
        obj[0x16] = 6;
        obj[0x47] = 0;
        obj[3] = 0;
        obj[4] = 1;
        obj[5] = 1;
        obj[6] = 0;
        *(u16*)(obj + 0x1A) = *(u16*)(obj + 0xA);
        *(u16*)(obj + 0x1E) = *(u16*)(obj + 0xE);
        *(u16*)(obj + 0x42) &= 0x7FFF;
    } else if (kind == 0x20) {
        obj[2] = sub & 0xF;
        obj[4] = 3;
        obj[5] = 0;
        obj[6] = 0;
    }
}
