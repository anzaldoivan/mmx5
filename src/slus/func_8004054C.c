#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8003AA4C(u8* arg0);

void func_8004054C(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x99) == 0 || *(s8*)(obj + 0x93) != 3) {
        func_8003AA4C(obj);
    }
}
