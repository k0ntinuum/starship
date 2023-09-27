

char getch() {
    char c = '\0';
    if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) die("read");
    return c;
}
void flash() {
    clear_screen();
    seed();
    calc();
    plot();
}
int too_much() {
    if (f(states, len) > max_rule-1 ) return 1;
    return 0;
}

void respond() {
    int c = getch();
    if (last_in == 91 && second_to_last_in == 27) {
        switch (c) {
            case 65 : 
                rule[current_target]++;
                if (rule[current_target] > states - 1) rule[current_target] = 0;
                calc();plot();break;
            case 66 : 
                rule[current_target]--;
                if (rule[current_target] < 0) rule[current_target] = states -1; 
                calc();plot();break;
            case 67 : current_target++; if (current_target > rule_length -1) current_target = 0; plot();break;
            case 68 : current_target--; if (current_target < 0) current_target = rule_length -1; plot();break;
        }

    }
    switch (c) {
        case 'r': new_rule();calc();plot();break;
        case ' ': flash();break;
        case 'q': stop_raw_mode();exit(0);break;
        case '=': cols++; if (cols >= max_cols) cols = 1;flash();break;
        case '+': cols--; if (cols < 0 ) cols = max_cols - 1;flash();break;
        case '-': rows++; if (rows >= max_rows) rows = 1;flash();break;
        case '_': rows--; if (rows < 0 ) rows = max_rows - 1;flash();break;
        case 'c': cont(1);break;
        case 'm': mountain();break;
        case 'M': new_rule();mountain();break;
        case 's': states++; if (states > 3) states = 2; new_rule();flash();break;
        case 'l': len++; if (len > 9) len = 2;new_rule();flash();break;
    }
    second_to_last_in = last_in;
    last_in = c;
}