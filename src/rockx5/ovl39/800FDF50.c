#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"
#include "mmx5/object.h"

void func_800FDF50_ovl39(u8* obj) {
    u8* p;

    animate_object(obj);
    *(u16*)(obj + 0xA) =
        *(u16*)(*(u8**)(obj + 0x7C) + 0xA) + *(u16*)(obj + 0x90);
    func_800317B8(obj);
    p = *(u8**)(obj + 0x7C);
    if (*(s8*)(p + 4) == 2 || *(s8*)(p + 6) >= 10) {
        obj[5]++;
    }
}

void func_800FDFCC_ovl39(u8* obj) {
    play_sound(2, 0x6C, obj);
    obj[4] = 2;
}

void func_800FE004_ovl39(EntFE004* obj) {
    animate_object(obj);
    func_800317B8(obj);
    move_object(obj);
    ((s32(*)())func_8002F8FC)(obj);
    if (obj->flags & 8) {
        obj->timer = 0x78;
        obj->state++;
    } else {
        func_8002D89C(obj);
    }
}

#include "shared/func_800FE070_ovl39.c"

void func_800FE130_ovl39(EntFE004* obj) {
    animate_object(obj);
    func_800317B8(obj);
    move_object(obj);
    ((s32(*)())func_8002F8FC)(obj);
    if (obj->flags & 7) {
        obj->timer = 0x78;
        obj->state++;
    }
}

#define func_800FE070_ovl39 func_800FE190_ovl39
#include "shared/func_800FE070_ovl39.c"
#undef func_800FE070_ovl39

void func_800FE250_ovl39(EntFE250* obj) {
    animate_object(obj);
    func_800317B8(obj);
    move_object(obj);
    ((s32(*)())func_8002F8FC)(obj);
    if (obj->flags != 0) {
        obj->unk58 = 0;
        obj->timer = 0x3C;
        obj->state++;
    }
}

void func_800FE2B0_ovl39(u8* arg0) {
    s32 t;

    arg0[3] ^= 1;
    t = *(u16*)(arg0 + 0x8C) - 1;
    *(u16*)(arg0 + 0x8C) = t;
    if ((t & 0xFFFF) == 0) {
        if (((s8*)arg0)[2] == 5) {
            (*(u8**)(arg0 + 0x7C))[0x8A] = 1;
        }
        arg0[4] = 2;
    }
}

extern u8 D_800FECD4_ovl39[];

void func_800FE2FC_ovl39(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        play_sound(2, 0xA9, obj);
        *(u8**)(obj + 0x50) = D_800FECD4_ovl39;
        *(s16*)(obj + 0x8C) = 50;
        obj[5]++;
    }
}

void func_800FE35C_ovl39(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 0x10) {
        *(*(u8**)(obj + 0x7C) + 0x8B) = 1;
        obj[4] = 2;
    }
}

void func_800FE3A0_ovl39(u8* a0) {
    u8* p;

    if ((*(u8**)(a0 + 0x7C))[0x47] == 0) {
        func_800317B8(a0);
    }
    p = *(u8**)(a0 + 0x7C);
    if (((s8*)p)[2] == 0) {
        *(u16*)(a0 + 0xA) = *(u16*)(p + 0xA) - 0x38;
    } else {
        *(u16*)(a0 + 0xA) = *(u16*)(p + 0xA) + 0x38;
    }
    *(u16*)(a0 + 0xE) = *(u16*)(*(u8**)(a0 + 0x7C) + 0xE);
    a0[3] = 0;
}

#define D_800EEC60_ovl00 func_800FE424_ovl39
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
