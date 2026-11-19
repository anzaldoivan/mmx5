/* Shared body (DK-5), from the banked draft of func_800FA978_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/ovl07.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "mmx5/globals.h"
#include "addr.h"

extern void func_800FCAD8_ovl07(u8* obj, s16 x, s16 y, s32 kind, s32 arg4);

static inline s16 func_800FA978_ovl07_rnd(void) {
    return (random_byte() & 0x1F) - 0x10;
}

void DEDUP_NAME(u8* obj) {
    s16 r;

    animate_object(obj);
    D_1F80004C.bytes[0x97] = 1;
    D_1F80004C.bytes[0x96] = D_80101C10_ovl07[D_1F80004C.s8s[0x97]][0];
    D_1F80004C.bytes[0x95] = D_80101C10_ovl07[D_1F80004C.s8s[0x97]][1];
    play_sound(2, 0x24, obj);
    switch (D_1F80004C.bytes[0x90]) {
    case 0:
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) - 0x60, 2, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) - 0x40, 2, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) - 0x20, 2, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) + 0x20, 2, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) + 0x40, 2, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) + 0x60, 2, 0);
        break;
    case 1:
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) - 0x60, 0, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) - 0x40, 0, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) - 0x20, 0, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) + 0x20, 0, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) + 0x40, 0, 0);
        r = (random_byte() & 0x1F) - 0x10;
        func_800FCAD8_ovl07(obj, *(s16*)(obj + 0xA),
                            r + *(s16*)(obj + 0xE) + 0x60, 0, 0);
        break;
    case 2:
        func_800FCAD8_ovl07(
            obj, func_800FA978_ovl07_rnd() + *(s16*)(obj + 0xA) - 0x60,
            *(s16*)(obj + 0xE), 1, 0);
        func_800FCAD8_ovl07(
            obj, func_800FA978_ovl07_rnd() + *(s16*)(obj + 0xA) - 0x40,
            *(s16*)(obj + 0xE), 1, 0);
        func_800FCAD8_ovl07(
            obj, func_800FA978_ovl07_rnd() + *(s16*)(obj + 0xA) - 0x20,
            *(s16*)(obj + 0xE), 1, 0);
        func_800FCAD8_ovl07(
            obj, func_800FA978_ovl07_rnd() + *(s16*)(obj + 0xA) + 0x20,
            *(s16*)(obj + 0xE), 1, 0);
        func_800FCAD8_ovl07(
            obj, func_800FA978_ovl07_rnd() + *(s16*)(obj + 0xA) + 0x40,
            *(s16*)(obj + 0xE), 1, 0);
        func_800FCAD8_ovl07(
            obj, func_800FA978_ovl07_rnd() + *(s16*)(obj + 0xA) + 0x60,
            *(s16*)(obj + 0xE), 1, 0);
        break;
    }
    *(s16*)(obj + 0x7C) = 0x14;
    obj[6]++;
}
