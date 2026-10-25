/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80020DC8.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/object_update.c:func_80021CC8, AGPL-3.0; proven shared with X6 by exact signature a99aed5959d6 (see THIRD_PARTY.md). */
#include "types.h"
#define COUNT(x) (sizeof(x) / sizeof(x[0]))
extern u8 D_8009A2F8[3][0x60];
void func_80022C84(u8* arg0);

void func_80022F3C(void) {
    u8(*var_s0)[0x60];

    for (var_s0 = D_8009A2F8; var_s0 < &D_8009A2F8[COUNT(D_8009A2F8)];
         var_s0++) {
        func_80022C84(*var_s0);
    }
}
