/* Shared body (DK-5), from the banked draft of func_800F5F70_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#define g_Player_as_Scr5F70 (*(Scr5F70*)&g_Player)

extern s16 D_800FA05A_ovl11;
extern Row5C8C D_8009A1F8[];

void DEDUP_NAME(Obj5C8C* obj) {
    s32 r;
    Scr5F70* s;

    obj->unk60 = 8;
    if (g_Player_as_Scr5F70.unk2 == 0 && g_Player_as_Scr5F70.unkFA == 0) {
        obj->unk62 = 8;
    } else {
        obj->unk62 = 6;
    }
    set_animation(obj, 3);
    if (obj->unkA > D_800FA05A_ovl11) {
        obj->unk15 = 0;
        obj->unk20 = 0xFFFA0000;
        obj->unkA = (obj->unk14 + D_8009A1F8)->unkA + 0x180;
    } else {
        obj->unk15 = 0x40;
        obj->unk20 = 0x60000;
        obj->unkA = (obj->unk14 + D_8009A1F8)->unkA - 0x40;
    }
    obj->unk24 = 0;
    r = random_byte();
    s = &g_Player_as_Scr5F70;
    r = (r & 0x3F) - 0x20;
    obj->unkE = s->unkE + r;
    animate_object(obj);
    play_sound(2, 0x32, obj);
    obj->unk6++;
}
