#include "interface.h"
#include <math.h>

brent_root_c11_err_t brent_solve(scalar_fn_t f, void* ctx, double a, double b, double tol, int max_iter, brent_result_t* out) {
    if (!f || !out) return BRENT_ROOT_C11_ERR_NULL;
    double fa = f(a, ctx), fb = f(b, ctx);
    brent_root_c11_err_t err = validate_bracket(fa, fb, tol, max_iter);
    if (err != BRENT_ROOT_C11_OK) return err;
    if (fabs(fa) < fabs(fb)) {
        double tx = a; a = b; b = tx;
        double tf = fa; fa = fb; fb = tf;
    }
    double c = a, fc = fa, d = b - a;
    bool mflag = true;
    for (int iter = 1; iter <= max_iter; ++iter) {
        if (fabs(fb) <= tol || fabs(b - a) <= tol) {
            *out = (brent_result_t){b, fb, iter, true};
            return BRENT_ROOT_C11_OK;
        }
        double s;
        if (fa != fc && fb != fc) {
            s = (a * fb * fc) / ((fa - fb) * (fa - fc))
              + (b * fa * fc) / ((fb - fa) * (fb - fc))
              + (c * fa * fb) / ((fc - fa) * (fc - fb));
        } else {
            s = fast_secant_step(a, b, fa, fb);
        }
        double mid34 = (3.0 * a + b) * 0.25;
        bool cond1 = !((s > mid34 && s < b) || (s < mid34 && s > b));
        bool cond2 = mflag && fabs(s - b) >= fabs(b - c) * 0.5;
        bool cond3 = !mflag && fabs(s - b) >= fabs(c - d) * 0.5;
        if (cond1 || cond2 || cond3) {
            s = 0.5 * (a + b);
            mflag = true;
        } else {
            mflag = false;
        }
        double fs = f(s, ctx);
        d = c; c = b; fc = fb;
        if (fa * fs < 0.0) { b = s; fb = fs; }
        else { a = s; fa = fs; }
        if (fabs(fa) < fabs(fb)) {
            double tx = a; a = b; b = tx;
            double tf = fa; fa = fb; fb = tf;
        }
    }
    *out = (brent_result_t){b, fb, max_iter, fabs(fb) <= tol};
    return BRENT_ROOT_C11_OK;
}
