#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/movement.h"

void func_800F9B74_ovl28(u8* obj) {
    s16 d;

    if (++*(s16*)(obj + 0x7C) >= 11) {
        d = D_8009A0AA - *(s16*)(obj + 0xA);
        if (*(s32*)(obj + 0x20) < 0) {
            if (d < -0x40) {
                goto end; // !FAKE: goto kept for the matching branch layout
            }
        } else if (d > 0x40) {
            goto end; // !FAKE: goto kept for the matching branch layout
        }
        play_sound(2, 0x86, obj);
        obj[6]++;
        *(s32*)(obj + 0x20) = 0;
    }
end:
    func_8002D9EC(obj, 0x30, 0x30);
    apply_object_motion(obj);
}
