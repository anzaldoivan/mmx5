#include "types.h"
#include "mmx5/globals.h"

extern void func_8002D004(void);
extern void init_checkpoint_positions(void);
extern void func_8002906C(void);
extern s32 func_80027238(void);

void func_800EEC44_ovl21(u8* arg0) {
    func_8002C50C();
    func_8002D004();
    init_checkpoint_positions();
    func_8002906C();
    func_80027238();
    arg0[1]++;
}
