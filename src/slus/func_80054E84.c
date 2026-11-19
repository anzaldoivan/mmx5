#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"

extern s16 D_8009A220[];
extern s8 D_800D1C1C;
extern s8 D_800D1C1D;
extern s8 D_800D1C27;
extern s32 D_800E92F8;

void func_80054E84(u8* obj) {
    s8 kind;
    u8* p;

    if (((s8*)obj)[0x45] < 2) {
        animate_object(obj);
        if (((s8*)obj)[0x45] == 1) {
            play_sound(0, 0x10, obj);
            obj[0x45] = 0;
        }
    } else {
        kind = ((s8*)obj)[2];
        obj[4] = 2;
        obj[5] = 0;
        if (kind == 1) {
            D_800D1C1D = 3;
        } else if (kind == 3) {
            D_800E92F8 = 1;
            D_8009A220[0] = 0;
        } else if (kind == 8) {
            D_800D1C27 = 1;
        }
        p = g_Player;
        if (((s8*)p)[0xD0] == 0 && ((s8*)p)[0xD4] == 0) {
            D_800D1C1C = 0;
        }
    }
}
