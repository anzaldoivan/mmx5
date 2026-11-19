#include "types.h"
#include "mmx5/globals.h"

void func_8004A70C(u8* e) {
    u8* p = g_Player;

    *(s16*)(e + 0xA) = *(s16*)(p + 0xA);
    *(s16*)(e + 0xE) = *(s16*)(p + 0xE);
    if (*(s8*)(e + 0x46) == 0) {
        e[3] = 0;
        e[4] = 3;
    }
}
