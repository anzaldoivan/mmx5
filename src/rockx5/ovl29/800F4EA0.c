#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"

extern s32 D_800F9898_ovl29[];

void func_800F4EA0_ovl29(Obj4EA0* e) {
    if (D_8009A0AA > e->unkA) {
        e->unk15 = 0x40;
    } else {
        e->unk15 = 0;
    }
    set_animation(e, 8);
    e->unk50 = D_800F9898_ovl29;
    e->unk6++;
}

extern u8 D_800FA2E0_ovl29[][6];

void func_800F4F0C_ovl29(u8* obj) {
    u8* child;
    s16 x;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x29;
            child[2] = 3;
            *(u8**)(child + 0x7C) = obj;
            x = *(s16*)(obj + 0xA);
            *(s16*)(child + 0xA) = obj[0x15] != 0 ? x + 0x17 : x - 0x17;
            *(s16*)(child + 0xE) = *(s16*)(obj + 0xE);
            play_sound(2, 0xAB, obj, child);
            play_sound(2, 0xB0, obj);
        }
        obj[0x45] = 0;
    }
    if (*(s8*)(obj + 0x46) == 0) {
        obj[5] = D_800FA2E0_ovl29[obj[0x8D]][obj[0x8E]];
        obj[0x8E]++;
        obj[6] = 0;
    }
}
