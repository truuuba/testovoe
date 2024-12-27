#ifndef COUNTER_H
#define COUNTER_H
#include <vector>
#include <string>
#include <ctime>
#include <QStringList>
#include <curl/curl.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

QStringList found_colors_(){
    //белый, чёрный, коричневый, синий, голубой, красный, жёлтый, зелёный, серый, розовый
    QStringList all_c;
    all_c << "#ffffff" << "#000000" << "#6f4e37" << "#003262" << "#76abdf" << "#ff3800" << "#ffef00" << "#228b22" << "#c0c0c0" << "#FFb7c5";
    QStringList new_c;
    srand(time(0));
    while (all_c.size() != 1){
        int ind = rand() % all_c.size();
        new_c << all_c[ind];
        all_c.erase(all_c.begin() + ind);
    }
    new_c << all_c[0];
    return new_c;
}

QString take_nazv_but(QString a){
    QString nazv;
    if (a == "#ffffff")
        nazv = "Белый";
    else if (a == "#000000")
        nazv = "Черный";
    else if (a == "#6f4e37")
        nazv = "Коричневый";
    else if (a == "#003262")
        nazv = "Синий";
    else if (a == "#76abdf")
        nazv = "Голубой";
    else if (a == "#ff3800")
        nazv = "Красный";
    else if (a == "#ffef00")
        nazv = "Желтый";
    else if (a == "#228b22")
        nazv = "Зеленый";
    else if (a == "#c0c0c0")
        nazv = "Серый";
    else
        nazv = "Розовый";

    return nazv;
}

bool prov_black(QString a){
    if ((a == "Черный") or a == ("Коричневый") or (a == "Синий"))
        return true;
    else
        return false;
}

size_t callback_srv(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

double get_temp(const std::string& city, const std::string& apiKey) {
    // Формируем URL для запроса
    std::string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";

    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback_srv);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            return -1;
        }

        try {
            json j = json::parse(readBuffer);
            double temperature = j["main"]["temp"];
            return temperature;
        } catch (const json::exception& e) {
            return -1;
        }
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return -1;
}


#endif // COUNTER_H
