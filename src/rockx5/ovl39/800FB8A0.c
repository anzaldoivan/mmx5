#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern u8* find_free_visual_obj(void);

void func_800FB8A0_ovl39(u8* obj) {
    s32 hit;
    u8* child;
    u8 f;

    hit = func_800317B8(obj);
    animate_object(obj);
    move_object(obj);
    if (func_80031DD0(obj) >= 0) {
        if (obj[0x70] == 0) {
            func_8002F8FC(obj);
        }
        if (hit != 0 || (((f = obj[0x70]) & 1) && *(s32*)(obj + 0x20) > 0) ||
            ((f & 2) && *(s32*)(obj + 0x20) < 0)) {
            child = find_free_visual_obj();
            if (child != 0) {
                child[0] = 0x61;
                child[1] = 0x15;
                child[2] = 0;
                *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
                *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                if (obj[0x15] != 0) {
                    *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
                } else {
                    *(u16*)(child + 0xA) = *(u16*)(obj + 0xA);
                }
                child[0x15] = obj[0x15];
                *(u16*)(child + 0xE) = *(u16*)(obj + 0xE);
                *(u8**)(child + 0x50) = obj;
            }
        } else {
            goto other; // !FAKE: goto kept for the matching branch layout
        }
    }
    obj[4]++;
    return;
other: // !FAKE: label kept for the matching branch layout
    func_8002D89C(obj);
}

void func_800FB9E8_ovl39(u8* obj) {
    u8* p;
    u8* q;
    s32 d;

    animate_object(obj);
    func_800317B8(obj);
    if (--*(u16*)(obj + 0x8C) != 0) {
        return;
    }
    if (*(s8*)(obj + 2) == 10) {
        p = g_Player;
        d = *(s16*)(p + 0xA) - *(s16*)(obj + 0xA);
        if ((d >= 0) ? (d >= 0x30)
                     : (*(s16*)(obj + 0xA) - *(s16*)(p + 0xA) >= 0x30)) {
            q = g_Player;
            if (*(s16*)(q + 0xA) > *(s16*)(obj + 0xA)) {
                *(s32*)(obj + 0x28) = -0x2800;
            } else {
                *(s32*)(obj + 0x28) = 0x2800;
            }
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x2C) = 0;
        } else {
            if (*(s16*)(obj + 0xE) >= 0x821) {
                *(s32*)(obj + 0x2C) = -0x2800;
            } else {
                *(s32*)(obj + 0x2C) = 0x2800;
            }
            *(s32*)(obj + 0x24) = 0;
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
        }
        *(u16*)(obj + 0x8C) = 0;
        obj[0x8E] = 0;
        obj[5]++;
    } else {
        obj[4] = 2;
    }
}
