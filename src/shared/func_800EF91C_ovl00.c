#include "types.h"
#include "mmx5/system.h"

extern Obj80050880* find_free_visual_obj(void);
extern s32 D_800FA948_ovl00[];
extern s32 D_800FA928_ovl00[];

void func_800EF91C_ovl00(u8 flags, s16 x0, s16 y0, s16 x1, s16 y1, s16 count) {
    Obj80050880* obj;
    u16 rx;
    u16 ry;
    s16 d;
    s16 i;

    for (i = 0; i < count; i++) {
        obj = find_free_visual_obj();
        if (obj == 0) {
            continue;
        }
        obj->unk0 = 0x21;
        obj->unk1 = 9;
        obj->unk2 = 0;
        rx = (random_byte() << 8) + random_byte() + 1;
        ry = (random_byte() << 8) + random_byte() + 1;
        d = x1 - x0;
        if (d == 0) {
            obj->unkA = x0;
        } else {
            obj->unkA = x0 + rx % d;
        }
        d = y1 - y0;
        if (d == 0) {
            obj->unkE = y0;
        } else {
            obj->unkE = y0 + ry % d;
        }
        obj->unk8 = 0;
        obj->unkC = 0;
        switch (flags & 0xF) {
        case 1:
            obj->unk20 = D_800FA948_ovl00[random_byte() & 7] << 1;
            obj->unk24 = D_800FA928_ovl00[random_byte() & 3] << 1;
            break;
        case 2:
            obj->unk20 = -(D_800FA948_ovl00[random_byte() & 7] << 1);
            obj->unk24 = D_800FA928_ovl00[random_byte() & 3] << 1;
            break;
        case 4:
            obj->unk20 = -(D_800FA948_ovl00[random_byte() & 7] << 1);
            obj->unk24 = -(D_800FA928_ovl00[random_byte() & 3] << 1);
            break;
        case 8:
            obj->unk20 = D_800FA948_ovl00[random_byte() & 7] << 1;
            obj->unk24 = -(D_800FA928_ovl00[random_byte() & 3] << 1);
            break;
        default:
            obj->unk20 = 0;
            obj->unk24 = 0;
            break;
        }
        obj->unk15 = 0;
        obj->unk5C = flags >> 4;
        obj->unk4 = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
    }
}
