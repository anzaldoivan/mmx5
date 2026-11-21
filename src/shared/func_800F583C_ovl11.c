#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_80050650(s32, s16, s16, s16, s16, s32);
extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;

void func_800F583C_ovl11(u8* obj) {
    u16 x;
    s16 y;

    animate_object(obj);
    move_object(obj);
    if (!(D_8009A420_as_s32 & 1)) {
        x = *(u16*)(obj + 0xA);
        y = *(u16*)(obj + 0xE) + 0x28;
        func_80050650(0x11, x - 0x10, y, x + 0x10, y, 1);
    }
    if (*(s16*)(obj + 0x7C) != 0) {
        (*(s16*)(obj + 0x7C))--;
        return;
    }
    if (*(s32*)(obj + 0x20) < 0) {
        if (*(s16*)(obj + 0xA) < D_800FA056_ovl11 - 0x18 ||
            *(s16*)(obj + 0xA) + 0x28 < D_8009A0AA) {
            set_animation(obj, 6);
            obj[6]++;
        }
    } else {
        if (D_800FA058_ovl11 + 0x18 < *(s16*)(obj + 0xA) ||
            D_8009A0AA < *(s16*)(obj + 0xA) - 0x28) {
            set_animation(obj, 6);
            obj[6]++;
        }
    }
}
