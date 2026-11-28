#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/object.h"

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800494DC.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_init, AGPL-3.0; proven shared with X6 by exact signature 4a86628af3e4 (see THIRD_PARTY.md). */
#define SP(offset) (0x1F800000 + (offset))

void func_8004F458(X4_Obj* arg0, X4_Obj* arg1) {
    arg0->on_screen = 1;
    arg0->unk38 = 0;
    arg0->unk3C = (void*)((s8*)D_1F80001C.s32s + D_1F80001C.s32s[1]);
    arg0->animation_table = &g_visual_animation_tables.p;
    arg0->unk40 = 0;
    arg0->unk42 = 0x7804;
    arg0->unk16 = 1;
    func_8004F5CC(arg0, arg1);
    set_animation(arg0, 3);
    arg0->state++;
    func_8002D9EC(arg0, 0x20, 0x20);
}
#undef SP

void func_8004F4E0(u8* obj, u8* other) {
    s32 hit;

    animate_object(obj);
    hit = 0;
    if ((*(u32*)(other + 4) & 0xFFFF00) == 0xB00) {
        hit = 1;
    }
    if (*(s8*)(other + 5) == 0x34) {
        hit = 1;
    }
    if (hit) {
        func_8004F5CC(obj, other);
    } else {
        set_animation(obj, 4);
        obj[4]++;
    }
    func_8002D9EC(obj, 0x20, 0x20);
}

/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_80049670.c, AGPL-3.0 (THIRD_PARTY.md). */
/* Adapted from sozud/mmx4 @29b62af src/main/visuals/visual_00_wall_slide_dust.c:wall_slide_dust_fade, AGPL-3.0; proven shared with X6 by exact signature 246e79a6823b (see THIRD_PARTY.md). */

void func_8004F57C(ObjEE5C* arg0, X4_Obj* arg1) {
    ((void (*)())animate_object)(arg0);
    if (arg0->unk46 < 0) {
        ((void (*)())clear_object_slot)(arg0);
        return;
    }
    ((void (*)())func_8002D9EC)(arg0, 0x20, 0x20);
}

#include "shared/func_8004F5CC.c"

#define D_8007B5CC D_8007B5D4

#define func_8004F5CC func_8004F654
#include "shared/func_8004F5CC.c"
#undef func_8004F5CC
