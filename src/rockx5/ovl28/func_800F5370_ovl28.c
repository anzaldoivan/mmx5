#include "types.h"
#include "mmx5/object.h"
#include "mmx5/sound.h"

extern u8 D_800FDC0C_ovl28[];
extern s8 D_800D1C2E;
extern void func_80044DD0(s32 a0);

void func_800F5370_ovl28(u8* obj) {
    move_object(obj);
    if (*(s16*)(obj + 0xE) >= 0x300) {
        *(u8**)(obj + 0x68) = D_800FDC0C_ovl28;
    }
    if (obj[0x70] & 8) {
        play_sound(2, 0x6E, obj);
        obj[0x67] = 0;
        if (D_800D1C2E != 0) {
            func_80044DD0(0);
            *(s16*)(obj + 0x7E) = 1;
            obj[6] = 8;
        } else {
            obj[6]++;
        }
    }
}
