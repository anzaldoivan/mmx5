#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern void start_pad_vibration(s32);
extern void func_800FAFFC_ovl06(u8*, s32, s32, s32);

void func_800F81FC_ovl06(u8* obj) {
    apply_object_motion(obj);
    animate_object(obj);
    ((s32(*)())func_8002FB58)(obj);
    if (obj[0x70] & 8) {
        start_pad_vibration(5);
        play_sound(2, 7, obj);
        set_animation(obj, 0x1B);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) - 0x48),
                            *(s16*)(obj + 0xE), 4);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) - 0x38),
                            *(s16*)(obj + 0xE), 3);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) - 0x28),
                            *(s16*)(obj + 0xE), 2);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) - 0x18),
                            *(s16*)(obj + 0xE), 1);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) - 8),
                            *(s16*)(obj + 0xE), 0);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) + 8),
                            *(s16*)(obj + 0xE), 0);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) + 0x18),
                            *(s16*)(obj + 0xE), 1);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) + 0x28),
                            *(s16*)(obj + 0xE), 2);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) + 0x38),
                            *(s16*)(obj + 0xE), 3);
        func_800FAFFC_ovl06(obj, (s16)(*(s16*)(obj + 0xA) + 0x48),
                            *(s16*)(obj + 0xE), 4);
        *(s16*)(obj + 0x7C) = 0x3C;
        obj[6]++;
    }
}
