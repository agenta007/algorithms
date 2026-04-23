//
// Created by neo on 4/23/26.
//

#ifndef ALGORITHMS_WALL_CONTRUCTOR_H
#define ALGORITHMS_WALL_CONTRUCTOR_H

#include <iostream>
#include <vector>
#include <algorithm> // Добавено за std::sort
#include <queue>     // Добавено за std::priority_queue

using namespace std;
const long long INF = 1e18;

struct Brick {
    int length;
    int price;
};

// Преименувано на WallPoint за избягване на конфликти
struct WallPoint {
    long long x, y;
    WallPoint(long long x, long long y) : x(x), y(y) {}
};

// Comparator function
bool compareBricksByRatio(const Brick& a, const Brick& b) {
    return (long long)a.price * b.length < (long long)b.price * a.length;
}

void sortBricks(std::vector<Brick>& bricks) {
    std::sort(bricks.begin(), bricks.end(), compareBricksByRatio);
}

struct State {
    int mod;
    long long cost;
    long long length;

    bool operator>(const State& other) const {
        if (cost == other.cost) return length > other.length;
        return cost > other.cost;
    }
};

struct DistResult {
    int best_D;
    int best_C;
    std::vector<long long> min_cost;
    std::vector<long long> min_length;
};

//takes bricks and returns distance arrays
DistResult create_dist_arrays(const std::vector<Brick>& bricks) {
    if (bricks.empty()) return {0, 0, {}, {}};

    // Взимаме най-добрата тухла (вече са сортирани)
    int D_opt = bricks[0].length;
    int C_opt = bricks[0].price;

    // min_cost[r] съхранява минималната цена, необходима за построяване на
    // дължина L, такава че L % D_opt == r. Тук D_opt е дължината на най-ефективната тухла.
    std::vector<long long> min_cost(D_opt, INF);
    // min_length[r] съхранява най-малката възможна обща дължина, с която се
    // постига остатък 'r'. Това е критично, за да сме сигурни, че търсената от нас
    // дължина L не е по-малка от минимално необходимата за този остатък (L >= min_length[r]).
    std::vector<long long> min_length(D_opt, INF);

    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

    min_cost[0] = 0;
    min_length[0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (current.cost > min_cost[current.mod]) continue;

        for (const auto& b : bricks) {
            int next_mod = (current.mod + b.length) % D_opt;
            long long next_cost = current.cost + b.price;
            long long next_len = current.length + b.length;

            if (next_cost < min_cost[next_mod] ||
               (next_cost == min_cost[next_mod] && next_len < min_length[next_mod])) {

                min_cost[next_mod] = next_cost;
                min_length[next_mod] = next_len;
                pq.push({next_mod, next_cost, next_len});
            }
        }
    }

    return {D_opt, C_opt, min_cost, min_length};
}

// Помощна функция за пресмятане на цената за запълване на дадена дължина L
long long get_min_cost_for_length(long long L, const DistResult& dist_data) {
    if (L == 0) return 0;
    int r = L % dist_data.best_D;

    if (dist_data.min_cost[r] == INF || dist_data.min_length[r] > L) {
        return INF;
    }

    return dist_data.min_cost[r] + ((L - dist_data.min_length[r]) / dist_data.best_D) * dist_data.best_C;
}

// Помощна функция за пресмятане на цената за вертикално строене
long long calc_vertical_cost(const vector<long long>& x_coords, const vector<long long>& base_y, const vector<long long>& top_y, const DistResult& dist_data) {
    long long total_cost = 0;
    for (size_t j = 0; j < x_coords.size() - 1; ++j) {
        long long h = top_y[j] - base_y[j];
        if (h > 0) {
            long long width = x_coords[j+1] - x_coords[j];
            long long c = get_min_cost_for_length(h, dist_data);

            if (c == INF) return INF; // Невъзможно да се построи тази височина

            // Защита от препълване (Overflow)
            if (INF / width < c) return INF;
            long long added = width * c;
            if (INF - total_cost < added) return INF;

            total_cost += added;
        }
    }
    return total_cost;
}

