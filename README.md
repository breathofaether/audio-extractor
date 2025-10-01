# Audio Extractor in C

A C program that extracts audio from video files using [FFmpeg](https://ffmpeg.org/) and [FFprobe](https://ffmpeg.org/ffprobe.html).  
The program also supports **mono/stereo conversion**, displays **video metadata**, and shows **real-time FFmpeg output**.

---

## Features

- Extracts audio from video files (`.mp4`, `.mkv`, etc.)  
- Supports multiple output audio formats (`.mp3`, `.wav`, `.aac`)  
- Optionally convert audio to **mono** (1 channel) or **stereo** (2 channels)  
- Displays **input video metadata** (codec, audio channels) using FFprobe  
- Shows **real-time conversion logs** from FFmpeg  
- Written in **C**, demonstrating arrays, pointers, user input, and process control  

---

## Prerequisites

- **FFmpeg** and **FFprobe** installed and available in your system PATH  
  - [Windows installation guide](https://ffmpeg.org/download.html)  
  - [Linux installation guide](https://ffmpeg.org/download.html)  
  - [Mac installation guide](https://ffmpeg.org/download.html)  

- A C compiler (e.g., `gcc`)  

---

## How to Use

1. **Clone the repository** or download the source code:

```bash
git clone https://github.com/yourusername/audio-extractor-c.git
cd audio-extractor-c
```

2. **Compile** the program
   
```bash
gcc main.c -o audio_extract
```

3. **Place your video file in the same folder as the compiled program.**

4. **Run the program:**
   
```bash
./audio_extract   # Linux/Mac
audio_extract.exe # Windows
```
6. **Follow the prompts.**

---

## Example Session

```lua
Enter input video filename: sample.mp4
Fetching metadata...
codec_name=h264
channels=2

Enter output audio filename (e.g., output.mp3): sample_audio.mp3

Choose audio channel option:
1. Keep original
2. Convert to mono (1 channel)
3. Convert to stereo (2 channels)
Enter choice: 2

Running command:
ffmpeg -i "sample.mp4" -q:a 0 -ac 1 -map a "sample_audio.mp3"

[ffmpeg output displayed here]

Done! Audio saved as sample_audio.mp3
```
