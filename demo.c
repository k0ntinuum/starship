void demo() {
    clear_screen();
    int i = 0;
    new_rule();calc();plot();
    while(1) {
        plot();
        usleep(100000);
        i = arc4random_uniform(100);
        if (i < 95) cont(1); else { new_rule(); seed();calc();}


    }

}