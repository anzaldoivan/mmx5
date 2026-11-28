#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"

extern void func_8003A9AC(void);
extern void func_8003A94C(u8* obj);
extern s32 func_8003EFE0(u8* arg0);
extern s32 func_800439A8(u8* obj);
extern void func_8003D344(void* arg0);

void func_80036920(u8* obj) {
    s32 t;

    if (obj[0x89] & 8) {
        func_8003A9AC();
        return;
    }
    if (*(s8*)(obj + 0xD3) != 0) {
        func_8003A94C(obj);
        return;
    }
    if (func_8003EFE0(obj) == 0 && func_800439A8(obj) == 0) {
        animate_object(obj);
        apply_object_motion(obj);
        func_8003D344(obj);
        t = obj[0x8A] - 1;
        obj[0x8A] = t;
        if ((t << 24) == 0) {
            *(s32*)(obj + 0x20) = 0;
            obj[5] = 7;
            obj[6] = 0;
            return;
        }
        player_update_animation_shooting(obj, 0xB);
    }
}
