const int max_rows = 50;
const int max_cols = 500;
const int max_rule = 16808;
int cell[max_rows][max_cols];
int rule[max_rule];
int current_target= 0;


struct termios orig_termios;
int rule_length = 8;
int rule_mode = 0;
int rule_index = 0;
int current_setting = 0;
int hide_menu = 0;
int code_mode = 0;
int states = 3;
int len = 3;
int rows = 24;
int cols = 60;
int display_mode = 0;
bool change = true;
int last_in = 0;
int second_to_last_in = 0;








