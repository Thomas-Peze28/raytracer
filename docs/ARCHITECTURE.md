# 🏗️ ARCHITECTURE.md

## System Architecture & Design Patterns

This document outlines the architectural principles and design patterns used in the raytracer.

---

## 🎯 Core Philosophy

The raytracer is built on the following principles:

1. **Extensibility** - Easy to add new primitives, lights, and materials
2. **Separation of Concerns** - Each component has a single, well-defined responsibility
3. **Type Safety** - Leveraging C++ type system for compile-time safety
4. **Observer Pattern** - Decoupled communication between components

---

## 🏢 High-Level Architecture

```
┌─────────────────────────────────────────────────────────┐
│                   main.cpp (Entry Point)                │
└────────────────────┬────────────────────────────────────┘
                     │
        ┌────────────┼────────────┐
        │            │            │
    ┌───▼──┐    ┌───▼──┐    ┌───▼──┐
    │Parser│    │Scene │    │Core  │
    └───┬──┘    └──────┘    └───┬──┘
        │                        │
        ├─ Loads .rtx files      ├─ Ray-Scene intersection
        ├─ Creates objects       ├─ Color computation
        └─ Configures scene      ├─ PPM output
                                 └─ Observer notification
```

---

## 🏗️ Design Patterns Used

### 1. **Factory Pattern** ✅

**Location**: `src/Factory/`

**Purpose**: Encapsulates object creation for extensibility

#### PrimitiveFactory
Creates primitive objects from configuration:
- Sphere
- Plane
- Cylinder
- Cone

```cpp
// Usage
IPrimitive* primitive = PrimitiveFactory::create(type, properties);
```

#### LightFactory
Creates light sources from configuration:
- DirectionalLight
- PointLight
- AmbientLight

```cpp
// Usage
ILight* light = LightFactory::create(type, properties);
```

**Benefits**:
- ✅ Centralized object creation
- ✅ Easy to add new types
- ✅ Decoupled from client code

---

### 2. **Observer Pattern** ✅

**Location**: `src/Observer/`

**Purpose**: Decouple progress updates from rendering logic

#### Interfaces
- `IProgressObservable` - Publisher interface
- `IProgressObserver` - Subscriber interface

#### Implementation
```cpp
// Core publishes progress
core.addObserver(&progressBar);
core.notifyObservers(currentProgress);

// ProgressBar receives updates
void ProgressBar::update(float progress) {
    // Display progress bar
}
```

**Benefits**:
- ✅ Decoupled rendering from UI
- ✅ Multiple observers supported
- ✅ Easy to add new observers (logging, etc.)

---

### 3. **Strategy Pattern** (Implicit)

**Location**: `src/Object/`

**Purpose**: Different rendering strategies for different primitives

- Each primitive implements `IPrimitive::intersect()`
- Core uses polymorphism to call appropriate method

```cpp
// Abstract method
virtual bool intersect(const Ray& ray, Intersection& result) = 0;

// Implemented by each primitive
// - Sphere::intersect()
// - Plane::intersect()
// - Cylinder::intersect()
```

**Benefits**:
- ✅ Algorithm selection at runtime
- ✅ Easy to swap implementations
- ✅ Testable independently

---

## 📁 Project Structure

### Core Modules

```
src/
├── main.cpp                 # Entry point
├── Core/
│   ├── Core.hpp/cpp        # Main rendering engine
│   └── Raytracer logic
├── Parser/
│   ├── Parser.hpp/cpp      # Scene file parsing
│   └── Configuration loading
├── Factory/
│   ├── PrimitiveFactory/   # Create primitives
│   └── LightFactory/       # Create lights
├── Object/
│   ├── Camera/             # Viewpoint & projection
│   ├── Light/              # Light sources
│   │   ├── ILight/         # Abstract interface
│   │   ├── DirectionalLight/
│   │   └── PointLight/
│   ├── Primitive/          # 3D shapes
│   │   ├── IPrimitive/     # Abstract interface
│   │   ├── Sphere/
│   │   ├── Plane/
│   │   ├── Cylinder/
│   │   └── Cone/
│   └── Ray/                # Ray representation
├── Math/
│   ├── Point3D/            # 3D point math
│   └── Vector3D/           # 3D vector math
├── Scene/
│   ├── Scene.hpp/cpp       # Scene container
│   └── Object management
├── ProgressBar/            # Progress display
├── Observer/               # Observer interfaces
└── Include/
    └── RTCError.hpp        # Exception handling
```

---

## 🔄 Rendering Pipeline

### Step 1: Scene Loading
```
main() 
  → Parser::loadScene()
    → Factory::createPrimitive()
    → Factory::createLight()
    → Scene population
```

### Step 2: Initialization
```
Scene
  → Configure Camera
  → Register Lights
  → Register Primitives
```

### Step 3: Ray Tracing
```
Core::run()
  → For each pixel:
    → Generate Ray
    → Find intersections
    → Compute color
    → Write to PPM
    → Notify observers
```

