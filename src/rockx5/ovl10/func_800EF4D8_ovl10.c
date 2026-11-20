#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FB364_ovl10[];
extern u8 D_800FB370_ovl10[];
extern s16 D_800FB378_ovl10[];

void func_800EF4D8_ovl10(u8* obj) {
    s32 side;
    u8* p;
    u8* q;
    s32 lim;

    p = g_Player;
    if (*(s16*)(p + 0xA) < *(s16*)(obj + 0xA)) {
        side = 0;
        obj[0x15] = 0;
    } else {
        side = 1;
        obj[0x15] = 0x40;
    }
    lim = D_800FB378_ovl10[side];
    q = g_Player;
    if ((*(s16*)(q + 0xA) - *(s16*)(obj + 0xA)) >= 0
            ? (*(s16*)(q + 0xA) - *(s16*)(obj + 0xA)) < lim
            : (*(s16*)(obj + 0xA) - *(s16*)(q + 0xA)) < lim) {
        if (*(s8*)(obj + 2) != 0) {
            *(u8**)(obj + 0x68) = D_800FB364_ovl10;
            set_animation(obj, 3);
        } else {
            *(u8**)(obj + 0x68) = D_800FB370_ovl10;
            set_animation(obj, 0);
        }
        obj[6]++;
    }
}
