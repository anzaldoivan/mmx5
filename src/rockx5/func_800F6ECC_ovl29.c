#include "types.h"

extern s32 func_8002FB58(u8* obj);
extern void (*D_800FA550_ovl29[])(u8*);

void func_800F6ECC_ovl29(u8* obj) {
    u8* parent;
    s8 state;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    parent = *(u8**)(obj + 0x7C);
    func_8002FB58(obj);
    state = *(s8*)(parent + 4);
    if (state == 2) {
        obj[4] = state;
        obj[5] = 0;
        obj[6] = 0;
    }
    D_800FA550_ovl29[*(s8*)(obj + 4)](obj);
}
