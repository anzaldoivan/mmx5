#include "types.h"
#include "mmx5/object.h"

/* The box copy (a3 -> t1) in the 0x15 bne delay slot comes from
   `b = box;` written after x in each arm plus a dead reset of box after the if/else (C0070). */
static inline u8 func_800F7FF4_hit(u8* o, u8* box, s16 x, s16 px, s16 py) {
    s16 y;

    y = *(u16*)(o + 0xE) + ((s8*)box)[1];
    if (px < x - box[2]) {
        return 0;
    }
    if (x + box[2] - 1 < px) {
        return 0;
    }
    if (py < y - box[3]) {
        return 0;
    }
    if (y + box[3] - 1 < py) {
        return 0;
    }
    return 0x38;
}

s32 func_800F7FF4_ovl07(u8* arg0, s16 arg1, s16 arg2) {
    s32 i;
    u8* o;
    u8* box;
    u8* b;
    s16 x;
    u8 r;

    i = 0;
    o = g_class4_slots.u;
    for (; i < 0x40; i++, o += 0xA4) {
        if (o == arg0) {
            continue;
        }
        if (((s8*)o)[0] == 0) {
            continue;
        }
        if (((s8*)o)[0xA2] == 0) {
            continue;
        }
        box = *(u8**)(o + 0x68);
        if (box == 0) {
            continue;
        }
        if (o[0x15] == 0x40) {
            x = *(u16*)(o + 0xA) - ((s8*)box)[0];
            b = box;
        } else {
            x = *(u16*)(o + 0xA) + ((s8*)box)[0];
            b = box;
        }
        box = 0; // !FAKE: dead reset keeps the box copy (C0070)
        r = func_800F7FF4_hit(o, b, x, arg1, arg2);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}
