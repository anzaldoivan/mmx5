#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/movement.h"
#include "mmx5/object.h"

extern s32 func_8002D800(u8* a0);

void func_800F9B6C_ovl01(u8* obj) {
    u8* p;
    s32 k;

    if (((s8*)obj)[2] == 10) {
        func_8002D89C(obj);
        p = *(u8**)(obj + 0x50);
        if ((((s8*)p)[6] == 5 && *(s16*)(p + 0x7E) < 0x41) ||
            ((s8*)obj)[0x55] != 0) {
            obj[0x55]++;
            if (((s8*)obj)[0x55] < 10) {
                obj[0x47] = 0x34;
            } else if (((s8*)obj)[0x55] < 20) {
                k = 0x33;
            store47: // !FAKE: label for the shared store tail
                obj[0x47] = k;
            } else if (((s8*)obj)[0x55] < 30) {
                obj[0x47] = 0x32;
            } else {
                goto clear; // !FAKE: goto kept for the matching branch layout
            }
        } else {
            obj[0x47] = 0x34;
            obj[0x54]++;
            if (((s8*)obj)[0x54] < 10) {
                k = 0x32;
                goto store47; // !FAKE: goto kept for the matching branch layout
            } else if (((s8*)obj)[0x54] < 20) {
                obj[0x47] = 0x33;
            }
        }
    } else if (func_8002D800(obj) == 0) {
        apply_object_motion(obj);
        obj[3] ^= 1;
        if (obj[3] == 0) {
            *(u16*)(obj + 0x42) &= 0x7FFF;
            return;
        }
        func_8002D89C(obj);
    } else {
    clear: // !FAKE: label for the shared call
        clear_object_slot(obj);
    }
    *(u16*)(obj + 0x42) &= 0x7FFF;
}
