/* Shared body (DK-5): included by every member file src/<alias>/<name>.c, never compiled alone.
 * T4 probe: call, then u8 increment (rockx5 ovl00). Member file defines DEDUP_NAME (the member's symbol);
 * every member calls the resident set_animation. Census dup group of rockx5 func_800F2448_ovl00 (2 members:
 * ovl00, ovl01 func_800F3EAC_ovl01). */
#include "types.h"
#include "mmx5/graphics.h"

void DEDUP_NAME(Obj* o) {
    set_animation(o, 1);
    o->timer = 0x14;
    o->step++;
}
