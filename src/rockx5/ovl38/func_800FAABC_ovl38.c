#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern void func_800FCB74_ovl38(u8* arg0, s32 arg1);
extern u8 D_800FD558_ovl38[];

void func_800FAABC_ovl38(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        switch (D_800FD558_ovl38[*(s16*)(D_1F80004C.bytes + 0x86) +
                                 *(s16*)(obj + 0x7E) * 7]) {
        case 0:
            func_800FCB74_ovl38(obj, 3);
            play_sound(2, 0xA0, obj);
            break;
        case 1:
            func_800FCB74_ovl38(obj, 4);
            play_sound(2, 0xA0, obj);
            break;
        case 2:
            func_800FCB74_ovl38(obj, 5);
            func_800FCB74_ovl38(obj, 6);
            play_sound(2, 0xA0, obj);
            break;
        case 4:
            set_animation(obj, 0x18);
            *(s16*)(obj + 0x7C) = 0x32;
            obj[6]++;
            return;
        }
        (*(s16*)(D_1F80004C.bytes + 0x86))++;
    }
    if (*(s8*)(obj + 0x45) == 2) {
        set_animation(obj, 0x18);
        if (D_800FD558_ovl38[*(s16*)(D_1F80004C.bytes + 0x86) +
                             *(s16*)(obj + 0x7E) * 7] == 4) {
            *(s16*)(obj + 0x7C) = 0x32;
            obj[6]++;
        } else {
            obj[6]--;
        }
    }
}
