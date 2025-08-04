#ifndef KEA_ENGINE_EVENTTYPE_HPP
#define KEA_ENGINE_EVENTTYPE_HPP

#include <cstdint>

using EventType = uint32_t;

const uint32_t FNV_offset_basis = 2166136261u;
const uint32_t FNV_prime = 16777619u;

constexpr uint32_t fnv1a_hash(const char* str, uint32_t hash = FNV_offset_basis)
{
    return (*str) ? fnv1a_hash(str + 1, (hash ^ uint32_t(*str)) * FNV_prime) : hash;
}

#endif /* KEA_ENGINE_EVENTTYPE_HPP */
