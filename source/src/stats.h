#pragma once
#include <Arduino.h>

namespace cointhing {

class Stats {
public:
    static String toJson();
    static String utcTime();
    static String localTime();
    static String utcStart();

    static void reset();

    static bool fetchTimeAPI();
    static bool fetchWorldTimeAPI();

    static void inc_gecko_price_fetch();
    static void inc_gecko_chart_fetch();
    static void inc_gecko_price_fetch_fail();
    static void inc_gecko_chart_fetch_fail();
    static void inc_time_fetch();
    static void inc_time_fetch_fail();
    static void inc_settings_change();
    static void inc_server_requests();
    static void inc_wifi_sta_connected();
    static void inc_wifi_sta_disconnected();

    static void inc_brownout_counter();
    static void inc_crash_counter();

private:
    // time
    static String timezone;
    static time_t utc_time_start;
    static uint32_t raw_offset;
    static uint32_t dst_offset;

    // counter
    static uint32_t gecko_price_fetch;
    static uint32_t gecko_chart_fetch;
    static uint32_t gecko_price_fetch_fail;
    static uint32_t gecko_chart_fetch_fail;

    static uint32_t time_fetch;
    static uint32_t time_fetch_fail;

    static uint32_t settings_change;

    static uint32_t server_requests;

    static uint32_t wifi_sta_connected;
    static uint32_t wifi_sta_disconnected;

    static uint32_t brownout_counter;
    static uint32_t crash_counter;

    static SemaphoreHandle_t stats_sync_mutex;
};

extern Stats stats;

} // namespace cointhing