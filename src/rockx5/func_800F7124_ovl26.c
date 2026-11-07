#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A197;
extern void* D_800FA494_ovl26[];

void func_800F7124_ovl26(u8* obj) {
    s8 state;

    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        func_80017248(obj);
        ((void (*)(u8*))D_800FA494_ovl26[*(s8*)(obj + 5)])(obj);
    }
    state = *(s8*)(obj + 2);
    switch (state) {
    case 0:
    case 1:
        if (func_8002D938(obj, 0x168, 0x40) == 0) {
            func_8002D9EC(obj, 0x154, 0x20);
        } else {
            obj[4] = 2;
        }
        break;
    case 2:
    case 3:
        if (func_8002D938(obj, 0x40, 0x168) == 0) {
            func_8002D9EC(obj, 0x20, 0x154);
        } else {
            obj[4] = 2;
        }
        break;
    }
}
