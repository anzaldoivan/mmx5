#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_80053038(u8* obj) {
    u8* p;
    u8* q;
    u8* r;
    u8* t;
    s32 d;

    p = g_Player;
    d = *(s16*)(p + 0xE) - *(s16*)(obj + 0xE);
    if (d >= 0) {
        if (d < 4) {
            *(s32*)(obj + 0x24) = 0;
        } else {
            goto block_4; // !FAKE: goto kept for the matching branch layout
        }
    } else if ((*(s16*)(obj + 0xE) - *(s16*)(p + 0xE)) >= 4) {
    block_4: // !FAKE: label kept for the matching branch layout
        q = g_Player;
        if (*(s16*)(q + 0xE) >= *(s16*)(obj + 0xE)) {
            *(s32*)(obj + 0x24) = 0xFFFF0000;
        } else {
            *(s32*)(obj + 0x24) = 0x10000;
        }
    } else {
        *(s32*)(obj + 0x24) = 0;
    }
    move_object(obj);
    if (obj[0x84] == 0) {
        r = g_Player;
        if (*(s16*)(r + 0xA) > *(s16*)(obj + 0xA)) {
            obj[0x84] = 1;
            *(s16*)(obj + 0x7C) = 0x1E;
            obj[6]++;
        }
    } else if (t = g_Player, *(s16*)(t + 0xA) < *(s16*)(obj + 0xA)) {
        obj[0x84] = 0;
        *(s16*)(obj + 0x7C) = 0x1E;
        obj[6]++;
    }
}
