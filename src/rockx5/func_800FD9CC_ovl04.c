#include "types.h"

extern void func_80017248();
extern void func_8002DF54(u8* o);

void func_800FD9CC_ovl04(u8* o) {
    func_80017248();
    func_8002DF54(o);
    if (*(s8*)(o + 0x46) == 0) {
        *(u8*)(o + 4) = 2;
    }
}
