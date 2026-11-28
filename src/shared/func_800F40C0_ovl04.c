#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern s32 func_80044DE0();
#define D_800D1C00_as_Glb800F3EA0 (*(Glb800F3EA0*)&g_playthrough_state)

void func_800F40C0_ovl04(u8* obj) {
    animate_object(obj);
    if (func_80044DE0() == 0 && *(s8*)(obj + 0x45) == 1) {
        if (D_800D1C00_as_Glb800F3EA0.unkC != 0xC) {
            D_8009A1F8.bg3EA0.unk26 = 0x1550;
            D_8009A1F8.bg3EA0.unk24 = 0x1590;
        } else {
            D_8009A1F8.bg3EA0.unk26 = 0x440;
            D_8009A1F8.bg3EA0.unk24 = 0x480;
        }
        if (*(s8*)(obj + 0x5C) < D_800D1C00_as_Glb800F3EA0.unkA2) {
            if (--*(s16*)(obj + 0x7C) == 0) {
                play_sound(0, 0xE, 0);
                *(s16*)(obj + 0x7C) = 3;
            }
            obj[0x5C]++;
        } else {
            *(s16*)(obj + 0x7C) = 0x3C;
            obj[5]++;
        }
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
    }
}
