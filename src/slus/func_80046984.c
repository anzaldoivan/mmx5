#include "types.h"
#include "mmx5/title.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void func_80046A40(u8* a0);
extern void func_80044F78(void* arg0);

void func_80046984(u8* a0) {
    if (is_off_screen(a0, 0x20, 0x20) == 0) {
        if (*(s8*)(a0 + 0x98) != 0) {
            func_80046A40(a0);
        } else {
            animate_object(a0);
            move_object(a0);
            if (a0[0x70] == 0) {
                ((s32(*)())func_8002F8FC)(a0);
            }
            if (a0[0x70] != 0) {
                func_80044F78(a0);
                func_80046A40(a0);
            }
            func_8002D9EC(a0, 0x20, 0x20);
        }
    } else {
        func_80046A40(a0);
    }
}
