const int max_rows = 1000;
const int max_cols = 1000;
const int max_rule = 16808;
int cell[max_rows][max_cols];
int rule[max_rule];
int current_target= 0;


struct termios orig_termios;
int pixel_w = 1;
int pixel_h = 2;

int states = 3;
int len = 3;
int rule_length = 27;


int rule_mode = 0;
int rule_index = 0;
int current_setting = 0;
int hide_menu = 0;
int code_mode = 0;


int rows = 500;
int cols = 1000;
int display_mode = 0;
bool change = true;
int last_in = 0;
int second_to_last_in = 0;








