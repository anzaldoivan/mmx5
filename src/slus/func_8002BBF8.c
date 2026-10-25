#include "types.h"

extern Slot8002D27C D_800994A0[32];

void func_8002BBF8(void) {
    u8* b;
    u16 i;
    u16 j;
    u8 z;

    z = 0;

    for (i = 0; i < 32; i++) {
        b = (u8*)&D_800994A0[i];
        for (j = sizeof(Slot8002D27C) - 1; j != 0xFFFF; j--) {
            *b++ = z;
        }
    }
}
