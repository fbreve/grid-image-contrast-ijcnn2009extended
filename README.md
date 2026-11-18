# RossGrid — Chaotic Phase Synchronization for Object Selection

**Historical C++Builder / VCL implementation** of the **extended journal version** of a study first presented at **IJCNN 2009** and subsequently selected for publication in *Neural Networks*:

> Breve, Fabricio Aparecido; Zhao, Liang; Quiles, Marcos Gonçalves; and Macau, Elbert Einstein Nehrer. **Chaotic Phase Synchronization and Desynchronization in an Oscillator Network for Object Selection**. *Neural Networks*, **22**(5–6), 728–737, 2009. DOI: [10.1016/j.neunet.2009.06.027](https://doi.org/10.1016/j.neunet.2009.06.027).

**Paper:** [Publisher DOI](https://doi.org/10.1016/j.neunet.2009.06.027) · [Author-hosted manuscript (PDF)](https://www.fabriciobreve.com/artigos/ijcnn2009extended.pdf) · [arXiv preprint (posted in 2020)](https://arxiv.org/abs/2002.05493)

### Publication history

The research was **first presented at the 2009 International Joint Conference on Neural Networks (IJCNN)**. The work was then **selected for an extended version published in the journal *Neural Networks***, also in 2009. **This repository corresponds to the extended journal version**, not to a separate archive of the original IJCNN conference version. The *Neural Networks* article is therefore the **primary citation for this repository**.

The extended article describes a network of coupled chaotic oscillators in which oscillators representing a salient image object can become phase synchronized, enabling object selection and attention shifts.

## Status and scope

**Preserved historical research software — not a modern, supported build.**

- The application uses **Borland/CodeGear C++Builder with the proprietary VCL framework**. It is not directly compilable with ordinary GCC, Clang, or Microsoft Visual C++ without a port of the GUI and platform-dependent code.
- Original C++ source files, VCL form files, project definitions, the historical Windows executable and the supplied compressed archive remain on `master`. Generated compiler artifacts and editor backups are preserved in `archive/2019-initial-release` but no longer tracked in `master`.
- **No successful contemporary compile, application launch, or reproduction of the 2009 experiments is claimed.** Historical project paths and dependencies may require restoration of a suitable C++Builder environment.
- A frozen Git reference, [`archive/2019-initial-release`](https://github.com/fbreve/grid-image-contrast-ijcnn2009extended/tree/archive/2019-initial-release), points to commit [`fe8d54cffef4`](https://github.com/fbreve/grid-image-contrast-ijcnn2009extended/commit/fe8d54cffef4494ed3974840648ea4b9a4ca96e7) from **January 21, 2019**, before repository maintenance. This is the **earliest complete GitHub snapshot being preserved for maintenance purposes**, **not** an authenticated 2009 experimental snapshot.

## Project contents

| File or directory | Purpose |
| --- | --- |
| `RossGrid.cpp` | Windows/VCL application entry point |
| `rossler.cpp`, `rossler.h` | Rössler oscillator network, simulation and logging |
| `interface.cpp`, `interface.h`, `interface.dfm` | Main form, image handling and run controls |
| `logpixels.cpp`, `logpixels.h`, `logpixels.dfm` | Form to select pixels/oscillators for logging |
| `dynarray.cpp`, `dynarray.h` | Allocation and deallocation of dynamic arrays |
| `RossGrid.cbproj`, `RossGrid.cbproj.2007`, `RossGrid.bdsproj` | Historical C++Builder project configurations |
| `RossGrid.res`, `figura1.bmp` | Historical resource and example image files |
| `RossGrid.exe` | Pre-existing Windows executable; **not rebuilt or security-audited** |
| `plotar.txt` | Legacy MATLAB-style commands for inspecting output series |
| `serie.txt`, `serie2.txt`, `serie3.txt`, `serie4.txt` | Historically committed empty files; program writes time series with these names |
| `__history/` | IDE/editor source backups retained for historical preservation |
| `*.obj`, `*.pch`, `*.tds`, `*.map`, `RossGrid.#00` | Historical binary/build-related artifacts (the `#00` file's exact purpose has not been verified) |
| `grid-image-contrast-ijcnn2009extended.7z` | Historical compressed archive; contents have not been independently inspected |

See [HISTORICAL_FILES.md](HISTORICAL_FILES.md) for the complete archived inventory and the 2026 cleanup. The maintained `master` branch now excludes 54 editor-history backups and 10 generated compiler/local-configuration files, saving **28,012,737 bytes** from its current tree. All removed artifacts remain available through the historical branch; `RossGrid.exe`, the `.7z` archive and `RossGrid.#00` remain on `master`.

## Working with the historical project

A likely starting point for someone with a **compatible licensed C++Builder installation on Windows** is to open `RossGrid.cbproj` or `RossGrid.bdsproj` in its corresponding generation of the IDE.

These are **recovery suggestions, not tested build instructions**. The original project files include machine-specific relative search paths (for example, a directory under `Doutorado/Simulações/wc-win`); those paths may need local adjustment. Avoid modifying the archived branch to repair a local build.

The interface exposes oscillator/simulation settings (such as coupling force, time step, end time, salience and logging options), allows loading an image, and can save the image displayed by the application. Logged oscillator variables are written to the four `serie*.txt` files in the application's **working directory** when logging is enabled. The commands in `plotar.txt` are exploratory post-processing snippets, not an automated verification suite.

The historical `RossGrid.exe` has not been tested here. If you choose to run it, use a controlled Windows environment and inspect the executable and dependencies first. Its presence does **not** establish that its numerical behavior matches the article.

## Citation

Please cite the **extended journal article** when using the model or the accompanying historical implementation in research:

```bibtex
@article{breve2009chaotic,
  author  = {Breve, Fabricio Aparecido and Zhao, Liang and
             Quiles, Marcos Gon{\c{c}}alves and Macau, Elbert Einstein Nehrer},
  title   = {Chaotic Phase Synchronization and Desynchronization
             in an Oscillator Network for Object Selection},
  journal = {Neural Networks},
  volume  = {22},
  number  = {5--6},
  pages   = {728--737},
  year    = {2009},
  doi     = {10.1016/j.neunet.2009.06.027}
}
```

[CITATION.cff](CITATION.cff) provides GitHub citation metadata and identifies the **extended journal article** as the preferred scholarly citation.

## Reproducibility and maintenance policy

The `master` branch may receive **non-functional documentation and repository-hygiene changes**; scientific or GUI bug fixes should be isolated and tested against the historical implementation before integration. The historical branch should remain untouched.

The original publication predates the first GitHub upload by approximately **ten years**. For a genuine reconstruction of the published experiments, further evidence would be needed about the original source revision, IDE/compiler, dependencies, input images, run settings and numeric outputs.

Potential problems identified during source review are tracked in [KNOWN_ISSUES.md](KNOWN_ISSUES.md). They remain **unverified** and were not changed as part of this documentation update.

## Copyright and reuse

The **original RossGrid source code and repository-authored documentation** are distributed under the [Apache License, Version 2.0](LICENSE), with attribution and scope details in [NOTICE](NOTICE).

This license does **not** purport to grant rights to proprietary Borland/CodeGear C++Builder or VCL components, the journal article, or third-party material. The preserved `RossGrid.exe`, `RossGrid.#00`, `RossGrid.res`, `figura1.bmp` and uninspected `.7z` archive remain historical artifacts whose embedded third-party rights and redistribution permissions have not been independently verified.
