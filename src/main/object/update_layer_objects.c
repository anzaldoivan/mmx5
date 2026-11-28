/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800208EC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/object_update.c:update_layer_objects, AGPL-3.0; proven shared with X6 by exact signature 00a3e13855ef (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"
#include "addr.h"

extern void (*D_800712B4[])(s8*);

/* scratchpad 0x1F80006C, the slot after D_1F800068 (addr.h has no D_1F80006C entry) */
#define CUR_OBJ ((&D_1F800068)[1])

void update_layer_objects(void) {
    for (CUR_OBJ = (s8*)g_class7_slots.d144;
         CUR_OBJ < (s8*)&g_class7_slots.d144[4];
         CUR_OBJ += sizeof(Slot8002D144)) {
        if (g_playthrough_state.s[0x19] == 0 && CUR_OBJ[0]) {
            D_800712B4[CUR_OBJ[1]](CUR_OBJ);
        } else if (g_playthrough_state.s[0x19] && (u8)CUR_OBJ[0] & 8) {
            D_800712B4[CUR_OBJ[1]](CUR_OBJ);
        }
    }
}
#undef CUR_OBJ
