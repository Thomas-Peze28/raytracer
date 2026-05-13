# 🔧 INSTALLATION.md

## Build and Installation Guide

This document covers building the raytracer from source.

---

## Prerequisites

### System Requirements
- **OS**: Linux, macOS, or Unix-like system
- **Compiler**: GCC 7+ or Clang (C++17 or later)
- **Build Tool**: Make

### Dependencies

#### Required
- **libconfig++**: Configuration file parsing library
  ```bash
  # Ubuntu/Debian
  sudo apt-get install libconfig++-dev
  
  # macOS (Homebrew)
  brew install libconfig
  
  # Fedora
  sudo dnf install libconfig-devel
  ```

#### Optional
- **SFML**: For display features (future enhancement)
  ```bash
  # Ubuntu/Debian
  sudo apt-get install libsfml-dev
  
  # macOS (Homebrew)
  brew install sfml
  ```

---

## Building

### Quick Build

```bash
# Navigate to project root
cd /path/to/raytracer

# Build the project
make

# The executable will be created at the root: ./raytracer
```

### Clean Build

If you want to rebuild from scratch:

```bash
# Remove all build artifacts
make clean

# Rebuild everything
make
```

### Build Targets

```bash
# Default: builds the raytracer executable
make

# Clean build artifacts
make clean

# View available targets
make help
```

---

## Verification

After building, verify the installation:

```bash
# Check if executable exists
ls -la ./raytracer

# Test with example scene
./raytracer config/config.rtx -f test_output

# Check output
ls -la test_output.ppm
```

---

## Troubleshooting Build Issues

### Compiler Errors

**Error**: `fatal error: libconfig.h++: No such file or directory`
- **Solution**: Install libconfig++
  ```bash
  # Ubuntu/Debian
  sudo apt-get install libconfig++-dev libconfig++-doc
  ```

**Error**: `undefined reference to libconfig::...`
- **Solution**: The library is not linked; check `Makefile` compiler flags

### Missing C++ Features

**Error**: `error: 'optional' is not a member of 'std'`
- **Solution**: Ensure C++17 is enabled in Makefile
  ```makefile
  CXXFLAGS = -std=c++17 -Wall -Wextra
  ```

### Dependency Issues

If you encounter missing dependencies after installation:

```bash
# Reconfigure your environment
hash -r

# Rebuild from scratch
make clean && make
```

---

## Platform-Specific Instructions

### Ubuntu/Debian

```bash
# Install dependencies
sudo apt-get update
sudo apt-get install build-essential libconfig++-dev

# Build
make

# Run
./raytracer config/config.rtx
```

### macOS (with Homebrew)

```bash
# Install dependencies
brew install gcc libconfig

# Build (may need to specify compiler)
CC=gcc-11 CXX=g++-11 make

# Run
./raytracer config/config.rtx
```

### Fedora/RHEL

```bash
# Install dependencies
sudo dnf install gcc-c++ libconfig-devel

# Build
make

# Run
./raytracer config/config.rtx
```

---

## Development Setup

For developers wanting to contribute:

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd raytracer
   ```

2. **Set up development environment**
   ```bash
   # Install development tools
   sudo apt-get install build-essential gdb valgrind clang-format
   ```

3. **Build with debug symbols**
   ```bash
   make clean
   make DEBUG=1
   ```

4. **Debug with GDB**
   ```bash
   gdb ./raytracer
   (gdb) run config/config.rtx
   ```

---

## Project Structure After Build

After a successful build:

```
raytracer/
├── raytracer              # ✅ Executable
├── src/                   # Source files
├── config/                # Example scenes
├── docs/                  # Documentation
└── Makefile               # Build configuration
```

---

## Uninstallation

To remove build artifacts:

```bash
make clean
```

To remove the executable:

```bash
rm ./raytracer
```

---

## Next Steps

- See [USAGE.md](./USAGE.md) to run your first render
- Check [SCENE_FORMAT.md](./SCENE_FORMAT.md) to create scenes
- Visit [ARCHITECTURE.md](./ARCHITECTURE.md) to understand the design

For help, see [DEVELOPMENT.md](./DEVELOPMENT.md).
