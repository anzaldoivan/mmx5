#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

#define D_800EEC60_ovl00 func_80049F6C
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00

void func_80049F74(s8* e) {
    if (e[2] == 0) {
        g_Player[7] = 1;
        g_Player[0x98]--;
        g_Player[0x99]--;
    }
    clear_object_slot(e);
}
