#include "types.h"
#include "mmx5/globals.h"

s32 try_enter_ladder(u8* arg0);
s32 func_8003EF28(u8* arg0);
s32 func_800437FC(u8* arg0);
s32 player_check_dash_jump_walk(u8* arg0);
s32 func_8004387C(u8* arg0);
s32 func_80041A54(u8* arg0);
s32 check_crouch_input(u8* arg0);
void func_8003A70C(u8* arg0);

void func_800363B4(u8* arg0) {
    func_80043B88(arg0);
    if (func_80039ECC(arg0) != 0) {
        return;
    }
    if (try_enter_ladder(arg0) != 0) {
        return;
    }
    if (func_8003EF28(arg0) != 0) {
        return;
    }
    if (func_800437FC(arg0) != 0) {
        return;
    }
    if (player_check_dash_jump_walk(arg0) != 0) {
        return;
    }
    if (func_8004387C(arg0) != 0) {
        return;
    }
    if (func_80041A54(arg0) != 0) {
        return;
    }
    if (check_crouch_input(arg0) != 0) {
        return;
    }
    animate_object(arg0);
    if (((signed char*)arg0)[0x46] < 0) {
        func_8003A70C(arg0);
    } else {
        func_8003F2D8(arg0, 0xC);
    }
}