### Step 4: Output
```
Core::openOutputFile()
  → Create PPM file
  → Write header
  → Write pixel data
  → Close file
```

---

## 📦 Data Flow

```
┌─────────────────────┐
│   Scene File        │
│   (config.rtx)      │
└──────────┬──────────┘
           │
    ┌──────▼──────┐
    │  Parser     │
    └──────┬──────┘
           │
    ┌──────▼──────────────┐
    │  Scene Object       │
    │  - Primitives       │
    │  - Lights           │
    │  - Camera           │
    └──────┬──────────────┘
           │
    ┌──────▼──────────────┐
    │  Core               │
    │  - Ray Generation   │
    │  - Intersection     │
    │  - Shading          │
    └──────┬──────────────┘
           │
    ┌──────▼──────────────┐
    │  PPM Output         │
    │  - Pixel Data       │
    │  - Image File       │
    └─────────────────────┘
```

---

## 🔧 Key Interfaces

### IPrimitive
All geometry objects inherit from this:
```cpp
class IPrimitive {
public:
    virtual ~IPrimitive() = default;
    virtual bool intersect(const Ray& ray, Intersection& result) = 0;
    virtual Point3D getCenter() const = 0;
    virtual void translate(const Vector3D& v) = 0;
    virtual void rotate(const Vector3D& axis, float angle) = 0;
};
```

### ILight
All light sources inherit from this:
```cpp
class ILight {
public:
    virtual ~ILight() = default;
    virtual Vector3D getDirection(const Point3D& point) = 0;
    virtual float getIntensity(const Point3D& point) = 0;
    virtual Color getColor() = 0;
};
```

### IProgressObserver
Progress monitoring interface:
```cpp
class IProgressObserver {
public:
    virtual ~IProgressObserver() = default;
    virtual void update(float progress) = 0;
};
```

---

## 🎨 Rendering Algorithm

### Basic Ray Tracing

```
For each pixel (x, y):
  1. Generate ray from camera through pixel
  2. Find closest intersection point
  3. If no intersection:
     - Return background color
  4. If intersection found:
     - Calculate surface normal
     - For each light:
       - Calculate diffuse + ambient contribution
       - Check for shadows
     - Return accumulated color
  5. Write pixel to PPM
  6. Notify observers of progress
```

---

## 🚀 Extensibility Points

### Adding a New Primitive

1. Create class inheriting from `IPrimitive`
2. Implement `intersect()` method
3. Register in `PrimitiveFactory`
4. Add configuration support in `Parser`

### Adding a New Light

1. Create class inheriting from `ILight`
2. Implement light calculation methods
3. Register in `LightFactory`
4. Add configuration support in `Parser`

### Adding an Observer

1. Implement `IProgressObserver`
2. Override `update()` method
3. Register with `Core::addObserver()`

---

## 🛠️ Future Plugin System

While not currently implemented, the architecture supports plugins:

```cpp
// Pseudocode - Future plugin loading
DynamicLibrary lib("plugins/sphere.so");
IPrimitive* sphere = lib.create("Sphere");
```

**Directory**: `plugins/`
**Format**: `.so` files (shared objects)

---

## 📊 Class Diagram

```
┌─────────────────┐
│    IPrimitive   │ ◄─── Abstract Interface
└────┬────────────┘
     │
     ├─── Sphere
     ├─── Plane
     ├─── Cylinder
     └─── Cone

┌─────────────────┐
│     ILight      │ ◄─── Abstract Interface
└────┬────────────┘
     │
     ├─── DirectionalLight
     ├─── PointLight
     └─── AmbientLight

┌──────────────────────┐
│ IProgressObserver    │ ◄─── Abstract Interface
└────┬─────────────────┘
     │
     ├─── ProgressBar
     └─── CustomObserver
```

---

## ⚡ Performance Considerations

1. **Ray Acceleration** - Space partitioning (future)
2. **Caching** - Precomputed intersections
3. **Threading** - Parallel pixel processing (future)
4. **Optimization** - Early ray termination

---

## 📋 Design Pattern Checklist

Required patterns (at least 2 must be used):

- [x] **Factory Pattern** - Object creation
- [x] **Observer Pattern** - Progress updates
- [ ] Builder Pattern
- [ ] Composite Pattern
- [ ] Decorator Pattern
- [ ] State Pattern
- [ ] Mediator Pattern

---

## 🔗 Related Documentation

- [FEATURES.md](./FEATURES.md) - Planned enhancements
- [DEVELOPMENT.md](./DEVELOPMENT.md) - Contribution guidelines
- [SCENE_FORMAT.md](./SCENE_FORMAT.md) - Configuration format

---

## 💡 Best Practices

1. **Always use interfaces** for extensibility
2. **Avoid tight coupling** between modules
3. **Use Factory for creation** rather than `new` directly
4. **Notify observers** for long operations
5. **Handle exceptions** gracefully
6. **Document public APIs** clearly

For code style and conventions, see [DEVELOPMENT.md](./DEVELOPMENT.md).
