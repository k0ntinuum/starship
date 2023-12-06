int main(void) {
    InitWindow(cols*pixel_w, rows*pixel_h, "starship");
    SetTargetFPS(60);             
    while (!WindowShouldClose())  {
        respond_raylib();
        BeginDrawing();
        plot_ca();
        EndDrawing(); 
        //usleep(arc4random_uniform(40000));
        //usleep(arc4random_uniform(50000) );
        new_rule(); mountain();calc();
    }
    CloseWindow();  
    return 0;

   // hide_cursor();
    //demo();

}