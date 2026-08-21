#include "fancy_progress_bar.h"
#include <iostream>


#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

//[Co o o o o] 1%
//[---c o o o] 45%
//[------Co o] 75%
//[---------c] 100%
//[ o o o o o]
//[----      ]
//[    c     ]

using namespace std;

        void progress_bar::test() {
            cout << RED << "Nya uwu :3" << RESET << endl;
        }
        void progress_bar::step(float step_size) {
            amount += step_size;
            amount_percent = amount/end_amount * 100;
        }
        void progress_bar::draw() {
            int dashes = length * (amount/end_amount);
            cout << BLUE << bar_edge_left;
            for(int i = 0; i < dashes-1; i++) {
                cout << bar_infil;
            } 
            if(using_arch) {
                cout << YELLOW;
            }
            if(dashes != 0) {
                if(is_wakaing) {
                    cout << bar_infil_end;
                } else {
                    cout << bar_infil_end_alt;
                }
            }
            cout << WHITE;
            for(int i = 0; i < length-dashes; i++) {
                if((i+dashes)%2 == 0) {
                    cout << bar_empty;
                } else {
                    cout << bar_empty_alt;
                }
            }
            waka();
            cout << BLUE << bar_edge_right << WHITE;
            if(show_percent) {
                cout << ' ' << amount_percent << '%';
            }
            cout << RESET << flush;
        }
        void progress_bar::fill() {
            cout << BLUE << bar_edge_left;
            for(int i = 0; i < length; i++) {
                cout << bar_infil;
            }
            cout << bar_edge_right  << RESET << flush;
            amount = end_amount;
        }
        void progress_bar::reset() {
            cout << BLUE << bar_edge_left << WHITE;
            for(int i = 0; i < length; i++) {
                if(i%2 == 0) {
                    cout << bar_empty;
                } else {
                    cout << bar_empty_alt;
                }
            }
            cout << BLUE << bar_edge_right << RESET << flush;
            amount = 0;
        }
        void clear() {
            cout << '\r';
        }
        void progress_bar::waka() {
            if(is_wakaing) {
                is_wakaing = false;
            } else {
                is_wakaing = true;
            }
        }
        void progress_bar::start() {

        }
        void progress_bar::end() {

        }