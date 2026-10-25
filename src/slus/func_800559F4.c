#include "types.h"

extern s32 func_80017E54(s32);
extern void func_80017B84(void);
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_800D1F3C;
extern u8 D_80091C44;

void func_800559F4(u8* obj) {
    if (((s8*)obj)[6] == 0) {
        if (D_80091C44 == 0) {
            func_80017E54(3);
            obj[6]++;
        }
    } else if (D_800D1F3C == 0) {
        func_80017B84();
        func_800171E8(obj, 12);
        obj[6] = 0;
        obj[5]++;
    }
}
