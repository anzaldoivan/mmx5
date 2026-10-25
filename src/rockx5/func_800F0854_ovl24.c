/* Adapted from mmx6 @c1c892d src/shared/rock_20/func_800EF704.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/engine.c:func_8001F9DC, AGPL-3.0; proven shared with X6 by exact signature 8d45f66608cd (see THIRD_PARTY.md). */
#include "types.h"
extern s8 D_8009A424[];
void func_8001E668();

void func_800F0854_ovl24(X4_Obj* arg0) {
    if (*D_8009A424 == 0) {
        func_8001E668();
        arg0->unk2++;
    }
}
