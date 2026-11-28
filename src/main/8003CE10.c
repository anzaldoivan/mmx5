#include "types.h"

void player_clear_dash(u8* arg0) {
    arg0[0x84] = 0;
    arg0[0x86] = 0;
    if (*(s8*)(arg0 + 0x8C) > 0) {
        *(s8*)(arg0 + 0x8C) = -1;
    }
}

extern void func_8003C5D8(u8* obj);

void player_clear_attack(u8* obj) {
    obj[0x8E] = 0;
    obj[0x8F] = 0;
    obj[0x90] = 0;
    obj[0x91] = 0;
    obj[0x92] = 0;
    obj[0xA2] = 0;
    func_8003C5D8(obj);
}
