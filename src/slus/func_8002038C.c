#include "types.h"

#include "types.h"

extern void (*D_80071074[])(u8*);
extern void func_80022618(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);
extern void func_800176DC(void);

void func_8002038C(u8* arg0) {
    D_80071074[*(signed char*)(arg0 + 1)](arg0);
    func_80022618();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
    func_800176DC();
}
