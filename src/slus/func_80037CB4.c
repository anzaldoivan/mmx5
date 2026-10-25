#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern void func_8003A190(u8*);
extern void func_8003D2C4(void);
extern void func_8003A670(u8* arg0);
extern u8 D_8009A0A0[];

void func_80037CB4(u8* obj) {
    func_80017248(obj);
    if (*(s8*)(obj + 6) == 0) {
        if (obj[0xF5] == 4) {
            func_8003B33C(obj, 0x27);
            obj[6]++;
        }
    } else {
        if (*(s8*)(obj + 0x45) & 0x80) {
            obj[0x45] = 0;
            func_80016490(0, 0x21, 0);
        }
        if (*(s8*)(obj + 0x46) == 0) {
            func_8003A190(D_8009A0A0);
            func_8003D2C4();
            func_8003A670(obj);
        }
    }
}
