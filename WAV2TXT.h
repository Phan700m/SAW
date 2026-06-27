#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cmath>

struct WAVHeader {
    // RIFF заголовок
    char chunkID[4];        // "RIFF"
    uint32_t chunkSize;     // Размер файла - 8
    char format[4];         // "WAVE"

    // fmt подзаголовок
    char subchunk1ID[4];    // "fmt "
    uint32_t subchunk1Size; // 16 для PCM
    uint16_t audioFormat;   // 1 для PCM
    uint16_t numChannels;   // 1 - моно, 2 - стерео
    uint32_t sampleRate;    // Частота дискретизации
    uint32_t byteRate;      // sampleRate * numChannels * bitsPerSample/8
    uint16_t blockAlign;    // numChannels * bitsPerSample/8
    uint16_t bitsPerSample; // 8, 16, 24, 32

    // data подзаголовок
    char subchunk2ID[4];    // "data"
    uint32_t subchunk2Size; // Размер данных
};

class WAVConverter {
public:

    std::pair<std::vector<char>, std::vector<char>> convertToChannels(const std::string& filename);

private:

    std::pair<std::vector<char>, std::vector<char>> extractChannels(
        const std::vector<char>& audioData,
        uint16_t numChannels,
        uint16_t bitsPerSample);
};