// Помощна функция за пресмятане на цената за хоризонтално строене
long long calc_horizontal_cost(const vector<long long>& x_coords, const vector<long long>& base_y, const vector<long long>& top_y, const DistResult& dist_data) {
    // 1. Намиране на всички уникални хоризонтални граници (по Y)
    vector<long long> y_coords;
    for (long long y : base_y) y_coords.push_back(y);
    for (long long y : top_y) y_coords.push_back(y);
    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());

    long long total_cost = 0;
    // 2. Разделяме на хоризонтални ивици
    for (size_t k = 0; k < y_coords.size() - 1; ++k) {
        long long y_bottom = y_coords[k];
        long long y_top = y_coords[k+1];
        long long dh = y_top - y_bottom; // Дебелина на ивицата
        if (dh <= 0) continue;

        long long current_len = 0;
        long long strip_cost = 0;

        // 3. Сканираме по X, за да намерим непрекъснатите парчета стена в тази ивица
        for (size_t j = 0; j < x_coords.size() - 1; ++j) {
            // Проверяваме дали колона 'j' съществува в текущата височина (ивица)
            if (base_y[j] <= y_bottom && top_y[j] >= y_top) {
                current_len += (x_coords[j+1] - x_coords[j]);
            } else {
                if (current_len > 0) {
                    long long c = get_min_cost_for_length(current_len, dist_data);
                    if (c == INF) return INF;
                    strip_cost += c;
                    current_len = 0;
                }
            }
        }
        // Ако остане незатворено парче в края на стената
        if (current_len > 0) {
            long long c = get_min_cost_for_length(current_len, dist_data);
            if (c == INF) return INF;
            strip_cost += c;
        }

        // Добавяме цената за тази ивица умножена по дебелината ѝ (брой редове)
        if (strip_cost > 0) {
            if (INF / dh < strip_cost) return INF;
            long long added = strip_cost * dh;
            if (INF - total_cost < added) return INF;
            total_cost += added;
        }
    }
    return total_cost;
}


// ОСНОВНАТА ФУНКЦИЯ
long long wallConstructor(long long L, const vector<Brick>& bricks, const vector<WallPoint>& M1points, const vector<WallPoint>& M2points, const DistResult& dist_data) {

    // 1. Събиране и компресиране на всички уникални X координати
    vector<long long> x_coords;
    x_coords.push_back(0);
    x_coords.push_back(L);
    for (const auto& p : M1points) x_coords.push_back(p.x);
    for (const auto& p : M2points) x_coords.push_back(p.x);

    sort(x_coords.begin(), x_coords.end());
    x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());

    // 2. Ламбда функция за превръщане на координатите в "профил на височината" (височина за всеки X интервал)
    auto get_profile = [&](const vector<WallPoint>& pts) {
        vector<long long> profile(x_coords.size() - 1, 0);
        for (size_t i = 0; i < pts.size() - 1; ++i) {
            // Интересуват ни само хоризонталните сегменти, те определят тавана
            if (pts[i].y == pts[i+1].y) {
                long long x1 = min(pts[i].x, pts[i+1].x);
                long long x2 = max(pts[i].x, pts[i+1].x);
                long long y = pts[i].y;
                for (size_t j = 0; j < x_coords.size() - 1; ++j) {
                    if (x_coords[j] >= x1 && x_coords[j+1] <= x2) {
                        profile[j] = y;
                    }
                }
            }
        }
        return profile;
    };

    // 3. Генериране на височините
    vector<long long> M1_profile = get_profile(M1points);
    vector<long long> M2_profile = get_profile(M2points);
    vector<long long> ground_profile(x_coords.size() - 1, 0); // Нулево ниво

    // --- СЦЕНАРИЙ А ---
    // Ден 1: Хоризонтално (от земята до M1)
    long long d1_horiz = calc_horizontal_cost(x_coords, ground_profile, M1_profile, dist_data);
    // Ден 2: Вертикално (от M1 до M2)
    long long d2_vert = calc_vertical_cost(x_coords, M1_profile, M2_profile, dist_data);

    long long cost_scenario_A = (d1_horiz == INF || d2_vert == INF) ? INF : d1_horiz + d2_vert;

    // --- СЦЕНАРИЙ Б ---
    // Ден 1: Вертикално (от земята до M1)
    long long d1_vert = calc_vertical_cost(x_coords, ground_profile, M1_profile, dist_data);
    // Ден 2: Хоризонтално (от M1 до M2)
    long long d2_horiz = calc_horizontal_cost(x_coords, M1_profile, M2_profile, dist_data);

    long long cost_scenario_B = (d1_vert == INF || d2_horiz == INF) ? INF : d1_vert + d2_horiz;

    // Връщаме по-евтиния вариант
    return min(cost_scenario_A, cost_scenario_B);
}

void demoWallConstructor() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++) {
        long long L;
        int N, M1, M2;
        cin >> L >> N >> M1 >> M2;

        vector<Brick> bricks;
        for (int i = 0; i < N; i++) {
            int Di, Ci;
            cin >> Di >> Ci;
            bricks.push_back({Di, Ci});
        }

        sortBricks(bricks);

        vector<WallPoint> M1points; // Обновено
        for (int i = 0; i < M1; i++) {
            long long x, y;
            cin >> x >> y;
            M1points.push_back({x, y});
        }

        vector<WallPoint> M2points; // Обновено
        for (int i = 0; i < M2; i++) {
            long long x, y;
            cin >> x >> y;
            M2points.push_back({x, y});
        }

        // Генерираме цените предварително
        DistResult dist = create_dist_arrays(bricks);

        // Пресмятаме и извеждаме минималната цена
        long long min_price = wallConstructor(L, bricks, M1points, M2points, dist);

        // Според заданието, оптималната цена не надхвърля 10^18.
        if (min_price >= INF) {
            cout << "Impossible" << endl; // Ако няма валидно решение
        } else {
            cout << min_price << endl;
        }
    }
}

#endif //ALGORITHMS_WALL_CONTRUCTOR_H