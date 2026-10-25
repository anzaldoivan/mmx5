#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002D6FC(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_8002D89C(u8*);

void func_80050138(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 0x46) < 0) {
        func_8002D6FC(obj);
        return;
    }
    if (*(s8*)(obj + 2) != 0) {
        func_8002DF54(obj);
    }
    func_8002D89C(obj);
}
