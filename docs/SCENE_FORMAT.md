# 📝 SCENE_FORMAT.md

## Scene Configuration File Format

Scene files define the objects, lights, and camera for rendering. The raytracer uses **libconfig++** configuration files (typically with `.rtx` extension).

---

## File Format Overview

The scene file uses a hierarchical configuration structure with the following main sections:

```
camera { ... }
ambient { ... }
lights [ ... ]
primitives [ ... ]
```

---

## 📷 Camera Configuration

Defines the viewpoint and output resolution.

```conf
camera: {
    resolution: {
        width: 1920;
        height: 1080;
    };
    position: {
        x: 0.0;
        y: 0.0;
        z: -50.0;
    };
    rotation: {
        x: 0.0;
        y: 0.0;
        z: 0.0;
    };
    fov: 60.0;
};
```

### Camera Parameters

| Parameter | Type | Description | Default |
|-----------|------|-------------|---------|
| `resolution.width` | Integer | Image width in pixels | Required |
| `resolution.height` | Integer | Image height in pixels | Required |
| `position.x/y/z` | Float | Camera position in world space | 0.0 |
| `rotation.x/y/z` | Float | Rotation angles (degrees) | 0.0 |
| `fov` | Float | Field of view (degrees) | 60.0 |

**Example**:
```conf
camera: {
    resolution: { width: 1920; height: 1080; };
    position: { x: 10.0; y: 5.0; z: -30.0; };
    fov: 45.0;
};
```

---

## 💡 Ambient Light

Global illumination (background light) affecting all objects.

```conf
ambient: {
    color: {
        r: 1.0;
        g: 1.0;
        b: 1.0;
    };
    intensity: 0.3;
};
```

### Ambient Parameters

| Parameter | Type | Range | Description |
|-----------|------|-------|-------------|
| `color.r` | Float | 0.0-1.0 | Red component |
| `color.g` | Float | 0.0-1.0 | Green component |
| `color.b` | Float | 0.0-1.0 | Blue component |
| `intensity` | Float | 0.0-1.0 | Light strength |

**Example**:
```conf
ambient: {
    color: { r: 0.8; g: 0.8; b: 0.8; };
    intensity: 0.2;
};
```

---

## 💫 Lights

Array of light sources illuminating the scene.

### Directional Light

Simulates distant light source (like sunlight):

```conf
lights: (
    {
        type: "directional";
        color: {
            r: 1.0;
            g: 1.0;
            b: 1.0;
        };
        intensity: 0.8;
        direction: {
            x: 1.0;
            y: 1.0;
            z: -1.0;
        };
    }
);
```

### Point Light

Simulates local light source (like a light bulb):

```conf
lights: (
    {
        type: "point";
        color: {
            r: 1.0;
            g: 1.0;
            b: 1.0;
        };
        intensity: 1.0;
        position: {
            x: 10.0;
            y: 20.0;
            z: 10.0;
        };
    }
);
```

### Light Parameters

**Common**:
| Parameter | Type | Range | Description |
|-----------|------|-------|-------------|
| `type` | String | "directional", "point" | Light type |
| `color.r/g/b` | Float | 0.0-1.0 | RGB color |
| `intensity` | Float | 0.0-∞ | Light strength |

**Directional-specific**:
| Parameter | Type | Description |
|-----------|------|-------------|
| `direction.x/y/z` | Float | Light ray direction |

**Point-specific**:
| Parameter | Type | Description |
|-----------|------|-------------|
| `position.x/y/z` | Float | Light position |

**Multiple Lights**:
```conf
lights: (
    { type: "directional"; ... },
    { type: "directional"; ... },
    { type: "point"; ... }
);
```

---

## 🎨 Primitives

Array of 3D objects in the scene.

### Sphere

```conf
primitives: (
    {
        type: "sphere";
        position: {
            x: 0.0;
            y: 0.0;
            z: 0.0;
        };
        radius: 5.0;
        color: {
            r: 1.0;
            g: 0.0;
            b: 0.0;
        };
        material: {
            type: "flat";
        };
    }
);
```

### Plane

```conf
primitives: (
    {
        type: "plane";
        position: {
            x: 0.0;
            y: -10.0;
            z: 0.0;
        };
        normal: {
            x: 0.0;
            y: 1.0;
            z: 0.0;
        };
        color: {
            r: 0.5;
            g: 0.5;
            b: 0.5;
        };
        material: {
            type: "flat";
        };
    }
);
```

### Cylinder

```conf
primitives: (
    {
        type: "cylinder";
        position: {
            x: 5.0;
            y: 0.0;
            z: 5.0;
        };
        radius: 2.0;
        height: 10.0;
        axis: {
            x: 0.0;
            y: 1.0;
            z: 0.0;
        };
        color: {
            r: 0.0;
            g: 1.0;
            b: 0.0;
        };
        material: {
            type: "flat";
        };
    }
);
```

### Cone

```conf
primitives: (
    {
        type: "cone";
        position: {
            x: -5.0;
            y: 0.0;
            z: -5.0;
        };
        radius: 2.0;
        height: 8.0;
        axis: {
            x: 0.0;
            y: 1.0;
            z: 0.0;
        };
        color: {
            r: 1.0;
            g: 1.0;
            b: 0.0;
        };
        material: {
            type: "flat";
        };
    }
);
```

### Rectangle3D

```conf
primitives: (
    {
        type: "rectangle3d";
        position: {
            x: 0.0;
            y: 0.0;
            z: 0.0;
        };
        width: 10.0;
        height: 5.0;
        normal: {
            x: 0.0;
            y: 0.0;
            z: 1.0;
        };
        color: {
            r: 0.5;
            g: 0.0;
            b: 0.5;
        };
        material: {
            type: "flat";
        };
    }
);
```

