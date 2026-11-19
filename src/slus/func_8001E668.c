#include "types.h"
#include "mmx5/globals.h"

void func_80027288(void);
void func_80017D88(void);
void silence_sound(s32, s32);
void func_8002D004(void);

void func_8001E668(void) {
    func_80027288();
    func_80017D88();
    silence_sound(0xFF, 0);
    func_8002C50C();
    func_8002D004();
}
