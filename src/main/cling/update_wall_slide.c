#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 try_wall_jump(u8* arg0);
extern s32 is_pressing_into_wall(u8* arg0);
extern void func_8003A94C(u8* obj);
extern void func_8003A9AC(void);
extern void func_8003AEF0(u8* arg0);
extern void func_8003D344(void* arg0);
extern s32 func_8003EFE0(u8* arg0);
extern s32 func_80043B08(u8* arg0);

void update_wall_slide(u8* obj) {
    if (obj[0x89] & 8) {
        func_8003A9AC();
        return;
    }
    if (*(s8*)(obj + 0xD3) == 0) {
        if (func_8003EFE0(obj) != 0) {
            return;
        }
        if (func_80043B08(obj) != 0) {
            return;
        }
        if (obj[0x89] & 3) {
            goto rest; // !FAKE: goto kept for the matching branch layout
        }
    }
    func_8003A94C(obj);
    return;
rest: // !FAKE: label kept for the matching branch layout
    if (try_wall_jump(obj) != 0) {
        return;
    }
    if (is_pressing_into_wall(obj) != 0) {
        animate_object(obj);
        move_object(obj);
        func_8003D344(obj);
        player_update_animation_shooting(obj, 0xF);
        return;
    }
    func_8003AEF0(obj);
}
