#include "types.h"

extern void silence_sound(s32, s32);
extern void func_8003CEA4(u8* obj);

void player_reset_charge(u8* obj) {
    silence_sound(1, 7);
    func_8003CEA4(obj);
    obj[0x9B] = 0;
    obj[0x9C] = 0;
    obj[0x9D] = 0;
    obj[0x9E] = 0;
}
