#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D6FC(u8* obj);
extern void func_8002D89C(u8* obj);

void func_800EF534_ovl11(u8* obj) {
    func_80017248(obj);
    if ((*(s16*)(obj + 0x54))++ >= 0x97 && *(s8*)(obj + 0x45) == 1) {
        func_8002D6FC(obj);
    } else {
        func_8002D89C(obj);
    }
}
