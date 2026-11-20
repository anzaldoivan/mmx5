#include "types.h"
#include "mmx5/globals.h"

void func_800F2294_ovl29(u8* o) {
    u8* p;
    u8* r;
    u8* q;
    u8* t;

    if (o[0x15] == 0) {
        p = g_Player;
        if (*(s32*)(o + 8) > *(s32*)(p + 8)) {
            goto body; // !FAKE: goto kept for the matching branch layout
        }
    } else {
        r = g_Player;
        if (*(s32*)(o + 8) < *(s32*)(r + 8)) {
        body: // !FAKE: label kept for the matching branch layout
            if (*(s32*)(o + 0x80) == 0) {
                q = g_Player;
                if (((*(s16*)(o + 0xA) - *(s16*)(q + 0xA)) < 0
                         ? (*(s16*)(q + 0xA) - *(s16*)(o + 0xA))
                         : (*(s16*)(o + 0xA) - *(s16*)(q + 0xA))) <
                    *(s16*)(o + 0x84)) {
                    o[0x7A] = 0;
                    o[6] = 1;
                }
            } else {
                t = g_Player;
                if (*(s16*)(o + 0x84) <
                    ((*(s16*)(o + 0xA) - *(s16*)(t + 0xA)) < 0
                         ? (*(s16*)(t + 0xA) - *(s16*)(o + 0xA))
                         : (*(s16*)(o + 0xA) - *(s16*)(t + 0xA)))) {
                    o[0x7A] = 0;
                    o[6] = 1;
                }
            }
        }
    }
}
