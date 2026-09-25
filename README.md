# C++ Image Viewer

A minimal SFML-based image viewer. Zoom, pan, resize — the essentials, no bloat.

## 1. Install SFML

**Void Linux:**
```
sudo xbps-install -S SFML SFML-devel
```

**Debian/Ubuntu:**
```
sudo apt install libsfml-dev
```

**Arch (or Arch-based):**
```
sudo pacman -S sfml
```

## 2. Build

```
mkdir build && cd build
```

```
cmake ..
```

```
make
```

## 3. Run

```
./image_viewer /path/to/your/image.png
```

## Controls

- **Scroll wheel** — zoom in/out
- **Left-click + drag** — pan
- **R** — reset view
- **Esc** — quit

Supports whatever formats SFML's `sf::Texture::loadFromFile` supports: PNG, JPG, BMP, GIF (first frame), TGA, PSD, and a few others.
