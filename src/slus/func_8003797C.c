#include "types.h"

extern s32 func_80043B88(u8* obj);
extern void func_8003A9AC(u8* obj);
extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8003D344(void* arg0);

void func_8003797C(u8* obj) {
    func_80043B88(obj);
    if (obj[0x89] & 8) {
        func_8003A9AC(obj);
    } else {
        func_80017248(obj);
        func_8002DED4(obj);
        func_8003D344(obj);
    }
}
