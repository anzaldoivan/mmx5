#include "types.h"

extern s32 func_80016490(s32, s32, void*);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800F8DDC_ovl00(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        *(s16*)(obj + 0xA) = 0x127C;
        *(s16*)(obj + 0xE) = 0x11C;
        *(s16*)(obj + 0x7C) = 0xF;
        func_80016490(2, 4, obj);
        obj[6]++;
    }
    func_80017248(obj);
    func_8002DED4(obj);
}
