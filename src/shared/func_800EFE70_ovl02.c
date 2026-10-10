/* Shared body (DK-5): included by every member file src/<alias>/<name>.c, never compiled alone.
 * Member file defines DEDUP_NAME (the member's symbol) and DEDUP_CALLEE (its jal target).
 * Census dup group of rockx5 func_800EFE70_ovl02 (15 members, slus + rockx5). */
#include "types.h"

void DEDUP_NAME(u8* o) {
    o[3] = 0;
    DEDUP_CALLEE(o);
}
