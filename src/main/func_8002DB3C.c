/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8002CE18.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/objects.c:func_8002B468, AGPL-3.0; proven shared with X6 by exact signature 824e92a3c988 (see THIRD_PARTY.md). */
#include "types.h"
#include "mmx5/object.h"

EffectSlot30* func_8002DB3C(s8 id, s8 arg1) {
    EffectSlot30* effect;
    s8 i;

    i = 0;
    if (id >= 0) {
        do {
            effect = &g_class3_slots.eff[i];
            if (effect->active != 0 && effect->id == id &&
                effect->unk2 == arg1) {
                return effect;
            }
            i++;
        } while (i < 0x20);
    } else {
        id &= 0x7F;
        do {
            effect = &g_class3_slots.eff[i];
            if (effect->active != 0 && effect->id == id) {
                return effect;
            }
            i++;
        } while (i < 0x20);
    }
}
