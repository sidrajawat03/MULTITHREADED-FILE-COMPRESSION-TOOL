# 🚀 MULTITHREADED FILE COMPRESSION TOOL

A high-performance C++ console application built to compress and decompress textual data using Run-Length Encoding (RLE) — enhanced with multithreading for faster execution.
---

##  Internship Details

🏢 **Company:** Codtech IT Solutions  
👤 **Intern:** Aradhya Verma  
🆔 **Intern ID:** CT04DZ475  
💻 **Domain:** C++ Programming  
⏳ **Duration:** 4 Weeks  
🧑‍🏫 **Mentor:** Neela Santhosh  
---

## 📖 About the Project

This tool demonstrates how parallel processing in C++ can optimize file operations. It compresses input using Run-Length Encoding, then decompresses the result using:
🧵 Single-threaded logic for baseline performance
⚡ Multithreaded execution using std::thread for speedup
⏱️ Execution times are measured for both approaches, giving a clear comparison of performance gains through concurrency.

- 🔄 **Single-threaded mode** for baseline comparison  
- 🚀 **Multithreaded mode** for enhanced speed using `std::thread`  

🔍 The tool also captures and displays precise execution time for each operation, helping you **visualize the speedup**.

---

## 🌟 Features At a Glance

✅ **Compress Files** using efficient RLE  
🧵 **Multithreaded Decompression** — each chunk handled in parallel  
⚙️ **Single-threaded Decompression** for benchmarking  
📈 **Performance Tracking** — shows time in milliseconds  
🧠 **Thread-safe Mechanism** — with `std::mutex` to avoid race conditions  
🗃️ **Clean Output Structure** — outputs stored in `compressed.txt`, `output_mt.txt`, and `output_st.txt`

---

## 🧪 Real-World Use

 This utility is ideal for experimenting with multithreaded design patterns, especially in scenarios involving large text files, log processing, or data compression pipelines.

---

## 💻 Tech Stack

**Programming Language:**  
- C++

**Core Libraries:**  
- `<iostream>`, `<fstream>`, `<vector>`, `<string>`  
- `<thread>`, `<chrono>`, `<mutex>`

**Tools:**  
- `g++` (C++11 and above with pthread support)  
- Terminal (Linux/macOS/Windows)  
- Visual Studio Code (Recommended for dev)

---

## 📁 Project Structure

```

Task\_2/
├── input.txt            # Input text file (editable)
├── compressed.txt       # Output after RLE compression
├── output\_mt.txt        # Output from multithreaded decompression
├── output\_st.txt        # Output from single-threaded decompression
├── main2.cpp            # Core source code
├── main2                # Compiled executable (after build)
├── task2\_output.png     # Sample output screenshot
└── README.md            # Documentation

````

---

## ⚙️ How to Run

### 🔧 Prerequisites

Make sure you have:

- A C++11 compatible compiler (like `g++`)
- A terminal or command prompt
- Visual Studio Code (optional, but great for debugging)

### ▶️ Compile the Code

```bash
g++ -std=c++11 -pthread main2.cpp -o main2
````

### ▶️ Run the Executable

```bash
./main2
```

You’ll see the file being compressed and decompressed, followed by printed execution times for each mode.

---

## 📸 Gallery / Output Preview

Check out the sample output and performance benchmarks here:
📎 [Issue Tracker & Screenshots](

---

## 🙌 Final Note

This project goes beyond basic compression—it’s a hands-on demonstration of efficient multithreaded architecture in C++. Whether you're optimizing file handling or exploring concurrency, this tool offers a solid foundation for deeper learning.

---

```
