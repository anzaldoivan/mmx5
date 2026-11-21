#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FF470_ovl06[];

void func_800FAF38_ovl06(Obj1334* parent, s16 x, s16 y, u8 kind) {
    Obj1334* child;

    child = func_8002D1A4();
    if (child != 0) {
        child->unk0 = 0x41;
        child->unk1 = 0x11;
        child->unk7C = parent;
        child->unk2 = kind;
        child->unk15 = parent->unk15;
        child->unkA = x;
        child->unk8 = 0;
        child->unkE = y;
        child->unkC = 0;
        child->unk42 = parent->unk42 & 0x7FFF;
        child->unk30 = D_800FF470_ovl06;
        child->unk3C = parent->unk3C;
        child->unk40 = parent->unk40;
        child->unk14 = parent->unk14;
    }
}

extern ObjFAFFC* find_free_visual_obj(void);

void func_800FAFFC_ovl06(ObjFAFFC* arg0, s16 arg1, s16 arg2, u8 arg3) {
    ObjFAFFC* obj = find_free_visual_obj();

    if (obj != 0) {
        obj->unk0 = 0x41;
        obj->unk1 = 6;
        obj->unk2 = arg3;
        obj->unk15 = arg0->unk15;
        obj->unk40 = arg0->unk40;
        obj->unk42 = arg0->unk42 & 0x7FFF;
        obj->unk30 = arg0->unk30;
        obj->unk3C = arg0->unk3C;
        obj->unk14 = arg0->unk14;
        obj->unkA = arg1;
        obj->unk8 = 0;
        obj->unkE = arg2;
        obj->unkC = 0;
        obj->unk50 = arg0;
    }
}

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_80074E40[];
extern u8 D_800FF68C_ovl06[];
extern u8 D_800FF67C_ovl06[];
extern u8 D_800FF680_ovl06[];
extern u8 D_800FF698_ovl06[];
extern u8 D_800FF690_ovl06[];
extern u8 D_800FF694_ovl06[];
extern u8 D_800FF6A8_ovl06[];

void func_800FB0C4_ovl06(u8* obj) {
    s32 a;
    s32 v;
    s32 t;
    u8 pad[8]; // !FAKE: keeps the 0x28 frame

    obj[0x16] = 4;
    obj[0x67] = 1;
    obj[0x5C] = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x54) = 0;
    switch (((s8*)obj)[2] & 0xF0) {
    case 0x00:
        switch (obj[2] & 0xF) {
        case 0:
            if (obj[0x15] == 0) {
                *(s16*)(obj + 0xA) -= 0x20;
            } else {
                *(s16*)(obj + 0xA) += 0x20;
            }
            obj[0x60] = 4;
            *(u8**)(obj + 0x58) = D_80074E40;
            *(u8**)(obj + 0x68) = D_800FF68C_ovl06;
            *(u8**)(obj + 0x50) = D_800FF67C_ovl06;
            *(u8**)(obj + 0x54) = D_800FF680_ovl06;
            *(s16*)(obj + 0xE) -= 0x18;
            set_animation(obj, 0);
            obj[5] = 0;
            break;
        case 1:
            if (obj[0x15] == 0) {
                *(s16*)(obj + 0xA) -= 0x1E;
            } else {
                *(s16*)(obj + 0xA) += 0x1E;
            }
            obj[0x60] = 4;
            *(u8**)(obj + 0x68) = 0;
            *(u8**)(obj + 0x58) = D_80074E40;
            *(u8**)(obj + 0x50) = D_800FF67C_ovl06;
            *(u8**)(obj + 0x54) = D_800FF680_ovl06;
            *(s16*)(obj + 0xE) -= 0x10;
            set_animation(obj, 0);
            obj[5] = 1;
            break;
        case 2:
            obj[0x60] = 3;
            *(u8**)(obj + 0x58) = D_80074E40;
            *(u8**)(obj + 0x68) = D_800FF698_ovl06;
            obj[0x15] = 0;
            *(u8**)(obj + 0x50) = D_800FF690_ovl06;
            *(u8**)(obj + 0x54) = D_800FF694_ovl06;
            set_animation(obj, 0x1F);
            obj[5] = 3;
            break;
        case 3:
            obj[0x15] = 0x40;
            *(u8**)(obj + 0x58) = D_80074E40;
            *(u8**)(obj + 0x68) = D_800FF698_ovl06;
            obj[0x60] = 3;
            *(u8**)(obj + 0x50) = D_800FF690_ovl06;
            *(u8**)(obj + 0x54) = D_800FF694_ovl06;
            set_animation(obj, 0x1F);
            obj[5] = 3;
            break;
        }
        break;
    case 0x10:
        obj[0x60] = 3;
        *(u8**)(obj + 0x68) = 0;
        *(u8**)(obj + 0x50) = D_800FF6A8_ovl06;
        set_animation(obj, 0x11);
        obj[5] = 2;
        *(s16*)(obj + 0x88) = (obj[2] & 0xF) * 10;
        break;
    case 0x20:
    case 0x30:
    case 0x40:
        if (obj[0x15] == 0) {
            *(s16*)(obj + 0xA) -= 0x20;
        } else {
            *(s16*)(obj + 0xA) += 0x20;
        }
        obj[0x60] = 4;
        *(u8**)(obj + 0x68) = D_800FF68C_ovl06;
        *(u8**)(obj + 0x50) = D_800FF67C_ovl06;
        *(s16*)(obj + 0xE) -= 0x18;
        *(s16*)(obj + 0x8C) = *(s16*)(obj + 0xE);
        set_animation(obj, 0);
        obj[2] -= 0x20;
        if (obj[0x15] == 0) {
            t = *(s16*)(obj + 0xA) + 0x20;
            v = t - ((s8)obj[2] << 5);
        } else {
            t = *(s16*)(obj + 0xA) - 0x20;
            v = t + ((s8)obj[2] << 5);
        }
        a = ratan2(-0x30, v - *(s16*)(obj + 0xA));
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s32*)(obj + 0x20) = rcos(a) << 7;
        *(s32*)(obj + 0x24) = rsin(a) << 7;
        obj[5] = 4;
        break;
    }
    obj[4] = 1;
    obj[6] = 0;
    obj[7] = 0;
    obj[3] = 0;
}
