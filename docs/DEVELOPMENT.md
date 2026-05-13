# 👨‍💻 DEVELOPMENT.md

## Developer Guide

This document provides guidelines for developers contributing to the raytracer project.

---

## 🎯 Getting Started as a Developer

### Prerequisites

- Familiarity with C++17 and OOP principles
- Understanding of ray tracing basics
- Git knowledge for version control
- Understanding of design patterns (Factory, Observer, Strategy)

### Setup Development Environment

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd raytracer
   ```

2. **Install dependencies**
   ```bash
   # Ubuntu/Debian
   sudo apt-get install build-essential libconfig++-dev gdb valgrind clang-format
   ```

3. **Build with debug symbols**
   ```bash
   make clean
   DEBUG=1 make
   ```

4. **Run tests**
   ```bash
   ./raytracer config/config.rtx -f test_output
   ```

---

## 📁 Project Structure Reference

```
src/
├── main.cpp                      # Entry point
├── Core/Core.{hpp,cpp}          # Rendering engine
├── Parser/Parser.{hpp,cpp}      # Config file parsing
├── Factory/
│   ├── PrimitiveFactory/        # Creates primitives
│   └── LightFactory/            # Creates lights
├── Object/
│   ├── Camera/                  # Viewpoint
│   ├── Light/
│   │   ├── ILight/             # Light interface ⭐
│   │   ├── DirectionalLight/
│   │   ├── PointLight/
│   │   └── AmbientLight/
│   ├── Primitive/
│   │   ├── IPrimitive/         # Primitive interface ⭐
│   │   ├── Sphere/
│   │   ├── Plane/
│   │   ├── Cylinder/
│   │   ├── Cone/
│   │   └── Rectangle3D/
│   └── Ray/
├── Math/
│   ├── Point3D/                 # Point utilities
│   └── Vector3D/                # Vector utilities
├── Scene/Scene.{hpp,cpp}       # Scene container
├── Observer/                    # Observer pattern interfaces
├── ProgressBar/                 # Progress display
└── Include/RTCError.hpp        # Exception handling
```

⭐ = Key extension points

---

## 🚀 Adding a New Primitive

### Step 1: Create Header File

Create `src/Object/Primitive/YourPrimitive/YourPrimitive.hpp`:

```cpp
#pragma once

#include "../../Primitive/IPrimitive/IPrimitive.hpp"
#include "../../../Math/Point3D/Point3D.hpp"
#include "../../../Math/Vector3D/Vector3D.hpp"

namespace Raytracer {
    class YourPrimitive : public IPrimitive {
    public:
        YourPrimitive(const Point3D& position, float param1, const Color& color);
        ~YourPrimitive() = default;

        bool intersect(const Ray& ray, Intersection& intersection) const override;
        Point3D getCenter() const override;
        void translate(const Vector3D& translation) override;
        void rotate(const Vector3D& axis, float angle) override;

    private:
        Point3D _position;
        float _param1;  // Your parameter
        Color _color;
    };
}
```

### Step 2: Implement Source File

Create `src/Object/Primitive/YourPrimitive/YourPrimitive.cpp`:

```cpp
#include "YourPrimitive.hpp"
#include <cmath>

namespace Raytracer {
    YourPrimitive::YourPrimitive(const Point3D& position, float param1, const Color& color)
        : _position(position), _param1(param1), _color(color)
    {
    }

    bool YourPrimitive::intersect(const Ray& ray, Intersection& intersection) const
    {
        // Implement ray-primitive intersection algorithm
        // Return true if intersection found, false otherwise
        // Fill in intersection structure with hit details
        
        // Pseudocode:
        // 1. Calculate ray parameter t
        // 2. Check if intersection is valid (t > 0)
        // 3. Calculate intersection point and normal
        // 4. Fill Intersection structure
        
        return false;  // Placeholder
    }

    Point3D YourPrimitive::getCenter() const
    {
        return _position;
    }

    void YourPrimitive::translate(const Vector3D& translation)
    {
        _position = _position + translation;
    }

    void YourPrimitive::rotate(const Vector3D& axis, float angle)
    {
        // Implement rotation around axis
        // Use Rodrigues' rotation formula or similar
    }
}
```

### Step 3: Register in Factory

Edit `src/Factory/PrimitiveFactory/PrimitiveFactory.cpp`:

```cpp
#include "../../Object/Primitive/YourPrimitive/YourPrimitive.hpp"

