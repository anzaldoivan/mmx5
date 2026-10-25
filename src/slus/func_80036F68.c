#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* obj);
extern void func_8003B33C(u8* obj, s32 arg1);
extern void func_8003B0EC(u8* obj);

void func_80036F68(u8* obj) {
    func_80017248(obj);
    func_8002DF54(obj);
    if (*(s8*)(obj + 0x46) < 0) {
        func_8003B33C(obj, 0x1F);
        func_8003B0EC(obj);
    }
}
