#include "types.h"
#include "mmx5/graphics.h"
#include "mmx5/globals.h"

extern s16 D_800FA64A_ovl29;

void func_800F49FC_ovl29(Ent* e) {
    if (e->y > D_800FA64A_ovl29) {
        e->flag15 = 0;
    } else {
        e->flag15 = 0x40;
    }
    set_animation(e, 0xA);
    e->state++;
}

extern u8 D_800FA2E0_ovl29[][6];

void func_800F4A5C_ovl29(u8* obj) {
    u8* child;
    s32 row;

    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x30;
            child[1] = 0x29;
            child[2] = 2;
            *(u8**)(child + 0x7C) = obj;
        }
        *(u8**)(obj + 0x80) = child;
        obj[0x45] = 0;
    }
    if (*(s8*)(obj + 0x45) == 2) {
        (*(u8**)(obj + 0x80))[6]++;
        obj[0x45] = 0;
    }
    if (*(s8*)(obj + 0x46) == 0) {
        row = obj[0x8D];
        obj[5] = D_800FA2E0_ovl29[row][obj[0x8E]];
        obj[0x8E]++;
        obj[6] = 0;
        set_animation(obj, 0, row);
    }
}
