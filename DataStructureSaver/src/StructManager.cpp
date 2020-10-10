#include "pch.h"
#include "StructManager.h"

StructManager::StructManager(std::string path) : m_path(path) {};

void StructManager::SetPath(std::string path)
{
    m_path = path;
}

std::string StructManager::GetPath()
{
    return m_path;
}