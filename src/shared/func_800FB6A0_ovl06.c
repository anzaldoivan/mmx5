#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"

void func_800FB6A0_ovl06(Obj800FB6A0* o) {
    s32 d;
    s32 sq;

    if (o->x15 != 0) {
        o->x20 = 0x40000;
    } else {
        o->x20 = -0x40000;
    }
    d = D_8009A0AA - o->xA;
    if (d < 0) {
        d = o->xA - D_8009A0AA;
    }
    if (d < 5) {
        d = 1;
    } else {
        d = d / 4;
    }
    sq = d * d;
    o->x28 = 0;
    o->x24 = 0;
    o->x2C = 0x500000 / sq;
    o->x6++;
}

extern void func_800FBD10_ovl06(u8* obj, s32 x, s32 y, s32 n);
extern u8 D_800FF684_ovl06[];
extern u8 D_800FF688_ovl06[];

void func_800FB740_ovl06(u8* obj) {
    if (obj[0x47] == 11) {
        *(u8**)(obj + 0x50) = D_800FF684_ovl06;
        *(u8**)(obj + 0x54) = D_800FF688_ovl06;
    }
    ((s32(*)())apply_object_motion)(obj);
    if (obj[0x70] == 0) {
        ((s32(*)())func_8002F8FC)(obj);
        if (obj[0x70] == 0) {
            return;
        }
    }
    func_800FBD10_ovl06(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 2);
    func_800FBD10_ovl06(obj, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE), 3);
    *(s16*)(obj + 0x88) = 60;
    obj[6]++;
}

extern u8 D_800FF684_ovl06[];
extern u8 D_800FF688_ovl06[];

void func_800FB7EC_ovl06(u8* obj) {
    if (obj[0x47] == 11) {
        *(u8**)(obj + 0x50) = D_800FF684_ovl06;
        *(u8**)(obj + 0x54) = D_800FF688_ovl06;
    }
    if (--*(s16*)(obj + 0x88) == 0) {
        *(s32*)(obj + 0x50) = 0;
        obj[4] = 3;
        obj[7] = 0;
    }
}
