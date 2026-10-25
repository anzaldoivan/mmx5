#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* obj);
extern s32 func_800F2F8C_ovl01(u8* obj);
extern s32 func_800F3040_ovl01(u8* obj);
extern s32 func_800F2FEC_ovl01(u8* obj);

void func_800F2AB8_ovl01(u8* obj) {
    func_80017248(obj);
    func_8002DF54(obj);
    if (func_800F2F8C_ovl01(obj) == 0 && func_800F3040_ovl01(obj) == 0) {
        func_800F2FEC_ovl01(obj);
    }
}
