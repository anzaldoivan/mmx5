#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/graphics.h"
#include "mmx5/weapon.h"
#include "mmx5/system.h"

extern u8 D_8007706C[];

void func_80047D24(u8* obj) {
    u8 f;

    apply_object_motion(obj);
    if (obj[0x15] != 0) {
        if (*(s32*)(obj + 0x20) < 0) {
            *(s32*)(obj + 0x28) = 0;
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else if (*(s32*)(obj + 0x20) > 0) {
        *(s32*)(obj + 0x28) = 0;
    clear: // !FAKE: label kept for the matching branch layout
        *(s32*)(obj + 0x20) = 0;
    }
    if (*(s8*)(obj + 0x98) != 0 || obj[0x70] != 0) {
        obj[0x8D] = 0x78;
        obj[0x8E] = 0;
        obj[0x8F] = 0x14;
        obj[0x90] = 0;
        set_animation(obj, 1);
        obj[5]++;
        if (*(s8*)(obj + 0x98) == 0 && (f = obj[0x70], (f & 0xF) != 0xF) &&
            !(f & 8)) {
            if (f & 2) {
                obj[0x8C] = 1;
            } else if (f & 1) {
                obj[0x8C] = 2;
            } else {
                goto zero; // !FAKE: goto kept for the matching branch layout
            }
        } else {
        zero: // !FAKE: label kept for the matching branch layout
            obj[0x8C] = 0;
        }
        *(u8**)(obj + 0x50) = D_8007706C;
        *(s32*)(obj + 0x68) = 0;
        obj[0x98] = 0;
    }
    func_8002FB58(obj);
}

extern void set_velocity_from_angle(void*, s32);
extern u8 D_80077084[][5];
extern u8 D_80077080[];

void func_80047E3C(u8* o) {
    u8* p;

    if (--o[0x8D] == 0) {
        goto done; // !FAKE: goto kept for the matching branch layout
    }
    if (*(s8*)(o + 0x98) != 0) {
        if (++o[0x8E] >= 3) {
        done: // !FAKE: shared exit label
            o[4] = 2;
            return;
        }
    }
    if (o[0x90] < 3) {
        if (--o[0x8F] == 0) {
            p = player_spawn_weapon(1, *(s8*)(o + 1), 1, o);
            if (p != 0) {
                set_velocity_from_angle(p,
                                        D_80077084[o[0x8C]][random_byte() % 5]);
                *(u16*)(p + 0xA) = *(u16*)(o + 0xA);
                *(u16*)(p + 0xE) = *(u16*)(o + 0xE);
                *(s32*)(p + 0x20) <<= 2;
                *(s32*)(p + 0x24) <<= 2;
                o[0x90]++;
            }
            o[0x8F] = D_80077080[random_byte() & 3];
        }
    }
}
