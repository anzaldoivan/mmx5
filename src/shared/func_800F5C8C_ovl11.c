#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#define g_Player_as_Scr5C8C (*(Scr5C8C*)&g_Player)

extern s16 D_800FA05A_ovl11;
extern Row5C8C D_8009A1F8[];

s32 func_800F5C8C_ovl11(Obj5C8C* obj) {
    s32 ret;

    obj->unk60 = 8;
    if (g_Player_as_Scr5C8C.unk2 == 0 && g_Player_as_Scr5C8C.unkFA == 0) {
        obj->unk62 = 8;
    } else {
        obj->unk62 = 6;
    }
    set_animation(obj, 7);
    if (obj->unkA > D_800FA05A_ovl11) {
        obj->unk15 = 0;
        obj->unk20 = 0xFFFA0000;
        obj->unkA = (obj->unk14 + D_8009A1F8)->unkA + 0x180;
        obj->unkE =
            g_Player_as_Scr5C8C.unkE - (obj->unkA - g_Player_as_Scr5C8C.unkA);
    } else {
        obj->unk15 = 0x40;
        obj->unk20 = 0x60000;
        obj->unkA = (obj->unk14 + D_8009A1F8)->unkA - 0x40;
        obj->unkE =
            g_Player_as_Scr5C8C.unkE - (g_Player_as_Scr5C8C.unkA - obj->unkA);
    }
    obj->unk24 = 0xFFFA0000;
    animate_object(obj);
    ret = play_sound(2, 0x32, obj);
    obj->unk6++;
    return ret;
}