### Transformations

Each primitive supports transformations:

Applied in this order by the factory: translation, rotation, then scale.

```conf
primitives: (
    {
        type: "sphere";
        position: { x: 0.0; y: 0.0; z: 0.0; };
        radius: 5.0;
        
        // Translation
        translation: {
            x: 5.0;
            y: 0.0;
            z: 0.0;
        };
        
        // Rotation (in degrees)
        rotation: {
            x: 0.0;
            y: 45.0;
            z: 0.0;
        };

        // Scale
        scale: {
            x: 1.0;
            y: 2.0;
            z: 1.0;
        };
        
        color: { r: 1.0; g: 0.0; b: 0.0; };
        material: { type: "flat"; };
    }
);
```

---

## 📋 Primitive Parameters

### Common to All Primitives

| Parameter | Type | Description | Default |
|-----------|------|-------------|---------|
| `type` | String | Primitive type |
| `position.x/y/z` | Float | Center position |
| `color.r/g/b` | Float | RGB color (0.0-1.0) |
| `material.type` | String | Material type |
| `scale.x/y/z` | Float | Scale factors per axis | 1.0 |

### Shape-Specific

**Sphere**:
- `radius` (Float) - Sphere radius

**Plane**:
- `normal.x/y/z` (Float) - Surface normal

**Cylinder**:
- `radius` (Float) - Base radius
- `height` (Float) - Cylinder height
- `axis.x/y/z` (Float) - Rotation axis

**Cone**:
- `radius` (Float) - Base radius
- `height` (Float) - Cone height
- `axis.x/y/z` (Float) - Rotation axis

**Rectangle3D**:
- `width` (Float) - Width
- `height` (Float) - Height
- `normal.x/y/z` (Float) - Surface normal

---

## 📐 Complete Example Scene

A simple scene with a sphere, plane, and lighting:

```conf
// Camera configuration
camera: {
    resolution: {
        width: 1280;
        height: 720;
    };
    position: {
        x: 0.0;
        y: 5.0;
        z: -30.0;
    };
    fov: 60.0;
};

// Ambient light
ambient: {
    color: {
        r: 0.8;
        g: 0.8;
        b: 0.8;
    };
    intensity: 0.2;
};

// Light sources
lights: (
    {
        type: "directional";
        color: { r: 1.0; g: 1.0; b: 1.0; };
        intensity: 0.8;
        direction: { x: 1.0; y: 2.0; z: -1.0; };
    },
    {
        type: "point";
        color: { r: 1.0; g: 0.0; b: 0.0; };
        intensity: 0.5;
        position: { x: 15.0; y: 10.0; z: -10.0; };
    }
);

// Scene objects
primitives: (
    // Ground plane
    {
        type: "plane";
        position: { x: 0.0; y: -5.0; z: 0.0; };
        normal: { x: 0.0; y: 1.0; z: 0.0; };
        color: { r: 0.5; g: 0.5; b: 0.5; };
        material: { type: "flat"; };
    },
    // Red sphere
    {
        type: "sphere";
        position: { x: -8.0; y: 0.0; z: 0.0; };
        radius: 3.0;
        color: { r: 1.0; g: 0.0; b: 0.0; };
        material: { type: "flat"; };
    },
    // Green sphere
    {
        type: "sphere";
        position: { x: 0.0; y: 2.0; z: 0.0; };
        radius: 4.0;
        color: { r: 0.0; g: 1.0; b: 0.0; };
        material: { type: "flat"; };
    },
    // Blue sphere
    {
        type: "sphere";
        position: { x: 8.0; y: 0.0; z: 0.0; };
        radius: 3.0;
        color: { r: 0.0; g: 0.0; b: 1.0; };
        material: { type: "flat"; };
    }
);
```

---

## ⚠️ Common Errors

### Missing Required Fields
```
Error: "Missing required field: camera.resolution.width"
```
**Solution**: Ensure all required fields are present.

### Invalid Color Values
```
Error: "Color values must be between 0.0 and 1.0"
```
**Solution**: Use values in range [0.0, 1.0] for RGB.

### Unknown Primitive Type
```
Error: "Unknown primitive type: 'sphere2'"
```
**Solution**: Check spelling. Valid types: sphere, plane, cylinder, cone, rectangle3d.

### Malformed Syntax
```
Error: "Parse error at line 42"
```
**Solution**: Check configuration syntax. Use `:` for assignments, `;` for termination, `,` for list separation.

---

## 💡 Tips & Tricks

1. **Color Testing**: Use RGB values 0.0-1.0. For hex colors: `hex / 255.0`
2. **Positioning**: Use negative Z for objects in front of camera
3. **Lighting**: Adjust intensity for contrast (0.2-1.0 typical)
4. **Performance**: Start with low resolution for testing
5. **Comments**: Use `//` for single-line comments

---

## 🔗 Related Documentation

- [USAGE.md](./USAGE.md) - How to run scenes
- [FEATURES.md](./FEATURES.md) - Supported features
- [ARCHITECTURE.md](./ARCHITECTURE.md) - Technical details

---

## 📚 Resources

- LibConfig++ Documentation: http://www.hyperrealm.com/libconfig/
- PPM Format: http://netpbm.sourceforge.net/doc/ppm.html
- Ray Tracing Basics: https://en.wikipedia.org/wiki/Ray_tracing

For example scene files, check the `config/` directory in the project root.
