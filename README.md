# SAW (Sample Audio Weaver)

## Overview

SAW is a C++ tool that reconstructs an audio track by assembling it from short sound effects (SFX). The program analyzes an original WAV file and finds the best matching SFX pieces to recreate it, producing both a text-based sequence and a preview audio file.

## How It Works

1. **Input**: The user provides:
   - An original `.wav` file (the target track)
   - Multiple short `.wav` files (SFX) stored in an `SFXs/` folder
   - A "step" parameter that determines the size of comparison chunks

2. **Process**: 
   - Divides both the original track and all SFX files into pieces of equal size (determined by the step parameter)
   - For each piece of the original, finds the SFX piece that most closely matches it
   - Builds a sequence of the best-matching SFX pieces

3. **Output**:
   - A `.txt` file with the reconstruction sequence
   - A preview `.wav` file showing the assembled result

## Requirements

- **Audio Format**: WAV files with specific characteristics:
  - Format: PCM
  - Channels: Stereo only
  - Sample Rate: 8000 Hz
  - Bits Per Sample: 8-bit

> ⚠️ The program may not work correctly with other file formats or settings

## Output Format

The generated `.txt` file follows this encoding:
```
[STEP]~[FILENAME:INDEX:START][FILENAME:INDEX:START]...
```

Where:
- **STEP**: The step size in samples (fixed for all SFX)
- **FILENAME**: Name of the SFX file used
- **INDEX**: The piece number from the divided SFX (starting from 0)
- **START**: The starting position in samples

## Example Output
```
100~[s13587.wav:1:0][s22461.wav:104:0][s2842.wav:62:0][s288.wav:67:0]...
```

## File Structure
```
project/
├── SAW.exe
├── SFXs/
│   ├── sound1.wav
│   ├── sound2.wav
│   └── ...
└── output/
    ├── result.txt
    └── result (preview).wav
```

## Usage

1. Place all your SFX files in the `SFXs/` folder
2. Run the program
3. Enter the path to your original WAV file
4. Enter the desired output filename (will be saved as `.txt`)
5. Enter the step size (recommended range: 50-200)
6. The program will process and generate:
   - A sequence file in the `output/` folder
   - A preview WAV file for verification

## Technical Details

- **Comparison Method**: Uses absolute difference averaging between left and right channels to find the best-matching SFX piece
- **Normalization**: Audio is normalized to prevent clipping
- **Reconstruction**: The preview output is an 8-bit stereo WAV at 8000 Hz

## Limitations

- Only works with 8-bit stereo WAV files at 8000 Hz
- Requires all SFX files to be placed in the `SFXs/` folder
- Performance depends on the number of SFX files and the step size

---

**Created by: _Phan70m**