IPrimitive* PrimitiveFactory::create(const std::string& type, const libconfig::Setting& setting)
{
    if (type == "yourprimitive") {
        Point3D position(
            setting.lookup("position.x"),
            setting.lookup("position.y"),
            setting.lookup("position.z")
        );
        float param1 = setting.lookup("param1");
        Color color(
            setting.lookup("color.r"),
            setting.lookup("color.g"),
            setting.lookup("color.b")
        );
        return new YourPrimitive(position, param1, color);
    }
    // ... other types
}
```

### Step 4: Update Parser

Edit `src/Parser/Parser.cpp` to handle your primitive in scene files.

### Step 5: Add Tests

Create test scenes in `config/` to test your implementation.

---

## 💡 Adding a New Light

### Similar Process

1. Create `src/Object/Light/YourLight/YourLight.hpp`
2. Implement `src/Object/Light/YourLight/YourLight.cpp`
3. Register in `src/Factory/LightFactory/LightFactory.cpp`
4. Update `src/Parser/Parser.cpp`
5. Add test scenes

### Example Interface Implementation

```cpp
#include "../../Light/ILight/ILight.hpp"

namespace Raytracer {
    class YourLight : public ILight {
    public:
        YourLight(const Point3D& position);
        
        Vector3D getDirection(const Point3D& point) const override;
        float getIntensity(const Point3D& point) const override;
        Color getColor() const override;
    
    private:
        Point3D _position;
        // ... your properties
    };
}
```

---

## 🧪 Code Style & Standards

### Naming Conventions

```cpp
// Classes: PascalCase
class MyPrimitive { };

// Functions: camelCase
void myFunction() { }

// Member variables: _snake_case
float _member_variable;

// Constants: UPPER_SNAKE_CASE
const float PI_VALUE = 3.14159f;

// Namespaces: snake_case (Raytracer convention)
namespace Raytracer { }
```

### File Organization

```cpp
// Header guards
#pragma once

// Includes (order matters)
#include <standard_library>
#include <libconfig++>
#include "local_header.hpp"

// Namespace
namespace Raytracer {
    // Forward declarations
    class Other;

    // Class definition
    class MyClass {
    public:
        // Public interface
        MyClass();
        ~MyClass();
        
    private:
        // Private members
        float _value;
    };
}
```

### Code Quality

- **Comments**: Use `//` for implementation comments
- **Documentation**: Use `/** ... */` for public APIs
- **Formatting**: Run `clang-format` on all changes
- **Testing**: Verify with example scenes

---

## 🔄 Build System

### Makefile Targets

```bash
make              # Build raytracer
make clean        # Remove build artifacts
make DEBUG=1      # Build with debug symbols
make help         # Show available targets
```

### Custom Build Flags

```bash
# Enable optimization
CXXFLAGS="-O3" make

# Enable warnings
CXXFLAGS="-Wall -Wextra -Werror" make
```

---

## 🐛 Debugging

### Using GDB

```bash
# Build with debug symbols
DEBUG=1 make

# Run under debugger
gdb ./raytracer

(gdb) run config/config.rtx
(gdb) bt                    # Backtrace
(gdb) print variable        # Print value
(gdb) break main.cpp:50    # Set breakpoint
(gdb) continue             # Continue execution
```

### Using Valgrind (Memory Leaks)

```bash
# Check for memory leaks
valgrind --leak-check=full ./raytracer config/config.rtx

# Detailed output
valgrind --leak-check=full --show-leak-kinds=all ./raytracer config/config.rtx
```

### Logging

Add debug output:

```cpp
#ifdef DEBUG
    std::cerr << "Debug: " << variable << std::endl;
#endif
```

---

## 📊 Performance Profiling

### Using Linux perf

```bash
# Record profile
perf record ./raytracer config/config.rtx

# View results
perf report
```

### Timing Measurements

```cpp
#include <chrono>

auto start = std::chrono::high_resolution_clock::now();
// ... code to measure
auto end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
std::cout << "Time: " << duration.count() << "ms" << std::endl;
```

---

## 🧬 Design Patterns Usage

### Factory Pattern (Used ✅)

When to use:
- Creating primitives from configuration
- Creating lights from configuration
- Object creation that varies by type

Example:
```cpp
IPrimitive* primitive = PrimitiveFactory::create("sphere", config);
```

### Observer Pattern (Used ✅)

When to use:
- Notifying about progress updates
- Decoupling rendering from UI
- Multiple listeners to same event

