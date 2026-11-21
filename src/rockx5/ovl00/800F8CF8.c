#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/graphics.h"
#include "mmx5/movement.h"

void func_800F8CF8_ovl00(u8* obj) {
    set_animation(obj, 4);
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x50) = 0;
    *(s32*)(obj + 0x54) = 0;
    *(s16*)(obj + 0x7C) = 15;
    obj[6]++;
    play_sound(2, 4, obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}

void func_800F8D6C_ovl00(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        *(s16*)(obj + 0x7C) = 0x78;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}

void func_800F8DDC_ovl00(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        *(s16*)(obj + 0xA) = 0x127C;
        *(s16*)(obj + 0xE) = 0x11C;
        *(s16*)(obj + 0x7C) = 0xF;
        play_sound(2, 4, obj);
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
}

extern u8 D_800FB3DC_ovl00[];
extern u8 D_800FB3E8_ovl00[];

void func_800F8E60_ovl00(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        set_animation(obj, 0);
        *(u8**)(obj + 0x50) = D_800FB3DC_ovl00;
        *(u8**)(obj + 0x54) = D_800FB3E8_ovl00;
        *(s16*)(obj + 0x7C) = 10;
        obj[6]++;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}

extern u8 D_800FB448_ovl00[][6];

void func_800F8EF4_ovl00(Ent8EF4* obj) {
    if (--obj->unk7C == -1) {
        obj->unk5 = D_800FB448_ovl00[obj->unk8D][obj->unk8E++];
        obj->unk6 = 0;
    }
    animate_object(obj);
    apply_object_motion(obj);
    func_8002D9EC(obj, 0xFF, 0xFF);
}
