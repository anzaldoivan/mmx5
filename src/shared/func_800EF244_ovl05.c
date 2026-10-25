/* Shared body (DK-5), from the banked draft of func_800EF244_ovl05 by tools/wave/gate.py rescan. */
/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80050DFC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/items/item_08_boss_door.c:boss_door_update, AGPL-3.0; proven shared with X6 by exact signature 3841861bc21e (see THIRD_PARTY.md). */
#include "types.h"
#define BASE_OBJECT(object) ((X4_Obj*)(object))
extern void (*D_800F4FC8_ovl05[])(X4_Obj*);

#define M2C_UNK s32
s32 func_8002FB58(X4_Obj*);
void DEDUP_NAME(X4_Obj* arg0) {
    arg0->unk18.val = arg0->x_pos.val;
    arg0->unk1C.val = arg0->y_pos.val;
    D_800F4FC8_ovl05[arg0->state](arg0);
    ((s32(*)())func_8002FB58)(BASE_OBJECT(arg0));
}
