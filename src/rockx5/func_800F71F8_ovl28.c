#include "types.h"

extern void func_80017248(u8* p);

void func_800F71F8_ovl28(u8* p) {
    func_80017248(p);
    if (*(s8*)(*(u8**)(p + 0x50) + 6) == 2) {
        p[4]++;
    }
}
