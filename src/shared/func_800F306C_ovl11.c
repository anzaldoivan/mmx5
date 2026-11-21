#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern u8 D_800F9B84_ovl11[];
extern u8 D_800F9B88_ovl11[];
extern s8 D_800F9B8C_ovl11[][2];

void func_800F306C_ovl11(Obj306C* obj) {
    s32 v;
    s16 a;
    s32 r;
    u8 d;

    obj->unk3 = 1;
    obj->unk4++;
    if ((s8)obj->unk2 & 0x80) {
        obj->unk24 = 0;
        if ((obj->unk2 & 0xF) == 1) {
            v = 0xFFFD0000;
            if (obj->unk15 != 0) {
                v = 0x30000;
            }
            obj->unk20 = v;
        } else {
            v = 0xFFFE8000;
            if (obj->unk15 != 0) {
                v = 0x30000;
            }
            obj->unk20 = v;
        }
        if ((obj->unk2 & 0xF) == 0) {
            obj->unk24 = 0x18000;
        }
        if ((obj->unk2 & 0xF) == 2) {
            obj->unk24 = 0xFFFE8000;
        }
        obj->unk28 = 0;
        obj->unk2C = 0;
        set_animation(obj, 0x10);
        obj->unk60 = 2;
    } else {
        v = 0xFFFD0000;
        if (obj->unk15 != 0) {
            v = 0x30000;
        }
        obj->unk20 = v;
        obj->unk28 = 0;
        obj->unk24 = 0x18000;
        obj->unk2C = 0x4000;
        set_animation(obj, 0x16);
        obj->unk60 = 5;
    }
    a = obj->unkA;
    if (obj->unk15 != 0) {
        r = a + D_800F9B8C_ovl11[obj->unk2 & 0xF][0];
    } else {
        r = a - D_800F9B8C_ovl11[obj->unk2 & 0xF][0];
    }
    obj->unkA = r;
    d = ((Tbl9B8C*)D_800F9B8C_ovl11)->f1[(obj->unk2 & 0xF) * 2];
    obj->unk67 = 0;
    obj->unk16 = 6;
    obj->unk68 = D_800F9B88_ovl11;
    obj->unk54 = D_800F9B84_ovl11;
    obj->unk50 = D_800F9B84_ovl11;
    obj->unkE += (s8)d;
}

extern s32 func_8002E274(u8* a0, u8* a1);
extern s32 func_8004FC64(u8* a0);
extern s32 func_8002D800(u8* a0);

void func_800F3230_ovl11(u8* obj) {
    u8* g = g_Player;

    if (g[0xF7] == 0) {
        animate_object(obj);
        apply_object_motion(obj);
    }
    if (func_800317B8(obj) != 0) {
        goto inc; // !FAKE: goto kept for the matching branch layout
    }
    if (func_8002E274(obj, g) != 0) {
        if (obj[2] & 0x40) {
            ((s32(*)())func_8004FD24)(obj);
        }
        goto inc; // !FAKE: goto kept for the matching branch layout
    }
    if (obj[2] & 0x40) {
        if (obj[0x70] == 0) {
            ((s32(*)())func_8002F8FC)(obj);
            if (obj[0x70] == 0) {
                goto tail; // !FAKE: goto kept for the matching branch layout
            }
        }
        ((s32(*)())func_8004FD24)(obj);
        obj[4]++;
        return;
    }
    if (obj[0x70] == 0) {
        ((s32(*)())func_8002F8FC)(obj);
        if (obj[0x70] == 0) {
            goto tail; // !FAKE: goto kept for the matching branch layout
        }
    }
    func_8004FC64(obj);
    obj[4] = 2;
    return;
tail:
    if (func_8002D800(obj) == 0) {
        func_8002D89C(obj);
        return;
    }
inc:
    obj[4]++;
}
