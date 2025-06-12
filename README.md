# 🖼️ Image to ASCII Converter in C

This project is a simple image-to-ASCII converter written in C. It reads a BMP image file (24-bit Bitmap format) and converts its pixel intensities into ASCII characters to generate a textual representation of the image. Additionally, it generates a grayscale `.pgm` image output.

## 🚀 Features

- Supports **24-bit BMP images only** (preserves raw pixel data).
- Converts color pixel intensities to grayscale.
- Maps grayscale values to a set of 72 ASCII characters based on brightness.
- Outputs both:
  - A `.txt` file containing the ASCII art.
  - A `.pgm` file representing the grayscale image for visualization.

---

## 📁 Input Format

> The image **must be in `.bmp` format** with 24-bit depth. This ensures the pixel data is preserved without compression.

The code currently reads from a file named `einstein.bmp`. Make sure to place your image in the same directory and rename it accordingly.

---

## 📦 Output Files

- `pic1.txt` → ASCII art output.
- `pgmimg2.pgm` → Grayscale `.pgm` image representation.
- `cat2.bmp` → Rewritten BMP file (intermediate/debugging use).

---

## 🛠️ Dependencies

- Standard C compiler (`gcc` or any other)
- No external libraries required

---

## 🧠 How It Works

1. **Reads BMP Header**: Extracts image metadata like width, height, bit count, and pixel offset.
2. **Processes Pixels**: Reads raw RGB pixel data and calculates perceived intensity using the formula:
   ```intensity = 0.2126 * R + 0.7152 * G + 0.0722 * B```
3. **Maps to ASCII**: Scales the intensity to match one of 72 ASCII characters.
4. **Generates Output**: Writes the ASCII values to `pic1.txt` and grayscale pixel values to `pgmimg2.pgm`.

---

### 🔨 Compile the Code

```bash
gcc -o img2ascii img2ascii.c
```
### ▶️ Run the Program
```bash
./img2ascii
```
Make sure your image.bmp is in the same folder as the program.

---
### 🧪 Known Limitations
-Only works with BMP images (no support for JPG, PNG, etc.)
-No resizing or dithering applied to maintain image integrity
-Output quality may degrade for high-resolution images
