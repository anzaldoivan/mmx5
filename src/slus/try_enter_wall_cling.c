#include "types.h"

extern s32 try_wall_jump(u8* arg0);
extern s32 is_pressing_into_wall(u8* arg0);
extern void player_enter_wall_cling(u8* arg0);

s32 try_enter_wall_cling(u8* arg0) {
    if (*(s8*)(arg0 + 0xD3) != 0) {
        return 0;
    }
    if ((arg0[0x89] & 3) == 0) {
        return 0;
    }
    if (try_wall_jump(arg0) != 0) {
        return 1;
    }
    if (is_pressing_into_wall(arg0) == 0) {
        return 0;
    }
    player_enter_wall_cling(arg0);
    return 1;
}
