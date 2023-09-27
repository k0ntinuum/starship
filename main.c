int main(void) {
    start_raw_mode();
    new_rule();
    hide_cursor();
    flash();
    for (;;) respond();
}