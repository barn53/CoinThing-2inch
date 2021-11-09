#pragma once
#include "trace.h"
#include <Arduino.h>

namespace cointhing {

enum class NumberFormat : uint8_t {
    THOUSAND_DOT_DECIMAL_COMMA = 0, // 1.000,00
    THOUSAND_BLANK_DECIMAL_COMMA, // 1 000,00
    DECIMAL_COMMA, // 1000,00
    THOUSAND_COMMA_DECIMAL_DOT, // 1,000.00
    THOUSAND_BLANK_DECIMAL_DOT, // 1 000.00
    DECIMAL_DOT // 1000.00
};
void formatNumber(float n, String& s, NumberFormat format, bool forceSign, bool dash00, uint8_t forceDecimalPlaces = std::numeric_limits<uint8_t>::max());

class MutexGuard {
public:
    MutexGuard(SemaphoreHandle_t mutex)
        : m_guard(mutex)
    {
        xSemaphoreTake(m_guard, portMAX_DELAY);
    }
    ~MutexGuard()
    {
        xSemaphoreGive(m_guard);
    }

private:
    SemaphoreHandle_t m_guard;
};

class RecursiveMutexGuard {
public:
    RecursiveMutexGuard(SemaphoreHandle_t recursiveMutex)
        : m_guard(recursiveMutex)
    {
        xSemaphoreTakeRecursive(m_guard, portMAX_DELAY);
    }
    ~RecursiveMutexGuard()
    {
        xSemaphoreGiveRecursive(m_guard);
    }

private:
    SemaphoreHandle_t m_guard;
};

} // namespace cointhing