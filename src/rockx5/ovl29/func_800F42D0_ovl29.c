#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#define D_8009A420_as_s32 (*(s32*)&D_8009A420)

extern void func_80017BF4(void);
extern u8 D_800F988C_ovl29[];

void func_800F42D0_ovl29(u8* obj) {
    if (*(s8*)(obj + 0x5C) < D_800D1CA2) {
        if (--*(s16*)(obj + 0x7E) == 0) {
            play_sound(0, 0xE, 0);
            *(s16*)(obj + 0x7E) = 3;
        }
        if (!(D_8009A420_as_s32 & 1)) {
            obj[0x5C]++;
        }
        func_8002D9EC(obj, 0x40, 0x40);
    } else {
        func_80017BF4();
        set_animation(obj, 0);
        obj[5] = 4;
        obj[6] = 0;
        *(u8**)(obj + 0x54) = D_800F988C_ovl29;
        func_8003D2C4();
        func_8002D9EC(obj, 0x40, 0x40);
    }
}
