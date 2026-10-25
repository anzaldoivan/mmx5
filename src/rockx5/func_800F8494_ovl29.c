#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D89C(u8*);

void func_800F8494_ovl29(u8* obj) {
    func_80017248(obj);
    func_8002D89C(obj);
    if (*(s8*)(obj + 0x46) == 0) {
        obj[4]++;
    }
}
