#pragma once
#include <fstream>
#include <string>
#include <stdexcept>

class StructManager
{
private:
    std::string m_path;

public:
    StructManager(std::string path = "record.dat");
    void SetPath(std::string path);
    std::string GetPath();

    template<typename T>
    int Save(T& entity) const;

    template<typename T>
    int Read(T* entity) const;
};

template<typename T>
int StructManager::Save(T& entity) const
{
    std::ofstream wf(m_path, std::ios::out | std::ios::binary);
    if (!wf)
        throw std::runtime_error("Cannot open the file to write. Target path: " + m_path);

    wf.write((char*)&entity, sizeof(T));

    wf.close();
    if (!wf.good())
        throw std::runtime_error("Error occurred while writing to " + m_path);

    return 0;
}

template<typename T>
int StructManager::Read(T* entity) const
{
    std::ifstream rf(m_path, std::ios::out | std::ios::binary);
    if (!rf) {
        throw std::runtime_error("Cannot open the file to read. Target path: " + m_path);
        return 1;
    }

    rf.read((char*)entity, sizeof(T));

    rf.close();
    if (!rf.good()) {
        throw std::runtime_error("Error occurred while reading from " + m_path);
        return 1;
    }

    return 0;
}