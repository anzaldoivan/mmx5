/* slus func_8004CD40: twin of func_800462D4 (dup1200), counter at +0xA6. */
#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

void func_8004CD40(s8* e) {
    g_Player[0xA6]--;
    clear_object_slot(e);
}
