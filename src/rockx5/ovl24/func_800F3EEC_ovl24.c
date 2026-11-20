#include "types.h"

void func_800F4D50_ovl24(u8* arg0, s16 arg1, s16 arg2, u8 arg3);
extern s32 D_800D1CB0;
extern s16 D_800F5954_ovl24[];

void func_800F3EEC_ovl24(u8* arg0) {
    s32 t;
    s32 min;
    s32 sec;
    s32 frm;
    s32 hi;
    s32 lo;

    t = D_800D1CB0;
    func_800F4D50_ovl24(arg0, 0, 0, 0x1B);
    func_800F4D50_ovl24(arg0, 0, 0, 0x1C);
    if (t > 359999) {
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[0], D_800F5954_ovl24[1],
                            0x89);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[2], D_800F5954_ovl24[3],
                            0x89);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[4], D_800F5954_ovl24[5],
                            0x85);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[6], D_800F5954_ovl24[7],
                            0x89);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[8], D_800F5954_ovl24[9],
                            0x89);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[10], D_800F5954_ovl24[11],
                            0x89);
    } else if (t <= 0) {
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[0], D_800F5954_ovl24[1],
                            0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[2], D_800F5954_ovl24[3],
                            0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[4], D_800F5954_ovl24[5],
                            0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[6], D_800F5954_ovl24[7],
                            0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[8], D_800F5954_ovl24[9],
                            0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[10], D_800F5954_ovl24[11],
                            0x80);
    } else {
        min = t / 3600;
        sec = t / 60;
        sec -= min * 60;
        frm = t / 60;
        frm = t - frm * 60;
        if (min >= 100) {
            min = 99;
        }
        if (min != 0) {
            hi = min / 10;
            lo = min % 10;
        } else {
            hi = 0;
            lo = 0;
        }
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[0], D_800F5954_ovl24[1],
                            hi + 0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[2], D_800F5954_ovl24[3],
                            lo + 0x80);
        if (sec != 0) {
            hi = sec / 10;
            lo = sec % 10;
        } else {
            hi = 0;
            lo = 0;
        }
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[4], D_800F5954_ovl24[5],
                            hi + 0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[6], D_800F5954_ovl24[7],
                            lo + 0x80);
        if (frm != 0) {
            frm = frm * 100 / 60;
            hi = frm / 10;
            lo = frm % 10;
        } else {
            hi = 0;
            lo = 0;
        }
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[8], D_800F5954_ovl24[9],
                            hi + 0x80);
        func_800F4D50_ovl24(arg0, D_800F5954_ovl24[10], D_800F5954_ovl24[11],
                            lo + 0x80);
    }
    arg0[4] = 2;
}
