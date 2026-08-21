#ifndef FANCY_PROGRESS_BAR_H
#define FANCY_PROGRESS_BAR_H

class progress_bar {
    public:
        float end_amount = 0;
        float amount = 0;
        int amount_percent = 0;
        int length = 10;
        float ping_time_ms = 0;
        bool show_percent = true;
        bool show_amount = true;
        bool show_time_estimate = true;
        bool using_arch = true;

        char bar_edge_left = '[';
        char bar_edge_right = ']';
        char bar_empty = ' ';
        char bar_empty_alt = 'o';
        char bar_infil = '-';
        char bar_infil_end = 'C';
        char bar_infil_end_alt = 'c';

        void test();
        void step(float step_size);
        void draw();
        void fill();
        void reset();
        void clear();
        void waka();
        void start();
        void end();
    private:
        bool is_wakaing = false;
};

#endif