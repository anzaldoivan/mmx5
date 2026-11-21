#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"

extern u8 D_80074EE0[];
extern u8 D_800F9D1C_ovl11[];
extern u8 D_800F9D20_ovl11[];
extern s32 D_800F9D24_ovl11[];
extern s32 D_800F9D3C_ovl11[];

void func_800F8298_ovl11(u8* obj) {
    obj[4] = 1;
    obj[6] = 0;
    *(s16*)(obj + 0x88) = 0;
    obj[0x16] = 5;
    if (*(s8*)(obj + 2) == 0) {
        play_sound(2, 0x34, obj);
        obj[0x60] = 6;
        obj[5] = 0;
        set_animation(obj, 0xE);
        *(void**)(obj + 0x58) = D_80074EE0;
        *(void**)(obj + 0x54) = D_800F9D1C_ovl11;
        *(void**)(obj + 0x50) = D_800F9D20_ovl11;
        *(void**)(obj + 0x68) = 0;
        return;
    }
    obj[0x60] = 4;
    obj[5] = 3;
    set_animation(obj, 0xA);
    *(void**)(obj + 0x58) = 0;
    *(void**)(obj + 0x54) = 0;
    *(void**)(obj + 0x50) = &D_800F9D3C_ovl11[*(s8*)(obj + 0x45)];
    *(void**)(obj + 0x68) = &D_800F9D24_ovl11[*(s8*)(obj + 0x45)];
}
