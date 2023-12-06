void demo() {
    clear_screen();
    hide_cursor();
    int i = 0;
    new_rule();calc();plot();
    while(1) {
        plot();
        usleep(25000);
        i = arc4random_uniform(100);
        if (i < 85) cont(1); else { new_rule(); seed();calc();}


    }

}