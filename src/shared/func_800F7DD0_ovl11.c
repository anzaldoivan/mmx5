#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/system.h"
#include "mmx5/object.h"
#include "addr.h"
extern s16 D_800FA05A_ovl11;

void func_800F7DD0_ovl11(u8* obj) {
    u8* p;
    u8* q;
    u8* r;
    u16 x;

    set_animation(obj, 8);
    p = g_Player;
    obj[0x60] = 8;
    if (((s8*)p)[2] == 0 && p[0xFA] == 0) {
        obj[0x62] = 9;
    } else {
        obj[0x62] = 7;
    }
    r = g_Player;
    x = *(u16*)(r + 0xA);
    *(u16*)(obj + 0xA) = x;
    q = D_8009A1F8.u;
    ((Obj5C8C*)obj)->unkE = *(s16*)(q + ((s8*)obj)[0x14] * 0x54 + 0xE) + 0x170;
    *(s32*)(obj + 0x24) = 0x50000;
    if (D_800FA05A_ovl11 < (s16)x) {
        obj[0x15] = 0x40;
    } else {
        obj[0x15] = 0;
    }
    animate_object(obj);
    play_sound(2, 0x32, obj);
    obj[6]++;
}
