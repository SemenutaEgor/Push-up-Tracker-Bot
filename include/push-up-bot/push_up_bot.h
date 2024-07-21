#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <optional>
#include <thread>
#include <mutex>

#include "api.h"

struct ShockSeries
{
    uint16_t duration = 0;
    uint16_t days = 0;
    uint64_t start;
};

struct User
{
    std::string username;
    uint32_t sum_durations;
    std::optional<ShockSeries> series;
};

struct FileConfig
{
    uint64_t offset = 0;
    std::unordered_map<int64_t, User> users;
};

class PushUpBot
{
public:
    explicit PushUpBot(std::string endpoint, std::string configName, std::string logName, int64_t channelID, int64_t adminID);
    void Run();

private:
    void SaveConfig();
    void HandleVideo(const Request &request);
    void SendReminderMessage();

    void SendLocalDuration();
    void SendDays();
    void SendGlobalDuration();
    void RemainderThreadLogic();
    void StatsThreadLogic();
    void Log(const char* msg, const char* title = "");

    const std::string endpoint_;
    const std::string configName_;
    const std::string logName_;

    const int64_t channelID_;
    const int64_t adminID_;

    std::unique_ptr<IApiTelegram> api_;

    FileConfig config_;

    std::thread remainder_thread_;
    std::thread stats_thread_;
    std::mutex mutex_;
};