Example:
```cpp
core.addObserver(&progressBar);
core.notifyObservers(progress);
```

### Strategy Pattern (Implicit ✅)

When to use:
- Different algorithms per primitive type
- Runtime algorithm selection via polymorphism

Example:
```cpp
IPrimitive* obj = ...;
obj->intersect(ray, intersection);  // Calls Sphere or Plane version
```

### Factory + Builder Pattern

For future complex object construction:

```cpp
SceneBuilder builder;
builder.addPrimitive(...).addLight(...).build();
```

---

## 🔗 Adding an Observer

Extend the progress monitoring system:

### Create Observer Class

```cpp
class MyObserver : public IProgressObserver {
public:
    void update(float progress) override {
        // Handle progress update
        std::cout << "Progress: " << progress * 100 << "%" << std::endl;
    }
};
```

### Register with Core

```cpp
MyObserver observer;
core.addObserver(&observer);
core.run(scene);
```

---

## 📝 Documentation Standards

### Header Comments

```cpp
/**
 * @brief Brief description of function
 * @param param1 Description of parameter
 * @param param2 Description of parameter
 * @return Description of return value
 */
```

### Implementation Comments

```cpp
// Explain the WHY, not the WHAT
// Bad: "increment i"
i++;

// Good: "skip empty cells"
i++;
```

---

## 🧪 Testing New Features

### Create Test Scene

Create `config/test_yourfeature.rtx`:

```conf
camera: {
    resolution: { width: 800; height: 600; };
    position: { x: 0.0; y: 0.0; z: -20.0; };
};

ambient: {
    color: { r: 1.0; g: 1.0; b: 1.0; };
    intensity: 0.3;
};

lights: ( /* ... */ );

primitives: (
    // Your primitive to test
);
```

### Run and Validate

```bash
./raytracer config/test_yourfeature.rtx -f test_output
# Examine test_output.ppm with image viewer
```

---

## 🚀 Optimization Tips

1. **Cache computations**: Pre-calculate values used multiple times
2. **Minimize allocations**: Reuse buffers where possible
3. **Early exit**: Return as soon as you know the answer
4. **Vectorization**: Use SIMD where appropriate

---

## 🔐 Error Handling

### Using Exceptions

```cpp
// Define in Include/RTCError.hpp
class RTCError : public std::exception { };

// Usage
throw RTCError("Invalid scene configuration");
```

### Try-Catch

```cpp
try {
    parser.loadScene(filename, scene);
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 84;
}
```

---

## 📋 Checklist for New Features

Before submitting:

- [ ] Code compiles without warnings
- [ ] Follows naming conventions
- [ ] Includes documentation comments
- [ ] Tested with multiple scenes
- [ ] No memory leaks (valgrind clean)
- [ ] Design patterns properly used
- [ ] Backward compatible
- [ ] Performance acceptable

---

## 🤝 Contributing Workflow

1. **Create feature branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

2. **Make changes**
   - Follow code standards
   - Add tests
   - Update documentation

3. **Format code**
   ```bash
   clang-format -i src/**/*.cpp src/**/*.hpp
   ```

4. **Test thoroughly**
   ```bash
   make clean && make DEBUG=1
   ./raytracer config/config.rtx -f test
   valgrind ./raytracer config/config.rtx
   ```

5. **Commit with message**
   ```bash
   git commit -m "feat: add your feature description"
   ```

6. **Push and create pull request**
   ```bash
   git push origin feature/your-feature-name
   ```

---

## 📚 Mathematical References

### Ray-Sphere Intersection

```
Ray: P(t) = O + t*D
Sphere: |X - C|² = R²

Solution: (O - C + t*D)² = R²
```

### Ray-Plane Intersection

```
Plane: (X - P) · N = 0
Ray: X = O + t*D

Solution: t = ((P - O) · N) / (D · N)
```

### Normal Computation

```cpp
// For implicit surface f(x,y,z) = 0
Vector3D normal = gradient(f);
normal = normal.normalize();
```

---

## 🔗 Related Documentation

- [ARCHITECTURE.md](./ARCHITECTURE.md) - System design
- [SCENE_FORMAT.md](./SCENE_FORMAT.md) - Config format
- [FEATURES.md](./FEATURES.md) - Planned features

---

## 💬 Questions & Support

For questions:
1. Check existing documentation
2. Review similar implementations in codebase
3. Consult ray tracing references
4. Ask the pedagogical team

Happy coding! 🚀
