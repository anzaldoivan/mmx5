#include "types.h"
#include "mmx5/title.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);

void func_800FB87C_ovl06(Obj3700* obj) {
    Obj3700* plr = (Obj3700*)g_Player;
    s32 px;
    s32 py;
    s32 angle;
    s32 c;
    s32 s;
    s32 t;
    s32 u;

    px = plr->unkA;
    py = plr->unkE;
    angle = ratan2(obj->unkE - py, px - obj->unkA);
    obj->unk28 = 0;
    obj->unk2C = 0;
    c = rcos(angle);
    t = c << 4;
    obj->unk20 = (c << 6) + t;
    s = rsin(angle);
    u = s << 4;
    s <<= 6;
    s += u;
    s += s >> 1;
    obj->unk24 = s;
    obj->unk20 += obj->unk20 / 2;
    obj->unk6++;
}
