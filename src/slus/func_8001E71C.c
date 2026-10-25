#include "types.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80016D54(s32, s32); /* extern */
void func_80017D88(void);     /* extern */
void func_80027288(void);     /* extern */
void func_8002C50C(void);     /* extern */
void func_8002D004(void);     /* extern */
extern s8 D_8009A424;

void func_8001E71C(void* arg0) {
    if (D_8009A424 == 0) {
        M2C_FIELD(arg0, s8*, 0xD) = 1;
        func_80027288();
        func_80017D88();
        func_80016D54(0xFF, 0);
        func_8002C50C();
        func_8002D004();
        M2C_FIELD(arg0, s8*, 1) = 0;
        M2C_FIELD(arg0, u8*, 0) = (u8)(M2C_FIELD(arg0, u8*, 0) + 1);
    }
}
