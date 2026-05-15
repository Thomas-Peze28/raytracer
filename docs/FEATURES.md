# ⭐ FEATURES.md

## Feature Overview

This document outlines all implemented, planned, and possible features for the raytracer.

---

## 🎯 Mandatory Features (MUST)

These features are required for the project to meet core specifications.

### ✅ Primitives
- [x] **Sphere** - Basic spherical geometry
- [x] **Plane** - Infinite plane surfaces

### ✅ Transformations
- [x] **Translation** - Move objects in 3D space
- [x] **Scale** - Resize objects along axes

### ✅ Lighting
- [x] **Directional Light** - Parallel light rays (like sunlight)
- [x] **Ambient Light** - Global illumination background

### ✅ Materials
- [x] **Flat Color** - Solid color rendering without shading

### ✅ Scene Configuration
- [x] **Add Primitives** - Populate scenes with objects
- [x] **Set Up Lighting** - Configure light sources
- [x] **Set Up Camera** - Define viewpoint and resolution

### ✅ Interface
- [x] **PPM Output** - Render scenes to Portable PixMap files
- [x] **Command Line** - Control via terminal arguments
- [x] **Progress Bar** - Visual feedback during rendering

---

## 📈 Should-Have Features

Once core features are working, these enhance the raytracer.

### 🔄 Primitives
- [x] **Cylinder** - Cylindrical geometry
- [x] **Cone** - Conical geometry
- [ ] **Limited Cylinder** - Cylinder with height bounds (0.5 pts)
- [ ] **Limited Cone** - Cone with height bounds (0.5 pts)

### 🔄 Transformations
- [x] **Rotation** - Rotate objects around axes
- [ ] **Shear** - Skew transformations (0.5 pts)

### 🔄 Lighting
- [ ] **Drop Shadows** - Realistic shadow casting

### 🔄 Materials & Effects
- [ ] **Colored Lights** - RGB light sources (0.5 pts)
- [ ] **Multiple Directional Lights** - Multiple sun-like sources (0.5 pts)
- [ ] **Multiple Point Lights** - Multiple point light sources (0.5 pts)

---

## 🚀 Could-Have Features (Bonus)

Advanced features for enhanced realism and performance.

### 🎨 Advanced Primitives
| Feature | Points | Status |
|---------|--------|--------|
| Torus | 1 | ❌ Not Started |
| Tanglecube | 1 | ❌ Not Started |
| Triangles | 1 | ❌ Not Started |
| OBJ File Import | 1 | ❌ Not Started |
| Fractals | 2 | ❌ Not Started |
| Möbius Strip | 2 | ❌ Not Started |

### 🔀 Advanced Transformations
| Feature | Points | Status |
|---------|--------|--------|
| Scale | 0.5 | ✅ Implemented |
| Shear | 0.5 | ❌ Not Started |
| Transformation Matrix | 2 | ❌ Not Started |
| Scene Graph | 2 | ❌ Not Started |

### 💡 Advanced Lighting
| Feature | Points | Status |
|---------|--------|--------|
| Multiple Directional Lights | 0.5 | ❌ Not Started |
| Multiple Point Lights | 0.5 | ❌ Not Started |
| Colored Light | 0.5 | ❌ Not Started |
| Phong Reflection Model | 2 | ❌ Not Started |
| Ambient Occlusion | 2 | ❌ Not Started |

### 🎭 Advanced Materials
| Feature | Points | Status |
|---------|--------|--------|
| Transparency | 0.5 | ❌ Not Started |
| Refraction | 1 | ❌ Not Started |
| Reflection | 0.5 | ❌ Not Started |
| Texturing (File) | 1 | ❌ Not Started |
| Texturing (Chessboard) | 1 | ❌ Not Started |
| Texturing (Perlin Noise) | 1 | ❌ Not Started |
| Normal Mapping | 2 | ❌ Not Started |

### ⚙️ Advanced Scene Configuration
| Feature | Points | Status |
|---------|--------|--------|
| Scene Nesting | 2 | ❌ Not Started |
| Supersampling AA | 0.5 | ❌ Not Started |
| Adaptive Supersampling | 1 | ❌ Not Started |

### 🚄 Optimizations
| Feature | Points | Status |
|---------|--------|--------|
| Space Partitioning | 2 | ❌ Not Started |
| Multi-threading | 1 | ❌ Not Started |
| Clustering (Network Rendering) | 3 | ❌ Not Started |

### 🖥️ Advanced Interface
| Feature | Points | Status |
|---------|--------|--------|
| Live Display | 1 | ❌ Not Started |
| Exit During Generation | 0.5 | ❌ Not Started |
| Scene Preview | 2 | ❌ Not Started |
| Auto Reload on File Change | 1 | ❌ Not Started |

---

## 🏗️ Architecture Features

### Design Patterns Implemented
- [x] **Factory Pattern** - Object creation for primitives and lights
- [x] **Observer Pattern** - Progress monitoring system
- [ ] **Builder Pattern** - Complex object construction
- [ ] **Composite Pattern** - Hierarchical scene structures
- [ ] **Decorator Pattern** - Dynamic feature addition
- [ ] **State Pattern** - Rendering states
- [ ] **Mediator Pattern** - Component coordination

### Extensibility
- [x] **Interface-Based Design** - Abstract base classes for Primitives and Lights
- [ ] **Plugin System** - Dynamic library loading
- [ ] **Configuration Parser** - libconfig++ integration

---

## 📊 Implementation Status

| Category | Mandatory | Should | Could | Total |
|----------|-----------|--------|-------|-------|
| Primitives | 2/2 | 2/4 | 6 | ✅ Core Complete |
| Transforms | 1/1 | 1/3 | 4 | ✅ Core Complete |
| Lighting | 2/2 | 0/3 | 5 | ✅ Core Complete |
| Materials | 1/1 | 0 | 7 | ✅ Core Complete |
| Interface | 3/3 | 0 | 4 | ✅ Core Complete |
| **TOTAL** | **9/9** | **3/13** | **26** | **32/48** |

---

## 🎯 Development Roadmap

### Phase 1: Core (Complete)
- Basic rendering pipeline
- Sphere and Plane primitives
- Directional and Ambient lighting
- PPM output

### Phase 2: Enhancement (In Progress)
- [ ] Cylinder and Cone primitives
- [ ] Rotation transformation
- [ ] Drop shadows

### Phase 3: Advanced (Planned)
- [ ] Material system improvements
- [ ] Advanced transformations
- [ ] Performance optimizations

### Phase 4: Bonus (Optional)
- [ ] Advanced primitives and effects
- [ ] Multi-threading
- [ ] Real-time preview

---

## 💡 How to Request a Feature

To add new features or request functionality:

1. Check this document to see if it's already planned
2. Review [DEVELOPMENT.md](./DEVELOPMENT.md) for implementation guidelines
3. Follow the architecture patterns described in [ARCHITECTURE.md](./ARCHITECTURE.md)
4. Submit changes with clear documentation

---

## 📝 Notes

- Feature points are based on project grading scale
- Bonus features can be implemented beyond the listed items
- Priority is always given to core functionality and code quality
- All features should maintain backward compatibility with existing scenes

For implementation details, see [DEVELOPMENT.md](./DEVELOPMENT.md).
