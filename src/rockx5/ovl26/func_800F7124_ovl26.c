#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"

extern u8 D_8009A197;
extern void* D_800FA494_ovl26[];

void func_800F7124_ovl26(u8* obj) {
    s8 state;

    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        animate_object(obj);
        ((void (*)(u8*))D_800FA494_ovl26[*(s8*)(obj + 5)])(obj);
    }
    state = *(s8*)(obj + 2);
    switch (state) {
    case 0:
    case 1:
        if (is_off_screen(obj, 0x168, 0x40) == 0) {
            func_8002D9EC(obj, 0x154, 0x20);
        } else {
            obj[4] = 2;
        }
        break;
    case 2:
    case 3:
        if (is_off_screen(obj, 0x40, 0x168) == 0) {
            func_8002D9EC(obj, 0x20, 0x154);
        } else {
            obj[4] = 2;
        }
        break;
    }
}
