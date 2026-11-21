#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

void func_800F9A18_ovl28(Obj3DD4* e) {
    set_animation(e, 5);
    if (D_8009A0AA > e->unkA) {
        e->unk15 = 0x40;
    } else {
        e->unk15 = 0;
    }
    e->unk20 = 0;
    e->unk7C = 0;
    e->unk6++;
    func_8002D9EC(e, 0x30, 0x30);
    animate_object(e);
    apply_object_motion(e);
}

extern s32 player_spawn_dash_spark(void* arg0);

void func_800F9A9C_ovl28(u8* obj) {
    if (*(s8*)(obj + 0x45) == 1) {
        obj[0x45] = 0;
        if (D_8009A0AA > *(s16*)(obj + 0xA)) {
            obj[0x15] = 0x40;
        } else {
            obj[0x15] = 0;
        }
        if (obj[0x15] == 0) {
            *(s32*)(obj + 0x20) = 0xFFFBE000;
        } else {
            *(s32*)(obj + 0x20) = 0x42000;
        }
        play_sound(2, 0x85, obj);
        player_spawn_dash_spark(obj);
    }
    if (*(s8*)(obj + 0x45) == 2) {
        obj[6]++;
    }
    func_8002D9EC(obj, 0x30, 0x30);
    animate_object(obj);
    apply_object_motion(obj);
}

void func_800F9B74_ovl28(u8* obj) {
    s16 d;

    if (++*(s16*)(obj + 0x7C) >= 11) {
        d = D_8009A0AA - *(s16*)(obj + 0xA);
        if (*(s32*)(obj + 0x20) < 0) {
            if (d < -0x40) {
                goto end; // !FAKE: goto kept for the matching branch layout
            }
        } else if (d > 0x40) {
            goto end; // !FAKE: goto kept for the matching branch layout
        }
        play_sound(2, 0x86, obj);
        obj[6]++;
        *(s32*)(obj + 0x20) = 0;
    }
end:
    func_8002D9EC(obj, 0x30, 0x30);
    apply_object_motion(obj);
}

void func_800F9C30_ovl28(u8* obj) {
    if (*(s8*)(obj + 0x46) == 0) {
        set_animation(obj, 2);
        obj[5] = 3;
        obj[6] = 0;
    }
    func_8002D9EC(obj, 0x30, 0x30);
    animate_object(obj);
    apply_object_motion(obj);
}
