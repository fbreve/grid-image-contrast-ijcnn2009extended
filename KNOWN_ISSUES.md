# Potential issues in the historical C++Builder implementation

**Status:** source-code observations only. No supported C++Builder environment was available to build, run, reproduce or scientifically validate a fix. These are **not** confirmed runtime bugs, and no scientific algorithm or GUI source was changed during documentation maintenance.

Any proposed correction should be submitted separately, with the original [2019 Git snapshot](https://github.com/fbreve/grid-image-contrast-ijcnn2009extended/tree/archive/2019-initial-release) retained as a comparison reference.

## 1. Repeated heap allocation in UI text conversion

**File:** `interface.cpp`  
**Functions:** `doubletostr()` and `UpdateLabels()`

`doubletostr(double)` allocates a new 20-byte buffer with `malloc(20)` on every invocation and returns the pointer. `UpdateLabels()` uses the pointer to assign VCL label captions but does not free it. Since this code executes on periodic UI updates, it may leak memory throughout long simulation sessions.

**Possible maintenance fix:** use native string formatting (`FloatToStr`/`FormatFloat` or an equivalent supported by the historical compiler) or clearly manage buffer lifetime. Validate that formatted values and decimal separators still match historical behavior.

**Validation needed:** compile with the intended C++Builder version, exercise extended timer updates, compare memory usage and GUI text, and confirm there is no scientific-output change.

## 2. Image boundary accesses

**File:** `interface.cpp`  
**Function:** `TForm1::btnRunClick()`

The input-image loops iterate `i <= Width` and `j <= Height` before reading `Bitmap->Canvas->Pixels[i][j]`. Standard bitmap coordinates run from `0` to `Width-1` and `0` to `Height-1`; therefore these calls can request pixels outside the image boundary.

The destination arrays include a border (`M+2` by `N+2`), so **this is not necessarily a destination-buffer overflow**. The unverified concern is how VCL handles the out-of-range bitmap reads and what values enter the numerical model at those edges.

**Possible maintenance fix:** define border values explicitly and restrict actual image sampling to valid pixel coordinates. Do **not** make this change without checking the oscillator boundary conditions and model output, because the extra values could influence historical behavior.

**Validation needed:** images with known edge values, very small images, debugger bounds checks, and numerical comparison with historical output where possible.

## 3. Header guard ends before declarations

**File:** `dynarray.h`

The `#endif` matching the `#ifndef dynarrayH` guard appears **before** the declarations of `CreateDoubleArray`, `CreateIntArray`, `CreateBoolArray`, and the associated `DestroyArray` overloads.

This leaves the declarations outside the guard. Multiple declarations of the same function signature may be legal C++, so **this alone does not prove a compilation failure**. It is a maintainability issue that should be corrected in a future change if the build environment is available.

## 4. Portability and validation gap

The application depends on VCL and an old Borland/CodeGear toolchain. Historical project files refer to directories outside this repository. The distributed `RossGrid.exe` and compressed `.7z` archive have not been validated as matching the currently tracked source, and no build pipeline or repeatable scientific test exists.

**Before claiming a fix is verified:** identify the compiler version, build the application, compare its output on a known fixture, and capture evidence. Avoid conflating source cleanup with scientific validation.

## Suggested sequence

1. Recover a compatible C++Builder/Windows test environment and capture baseline behavior from the historical snapshot.
2. Fix the UI memory issue first, since it should be possible to isolate from the scientific computation.
3. Correct the header guard with a compile/build regression.
4. Investigate image boundaries alongside oscillator boundary conditions and numerical output.
5. Only then assess whether generated build products should be removed from a maintained branch.

Until those steps, the repository remains a **preserved historical implementation** rather than a validated contemporary port.
