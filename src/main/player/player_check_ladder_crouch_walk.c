#include "types.h"
s32 try_enter_ladder(u8* arg0);
s32 check_crouch_input(u8* arg0);
s32 func_800395E8(u8* arg0);
void func_8003A7E4(u8* arg0);

s32 player_check_ladder_crouch_walk(u8* arg0) {
    if (try_enter_ladder(arg0) != 0) {
        return 1;
    }
    if (check_crouch_input(arg0) != 0) {
        return 1;
    }
    if (func_800395E8(arg0) == 0) {
        return 0;
    }
    func_8003A7E4(arg0);
    return 1;
}
