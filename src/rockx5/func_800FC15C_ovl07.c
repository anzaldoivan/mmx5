#include "types.h"

#define D_1F80004C (*(u8**)0x1F80004C)
#define ABS(x) ((x) < 0 ? -(x) : (x))

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void func_800FC15C_ovl07(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (ABS(*(s16*)(D_1F80004C + 0x84) - *(s16*)(obj + 0xA)) < 8) {
        obj[6] = 3;
    }
}
