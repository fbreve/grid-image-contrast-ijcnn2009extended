# Historical project files and preservation policy

This document records the purpose of legacy files as far as it can be established from the Git tree and the original source. It is an **inventory**, not evidence of a successful modern build or of a byte-identical reproduction of the 2009 publication.

## Frozen historical reference

- **Branch:** [`archive/2019-initial-release`](https://github.com/fbreve/grid-image-contrast-ijcnn2009extended/tree/archive/2019-initial-release)
- **Commit:** [`fe8d54cffef4494ed3974840648ea4b9a4ca96e7`](https://github.com/fbreve/grid-image-contrast-ijcnn2009extended/commit/fe8d54cffef4494ed3974840648ea4b9a4ca96e7)
- **Date:** January 21, 2019 (last historical GitHub upload)
- **Publication history:** first presented at **IJCNN 2009**, then selected for an **extended version in *Neural Networks* (2009)**. This repository represents the **journal version**. **Do not infer that the 2019 Git snapshot is byte-identical to the publication-era source.**

The original GitHub snapshot contains **90 files totaling 37,124,690 bytes** in the Git tree. Source code, GUI form definitions, historical project metadata, binary artifacts, an executable and an archive are all preserved **in the archive branch**.

## Maintained `master` cleanup — November 18, 2026

[Commit `bba12cba9f7a`](https://github.com/fbreve/grid-image-contrast-ijcnn2009extended/commit/bba12cba9f7a9c19fe4d7dbfb024c51ad72960ad) removed **64 tracked generated/temporary files** from `master`:

- All **54** `__history/` editor backups
- **10** local-configuration and build files: `RossGrid.bdsproj.local`, `RossGrid.cbproj.local`, `RossGrid.map`, `RossGrid.obj`, `RossGrid.pch`, `RossGrid.tds`, `dynarray.obj`, `interface.obj`, `logpixels.obj`, `rossler.obj`

Total removed from the current Git tree: **28,012,737 bytes**, reducing the tree from **94 files / 37,142,093 bytes** (immediately before cleanup) to **30 files / 9,129,356 bytes** (immediately after). Later documentation and license files add a small amount of text.

**No original source, form, project definition, executable or other historical binary was edited by the cleanup.** All 64 removed objects remain available in the historical archive branch and Git history. This does not automatically shrink a full clone's historical object database.

The binary `RossGrid.#00` remains because its function is not verified. The `.7z` archive remains because its contents have not been independently inspected or verified as redundant.

## File groups

| Group | Files | Handling |
| --- | --- | --- |
| C++ / GUI source | `RossGrid.cpp`, `rossler.*`, `interface.*`, `logpixels.*`, `dynarray.*` | Preserve original contents; changes to code should be separate from documentation |
| VCL form resources | `interface.dfm`, `logpixels.dfm` | Required for the original visual interface; preserve |
| IDE project files | `RossGrid.bdsproj`, `RossGrid.cbproj`, `RossGrid.cbproj.2007`, `RossGrid.res` | Preserve for potential restoration in compatible C++Builder releases |
| Historical executable | `RossGrid.exe` (1,008,640 bytes) | Retain as artifact; no security, execution or scientific-equivalence validation has been performed |
| Historical archive | `grid-image-contrast-ijcnn2009extended.7z` (4,404,237 bytes) | Retain; archive contents have not been independently verified |
| Compiler/debug outputs | `RossGrid.pch` (15,467,038 bytes), `RossGrid.tds` (11,796,480 bytes), `*.obj`, `*.map` | **Archived only:** removed from `master`, preserved in `archive/2019-initial-release` |
| Other legacy artifacts | `RossGrid.#00` (3,588,629 bytes), `*.local` | Unknown `#00` remains on `master`; local config copies preserved in archive |
| Editor history | `__history/` (54 files) | Removed from `master`; fully preserved in historical archive |
| Input image | `figura1.bmp` | Preserve; it is a small bundled image, not a complete reproduction dataset |
| Logged series | `serie.txt` through `serie4.txt` (historically empty), `plotar.txt` | Preserve; the application can generate time-series files during logging |

### Project portability

Project files contain old **Borland/CodeGear C++Builder** settings, VCL dependencies and machine-specific relative directories, including `Doutorado/Simulações/wc-win`. None has been migrated to a current build system.

A modern compiler cannot be assumed to understand the historical VCL headers or GUI descriptors. Build and run experiments, if attempted, should record the precise IDE version, Windows environment, dependencies, source commit, input image, settings and program output.

### Why the historical binaries remain recoverable

The 2019 archive branch preserves the original `RossGrid.pch`, `RossGrid.tds`, `*.obj`, `*.map`, `*.local`, and editor-history backups for historical debugging. These artifacts are no longer tracked in the maintained `master` tree. New build outputs are excluded by `.gitignore`.

The original executable and unverified `.7z` archive remain on both branches. The cleanup was a source-tree maintenance operation, **not** a history rewrite or recreation of the 2009 scientific environment.

### Technical observations

The historical source contains some candidate issues (memory management, image bounds and header guards). These observations are recorded in [KNOWN_ISSUES.md](KNOWN_ISSUES.md). **None was modified or experimentally confirmed** as part of documentation maintenance.
