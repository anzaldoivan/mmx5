#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

extern u8 D_80074DA0[];
extern u8 D_800FBF30_ovl10[];
extern u8 D_800FBF38_ovl10[];

void func_800F7120_ovl10(u8* obj) {
    obj[4] = 8;
    obj[3] = 1;
    obj[0x16] = 6;
    *(u8**)(obj + 0x58) = D_80074DA0;
    *(u8**)(obj + 0x68) = D_800FBF30_ovl10;
    *(u8**)(obj + 0x54) = D_800FBF38_ovl10;
    *(u8**)(obj + 0x50) = D_800FBF38_ovl10;
    obj[0x5C] = 4;
    obj[0x60] = 4;
    *(s16*)(obj + 0x88) = 0x15E;
    if (D_800D1C0C.s != 12) {
        if (*(s16*)(obj + 0xA) < 0x1F61) {
            *(s16*)(obj + 0xA) = 0x1F70;
        } else if (*(s16*)(obj + 0xA) >= 0x20A0) {
            *(s16*)(obj + 0xA) = 0x2090;
        }
    } else {
        if (*(s16*)(obj + 0xA) < 0xA61) {
            *(s16*)(obj + 0xA) = 0xA70;
        } else if (*(s16*)(obj + 0xA) >= 0xBA0) {
            *(s16*)(obj + 0xA) = 0xB90;
        }
    }
    play_sound(2, 0x2E, obj);
    set_animation(obj, 0x21);
}
