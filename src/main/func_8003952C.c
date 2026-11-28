#include "types.h"

s32 player_check_dash_input(void* arg0);
void func_8003A30C(void* arg0);
void func_8003A874(void* arg0);

s32 func_8003952C(u8* arg0) {
    if (player_check_dash_input(arg0)) {
        func_8003A30C(arg0);
        return 1;
    }
    if (*(u16*)(arg0 + 0x80) & 0x80) {
        func_8003A874(arg0);
        return 1;
    }
    return 0;
}
