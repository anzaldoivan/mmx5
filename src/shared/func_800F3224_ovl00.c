/* Shared body (DK-5), from the banked draft of func_800F3224_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/title.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_8009A197;
extern void (*D_800FADCC_ovl00[])(u8* obj);
extern u8 D_800FADB8_ovl00[];

void DEDUP_NAME(u8* obj) {
    u8* base;
    s32 off;
    s32 r;

    if (D_8009A197 == 0) {
        D_800FADCC_ovl00[(s8)obj[5]](obj);
        animate_object(obj);
    }
    func_800317B8(obj);
    r = 2; /* r holds the 2: a literal is cse-reused across the calls (phantom $s1) */
    if ((s8)obj[2] != r && (r = func_80031DD0(obj)) < 0) {
        goto dead; // !FAKE: early exit joins the target's shared death block
    }
    if (obj[0x70] != 0 || (((s32(*)())func_8002F8FC)(obj), obj[0x70] != 0)) {
        if ((s8)obj[2] == 2) {
            obj[0] = 0x21;
            obj[0x15] = 0;
            *(s32*)(obj + 0x38) = 0;
            base = D_1F80001C.bytes;
            off = *(s32*)(base + 8);
            *(s16*)(obj + 0x40) = 0;
            *(s16*)(obj + 0x42) = 0x7804;
            *(u8**)(obj + 0x3C) = base + off;
            set_animation(obj, 0x11);
            if (random_byte() & 1) {
                play_sound(0, 2, obj);
            } else {
                play_sound(0, 3, obj);
            }
            obj[0x60] = 4;
            *(u8**)(obj + 0x50) = D_800FADB8_ovl00;
            obj[4] = 2;
            obj[7] = 0;
            return;
        }
    dead:
        ((s32(*)())func_8004FD24)(obj);
        obj[4] = 3;
        return;
    }
    if (is_off_screen(obj, 0x40, 0x20) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
        return;
    }
    obj[4] = 3;
}
