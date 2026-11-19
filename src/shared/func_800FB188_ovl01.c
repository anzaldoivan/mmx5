/* Shared body (DK-5), from the banked draft of func_800FB188_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void start_pad_vibration(s32);
extern void func_8002A600(s32, s32, s32);

void DEDUP_NAME(u8* obj) {
    animate_object(obj);
    apply_object_motion(obj);
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) < 0) {
        start_pad_vibration(5);
        play_sound(2, 7, obj);
        func_8002A600(0x14, 2, 2);
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        *(s16*)(obj + 0x7C) = 0;
        obj[6] = 4;
    }
}
