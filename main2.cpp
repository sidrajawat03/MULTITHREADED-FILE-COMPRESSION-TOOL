#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <sstream>
#include <functional> // for ref, cref
#include <cctype>     // for isdigit

using namespace std;
using namespace chrono;

mutex lockObj;

// Function to compress using Run-Length Encoding
string compressRLE(const string& input) {
    stringstream encoded;
    int count = 1;

    for (size_t i = 1; i <= input.size(); ++i) {
        if (i < input.size() && input[i] == input[i - 1]) {
            count++;
        } else {
            encoded << input[i - 1] << count;
            count = 1;
        }
    }

    return encoded.str();
}

// Function to decompress a chunk (used by threads)
void decompressSegment(const string& data, int begin, int finish, string& output) {
    string partial;
    for (int i = begin; i < finish;) {
        char symbol = data[i++];
        string countStr;

        while (i < finish && isdigit(static_cast<unsigned char>(data[i]))) {
            countStr += data[i++];
        }

        if (!countStr.empty()) {
            int count = stoi(countStr);
            partial += string(count, symbol);
        }
    }

    lock_guard<mutex> guard(lockObj);
    output += partial;
}

// Single-threaded decompression
string decompressSequential(const string& data) {
    string result;
    for (size_t i = 0; i < data.size();) {
        char symbol = data[i++];
        string countStr;

        while (i < data.size() && isdigit(static_cast<unsigned char>(data[i]))) {
            countStr += data[i++];
        }

        if (!countStr.empty()) {
            int count = stoi(countStr);
            result += string(count, symbol);
        }
    }

    return result;
}

int main() {
    // Step 1: Read original input
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input.txt\n";
        return 1;
    }

    string rawData((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    // Step 2: Compress and save
    string compressedData = compressRLE(rawData);
    ofstream compressedFile("compressed.txt");
    compressedFile << compressedData;
    compressedFile.close();

    // Step 3: Multi-threaded decompression
    string decompressedMT;
    int splitIndex = compressedData.size() / 2;

    // Ensure split is at a symbol boundary, not inside a number
    while (splitIndex > 0 && isdigit(static_cast<unsigned char>(compressedData[splitIndex]))) {
        splitIndex--;
    }

    auto mtStart = high_resolution_clock::now();
    thread worker1(&decompressSegment, cref(compressedData), 0, splitIndex, ref(decompressedMT));
    thread worker2(&decompressSegment, cref(compressedData), splitIndex, (int)compressedData.size(), ref(decompressedMT));
    worker1.join();
    worker2.join();
    auto mtEnd = high_resolution_clock::now();
    auto mtDuration = duration_cast<milliseconds>(mtEnd - mtStart).count();

    ofstream mtOutput("output_mt.txt");
    mtOutput << decompressedMT;
    mtOutput.close();

    // Step 4: Single-threaded decompression
    auto stStart = high_resolution_clock::now();
    string decompressedST = decompressSequential(compressedData);
    auto stEnd = high_resolution_clock::now();
    auto stDuration = duration_cast<milliseconds>(stEnd - stStart).count();

    ofstream stOutput("output_st.txt");
    stOutput << decompressedST;
    stOutput.close();

    // Step 5: Display results
    cout << " Compression complete. Saved to compressed.txt\n";
    cout << " Multi-threaded Decompression Time: " << mtDuration << " ms\n";
    cout << " Single-threaded Decompression Time: " << stDuration << " ms\n";
    cout << " Outputs saved to output_mt.txt and output_st.txt\n";

    return 0;
}
