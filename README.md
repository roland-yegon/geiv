<div align="center">

# 🖼️ GEIV (Good Enough Image Viewer)

### *A window. Some pixels. Zero bloat.*

[![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?style=for-the-badge&logo=cplusplus)](https://isocpp.org/)
[![SFML](https://img.shields.io/badge/SFML-2.5-8CC445?style=for-the-badge&logo=sfml&logoColor=white)](https://www.sfml-dev.org/)
[![CMake](https://img.shields.io/badge/CMake-3.16%2B-064F8C?style=for-the-badge&logo=cmake&logoColor=white)](https://cmake.org/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey?style=for-the-badge)]()

*No Electron. No 400MB of node_modules. No "please install our proprietary SDK." Just C++ and a picture.*

</div>

---

## 📖 Table of Contents

- [Why This Exists](#-why-this-exists)
- [Features](#-features)
- [Demo](#-demo)
- [Installation](#-installation)
  - [Void Linux](#void-linux)
  - [Debian / Ubuntu](#debian--ubuntu)
  - [Arch Linux](#arch-linux)
  - [Windows](#windows)
  - [macOS](#macos)
- [Building From Source](#-building-from-source)
- [Usage](#-usage)
- [Controls](#-controls)
- [Supported Formats](#-supported-formats)
- [Project Structure](#-project-structure)
- [Roadmap](#-roadmap)
- [Contributing](#-contributing)
- [FAQ](#-faq)
- [License](#-license)

---

## 🤔 Why This Exists

Because every "simple" image viewer on your system either:
1. Comes bundled with a photo-editing suite you didn't ask for,
2. Takes four seconds to boot because it's actually a web browser in a trench coat
3. Doesn't exist on a minimal Linux install and you're stuck squinting at `chafa` output in a terminal like it's 1987.

This is ~90 lines of C++ and SFML that does exactly one job: show you an image, let you zoom and pan, and get out of the way.

## ✨ Features

| Feature | Status |
|---|---|
| Load image from CLI argument | ✅ |
| Zoom with scroll wheel | ✅ |
| Pan by click-and-drag | ✅ |
| Resizable window | ✅ |
| Reset view (`R` key) | ✅ |
| Free and open source | ✅ |
| Bloat | ❌ |

## 🎬 Demo

```
./geiv ~/Pictures/cat_being_a_menace.png
```

## 📦 Installation

You need SFML before anything else works. Pick your poison:

### Void Linux

```
sudo xbps-install -S SFML SFML-devel
```

### Debian / Ubuntu

```
sudo apt install libsfml-dev
```

### Arch Linux

```
sudo pacman -S sfml
```

### Windows

Grab the precompiled binaries from the [official SFML downloads page](https://www.sfml-dev.org/download.php), matching your compiler (MinGW or Visual Studio version), and point CMake at the extracted folder via `SFML_DIR`.

### macOS

```
brew install sfml
```

## 🔨 Building From Source

Clone it, enter it, build it — the holy trinity:

```
git clone https://github.com/roland-yegon/geiv.git
```

```
cd geiv
```

```
mkdir build && cd build
```

```
cmake ..
```

```
make
```

A binary named `geiv` appears in `build/`. Congratulations, you compiled something.

## 🚀 Usage

```
./geiv /path/to/image.png
```

That's the whole API surface. No flags, no config file, no YAML to argue with.

## 🎮 Controls

| Input | Action |
|---|---|
| 🖱️ Scroll wheel | Zoom in / out |
| 🖱️ Left-click + drag | Pan around |
| ⌨️ `R` | Reset to default view |
| ⌨️ `Esc` | Quit |

## 🗂️ Supported Formats

Whatever `sf::Texture::loadFromFile` supports under the hood:

`PNG` · `JPG / JPEG` · `BMP` · `TGA` · `GIF` (first frame only) · `PSD` · `HDR` · `PIC`

## 🏗️ Project Structure

```
image_viewer/
├── main.cpp          # The whole program. Yes, really.
├── CMakeLists.txt     # Build config
├── .gitignore
├── README.md          # You are here
└── build/              # Generated, gitignored, not your problem
```

## 🗺️ Roadmap

- [ ] Multi-image / directory browsing (next / previous image)
- [ ] Slideshow mode
- [ ] Basic EXIF info overlay
- [ ] Drag-and-drop file loading
- [ ] Fit-to-window toggle

Pull requests that knock these out will be received with genuine enthusiasm.

## 🤝 Contributing

1. Fork it
2. Branch it: `git checkout -b feature/something-cool`
3. Commit it: `git commit -m "Add something cool"`
4. Push it: `git push origin feature/something-cool`
5. Open a Pull Request and wait for the confetti

## ❓ FAQ

**Q: Why SFML and not Qt/GLFW/raw X11?**
A: SFML gives you a window and image loading in about 10 lines, with none of the ceremony. Life's too short.

**Q: Does it support animated GIFs?**
A: It reads the first frame only. If you want a GIF player, this isn't it — yet (see Roadmap).

**Q: Can I use this in my own project?**
A: Yes. See License below.

## 📄 License

MIT. Do whatever you want with it — just don't blame me if you build Photoshop 2 out of it and it goes horribly wrong.

---

<div align="center">

Built with C++, SFML, and a mild grudge against bloated software.

</div>
