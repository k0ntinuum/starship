void demo() {
    clear_screen();
    hide_cursor();
    int i = 0;
    new_rule();calc();plot();
    while(1) {
        plot();
        //usleep(25000);
        usleep(arc4random_uniform(10000));
        //usleep(20000 + arc4random_uniform(17000));
        new_rule(); mountain();calc();
        //i = arc4random_uniform(100);
        //if (i < 50) cont(1); else { new_rule(); seed();calc();}


    }

}