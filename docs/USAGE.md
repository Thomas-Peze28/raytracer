# 🚀 USAGE.md

## Running the Raytracer

The raytracer generates images from scene configuration files and outputs the result in PPM format.

---

## Command Line Syntax

```bash
./raytracer <SCENE_FILE> [-f <OUTPUT_FILE_NAME>]
```

### Parameters

| Parameter | Description | Required |
|-----------|-------------|----------|
| `<SCENE_FILE>` | Path to the scene configuration file | ✅ Yes |
| `-f <OUTPUT_FILE_NAME>` | Output file name (without extension) | ❌ No |

### Default Behavior

- If no output file is specified, the default is `output.ppm`
- The `.ppm` extension is added automatically

---

## Examples

### Basic Usage
```bash
./raytracer config/config.rtx
```
Renders `config/config.rtx` and saves to `output.ppm`

### With Custom Output File
```bash
./raytracer config/config.rtx -f my_render
```
Renders and saves to `my_render.ppm`

### Help
```bash
./raytracer -h
# or
./raytracer --help
```
Displays usage information.

---

## Output

### PPM File Format

The raytracer outputs images in **Portable PixMap (PPM)** format:
- Human-readable text format
- Easy to convert to other formats (PNG, JPEG, etc.)
- Supported by most image viewers

### Conversion to Other Formats

Convert PPM to PNG using `ImageMagick`:
```bash
convert output.ppm output.png
```

Convert using `ffmpeg`:
```bash
ffmpeg -i output.ppm output.png
```

---

## Rendering Progress

While the raytracer processes your scene, you'll see a progress bar:
```
Rendering [████████████░░░░░░░░░░░░░░░░░░░░] 45%
```

---

## Troubleshooting

### Error: "Could not open output file"
- Check that the directory exists
- Verify write permissions on the destination path
- Ensure the filename is valid

### Error: "Invalid scene file"
- Verify the scene file path is correct
- Check the scene file format (see [SCENE_FORMAT.md](./SCENE_FORMAT.md))
- Ensure all required fields are present

### No image generated
- Check that the scene has at least one camera and one primitive
- Verify lighting is properly configured
- Review error messages in the console

---

## Exit Codes

| Code | Meaning |
|------|---------|
| `0` | Success / Help displayed |
| `1` | (Internal state) |
| `84` | Error (invalid arguments, file issues, or runtime error) |

---

## Performance Tips

1. **Start Small**: Use a low-resolution camera for testing
2. **Optimize Scenes**: Remove unnecessary objects
3. **Use Transformations**: Cache complex geometry
4. **Check Lighting**: Reduce the number of lights for faster renders

For more advanced features, see [FEATURES.md](./FEATURES.md).
