# 🎨 Raytracer

A sophisticated ray tracing engine written in C++ that generates realistic digital images by simulating the inverse path of light. This project implements a flexible, extensible architecture for rendering complex 3D scenes with support for various primitives, lighting models, and materials.

---

## 📚 Documentation

Navigate through our comprehensive documentation:

- **[🚀 USAGE.md](./docs/USAGE.md)** — How to run the raytracer and generate images
- **[🔧 INSTALLATION.md](./docs/INSTALLATION.md)** — Build and installation instructions
- **⭐ [FEATURES.md](./docs/FEATURES.md)** — Current features and roadmap
- **🏗️ [ARCHITECTURE.md](./docs/ARCHITECTURE.md)** — Design patterns and system overview
- **📝 [SCENE_FORMAT.md](./docs/SCENE_FORMAT.md)** — How to create scene configuration files
- **👨‍💻 [DEVELOPMENT.md](./docs/DEVELOPMENT.md)** — Guide for extending and contributing

---

## 🎯 Quick Start

```bash
# Build the project
make

# Run the raytracer
./raytracer <SCENE_FILE> [-f <OUTPUT_FILE_NAME>]

# Example
./raytracer config/config.rtx -f my_render
```

---

## ✨ Key Features

### Must-Have Features (Implemented)
- **Primitives**: Sphere, Plane, and more
- **Transformations**: Translation support
- **Lighting**: Directional light and ambient lighting
- **Materials**: Flat color rendering
- **Output**: PPM file format

### Should-Have Features
- **Primitives**: Cylinder, Cone
- **Transformations**: Rotation
- **Effects**: Drop shadows

### Could-Have Features
- Advanced primitives (Torus, Möbius strip, OBJ files)
- Complex transformations (Scale, Shear, Scene graphs)
- Advanced lighting (Phong reflection, Ambient occlusion)
- Material properties (Transparency, Refraction, Reflection)
- Anti-aliasing algorithms
- Multi-threading for performance

---

## 🏗️ Architecture Highlights

- **Interfaces First**: Extensible design with abstract base classes for Primitives and Lights
- **Design Patterns**: Factory, Observer, and more for clean, maintainable code
- **Plugin System**: Ready for dynamic library extensions
- **Scalable**: Built to handle complex scenes efficiently

---

## 📋 Requirements

- **C++ Compiler**: C++17 or later
- **Libraries**:
  - Standard C++ Library
  - libconfig++ (scene parsing)
  - SFML (optional, for display)

For detailed instructions, see [INSTALLATION.md](./docs/INSTALLATION.md).

---

## 📖 Project Structure

```
├── src/                    # Source code
│   ├── main.cpp           # Entry point
│   ├── Core/              # Rendering engine
│   ├── Parser/            # Scene configuration parser
│   ├── Factory/           # Factory pattern implementations
│   ├── Object/            # Scene objects (Primitives, Lights, Camera)
│   ├── Math/              # Mathematical utilities
│   └── ...
├── config/                # Example scene files
├── Makefile               # Build configuration
└── README.md              # This file
```

---

## 📄 License

This project is part of the Epitech curriculum.

---

## 🤝 Contributing

See [DEVELOPMENT.md](./docs/DEVELOPMENT.md) for guidelines on extending and contributing to this project.

---

**Ready to render?** Start with [USAGE.md](./docs/USAGE.md)!
