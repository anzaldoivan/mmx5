#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/sound.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80037F70.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/player.c:player_script_vanish, AGPL-3.0; proven shared with X6 by exact signature 8c272e77d29e (see THIRD_PARTY.md). */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define ANIMATED_OBJECT(object) ((X4_Obj*)(object))

void player_script_vanish(X4_Obj* self) {
    if (func_80039ECC(self) == 0 && self->unk6 == 0) {
        ((void (*)())animate_object)(ANIMATED_OBJECT(self));
        if (M2C_FIELD(self, s8*, 0x46) == 0) {
            self->on_screen = 0;
            self->unk6++;
        }
    }
}
#undef M2C_FIELD
#undef ANIMATED_OBJECT

extern void func_8003CE64(u8* obj);
extern void set_stand_animation_by_hp(u8* obj);

void func_80037BEC(u8* obj) {
    if (((s8*)obj)[6] == 0) {
        animate_object(obj);
        apply_object_motion(obj);
        if (*(s32*)(obj + 0x24) <= 0) {
            func_8003B33C(obj, 0xB);
            ((s8*)obj)[0x67] = -1;
            *(s32*)(obj + 0x24) = 0;
            obj[6]++;
        }
    } else if (obj[0x89] & 8) {
        func_8003CE64(obj);
        set_stand_animation_by_hp(obj);
        obj[0x67] = 0;
        ((s8*)obj)[0xD0] = -1;
        obj[5] = 0x14;
        obj[6] = 0;
    } else {
        animate_object(obj);
        apply_object_motion(obj);
    }
}

extern void func_8003A190(u8*);
extern void func_8003A670(u8* arg0);

void func_80037CB4(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 6) == 0) {
        if (obj[0xF5] == 4) {
            func_8003B33C(obj, 0x27);
            obj[6]++;
        }
    } else {
        if (*(s8*)(obj + 0x45) & 0x80) {
            obj[0x45] = 0;
            play_sound(0, 0x21, 0);
        }
        if (*(s8*)(obj + 0x46) == 0) {
            func_8003A190(g_Player);
            func_8003D2C4();
            func_8003A670(obj);
        }
    }
}

extern void func_8003B28C(u8* obj);
extern u8 D_800D1F3C;

void func_80037D68(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 6) == 0) {
        if (D_800D1F3C == 0) {
            func_8003B33C(obj, 0x27);
            obj[6]++;
        }
    } else {
        if (*(s8*)(obj + 0x45) & 0x80) {
            obj[0x45] = 0;
            play_sound(0, 0x21, 0);
        }
        if (*(s8*)(obj + 0x46) == 0) {
            func_8003B33C(obj, 0x28);
            func_8003B28C(obj);
        }
    }
}
