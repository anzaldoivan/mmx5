#include "types.h"
#include "mmx5/ovl06.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8 D_800FF1E4_ovl06[];
extern u8 D_800FF1E8_ovl06[];
extern s16 D_800FF4F4_ovl06[][2];

void func_800F84F0_ovl06(u8* obj) {
    s32 i;
    s32 c;
    s32 d;

    animate_object(obj);
    move_object(obj);
    i = obj[0x15] == 0;
    c = D_800FF4F4_ovl06[i][0] + D_800FF94C_ovl06;
    if (*(s16*)(obj + 0xA) >= c - 4 && c + 4 >= *(s16*)(obj + 0xA)) {
        d = D_800FF4F4_ovl06[i][1] + D_800FF94E_ovl06;
        if (*(s16*)(obj + 0xE) >= d - 4 && d + 4 >= *(s16*)(obj + 0xE)) {
            set_animation(obj, 0xD);
            *(u8**)(obj + 0x50) = D_800FF1E4_ovl06;
            *(u8**)(obj + 0x54) = D_800FF1E8_ovl06;
            *(s16*)(obj + 0x7C) = 0x28;
            obj[6]++;
        }
    }
}
