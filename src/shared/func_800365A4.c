#include "types.h"
#include "mmx5/globals.h"

extern void update_wall_jump_push(u8* arg0);
extern void update_wall_jump_rise(u8* arg0);

void func_800365A4(u8* arg0) {
    func_80043B88(arg0);
    if (*(s8*)(arg0 + 6) == 0) {
        update_wall_jump_push(arg0);
    } else {
        update_wall_jump_rise(arg0);
    }
}
