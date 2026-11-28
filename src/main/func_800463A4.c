#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern void func_800454A8(u8* obj);
extern void func_80046420(u8* obj);

void func_800463A4(u8* obj) {
    if (is_off_screen(obj, 0x2A, 0x22) == 0) {
        animate_object(obj);
        if (*(s8*)(obj + 1) == 0x14) {
            func_800454A8(obj);
        } else {
            func_80046420(obj);
        }
    } else {
        obj[3] = 0;
        obj[4] = 3;
        *(s32*)(obj + 0x50) = 0;
        *(s32*)(obj + 0x68) = 0;
    }
}
