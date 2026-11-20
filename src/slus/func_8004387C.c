#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"

extern s32 func_80044328(u8*);
extern void func_8003CF74(u8*, s32);
extern void func_80042090(u8*);

s32 func_8004387C(u8* arg0) {
    if (func_80044328(arg0) == 0) {
        return 0;
    }
    func_8003B33C(arg0, 0x58);
    play_sound(1, 7, arg0);
    if (random_byte() & 4) {
        func_8003CF74(arg0, 3);
    }
    arg0[0x84] = 0;
    arg0[0x86] = 0;
    arg0[5] = 0x30;
    arg0[6] = 0;
    func_80042090(arg0);
    return 1;
}
