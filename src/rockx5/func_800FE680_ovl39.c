#include "types.h"

extern void func_80017248(u8* obj);

void func_800FE680_ovl39(u8* obj) {
    u8* parent = *(u8**)(obj + 0x50);

    func_80017248(obj);
    if (*(s8*)(parent + 6) >= 3 || *(s8*)(parent + 4) == 2) {
        obj[4]++;
    }
}
