#include "types.h"
#include "mmx5/system.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"

extern u8* func_8002CA10(u8* obj, s32 arg1);
extern signed char D_800D1C0C;

void func_800F3C90_ovl10(u8* obj) {
    s32 lim;
    s16 x;
    u8* child;
    u8 st;
    u8 t;
    s32 r;

    if (D_800D1C0C != 0xC) {
        lim = 0x2000;
        x = 0x1F80;
    } else {
        lim = 0xB00;
        x = 0xA80;
    }
    apply_object_motion(obj);
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 2 && *(s32*)(obj + 0x24) <= 0) {
        set_animation(obj, 3);
    }
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) <= 0) {
        if (lim < *(s16*)(obj + 0xA)) {
            obj[0x15] = 0;
        } else {
            obj[0x15] = 0x40;
        }
        child = func_8002CA10(obj, 0);
        if (child != 0) {
            st = obj[0x8A];
            if (st != 2) {
                goto set7; // !FAKE: goto kept for the matching branch layout
            }
            if (*(s8*)(obj + 2) == 0) {
                if (*(s32*)(obj + 0x94) != 0) {
                    return;
                }
                obj[0x8F] = 0x14;
                r = random_byte() & 0xF;
                if (r < 3) {
                    obj[0x8B] = 0;
                } else if (r >= 0xD) {
                    obj[0x8B] = st;
                } else {
                    obj[0x8B] = 1;
                }
                obj[0x87] = 0x51;
                child[0] = 0x41;
                child[1] = obj[1];
                child[2] = 2;
                *(s32*)(child + 0x3C) = *(s32*)(obj + 0x3C);
                *(u16*)(child + 0x40) = *(u16*)(obj + 0x40);
                *(s32*)(child + 0x30) = *(s32*)(obj + 0x30);
                *(s16*)(child + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
                if (lim < *(s16*)(obj + 0xA)) {
                    *(s16*)(child + 0xA) = x;
                    child[0x15] = 0x40;
                    obj[0x15] = 0;
                } else {
                    *(s16*)(child + 0xA) = x + 0x100;
                    child[0x15] = 0;
                    obj[0x15] = 0x40;
                }
                child[0x8B] = obj[0x8B];
                child[0x87] = 0;
                child[0x8A] = obj[0x8A];
                *(s32*)(child + 0xC) = *(s32*)(obj + 0xC);
                *(u8**)(child + 0x80) = obj;
                *(u8**)(obj + 0x80) = child;
                obj[0x98] = 1;
            }
        }
        t = obj[0x8A];
        if (t == 2 && obj[0x8B] == t) {
            set_animation(obj, 8);
            obj[0x90] = 1;
        } else {
        set7:
            set_animation(obj, 7);
            obj[0x90] = 0;
        }
        obj[6] = 2;
        obj[7] = 0;
    }
}
