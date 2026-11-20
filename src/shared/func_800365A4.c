/* Shared body (DK-5), from the banked draft of func_800365A4 by tools/wave/gate.py rescan. */
#include "types.h"
#include "mmx5/globals.h"

extern void update_wall_jump_push(u8* arg0);
extern void func_800366D4(u8* arg0);

void DEDUP_NAME(u8* arg0) {
    func_80043B88(arg0);
    if (*(s8*)(arg0 + 6) == 0) {
        update_wall_jump_push(arg0);
    } else {
        func_800366D4(arg0);
    }
}
