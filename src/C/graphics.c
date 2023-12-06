


Color color_from(int i) {
    int h = 100;
    switch (i) {
        case 0 : return (Color){.r = 0, .g = 0, .b = 0, .a = 255};break;
        case 1 : return (Color){.r = 255, .g = 255, .b = 255, .a = 255};break;
        case 2 : return (Color){.r = h, .g = h, .b = h, .a = 255};break;
        default : return (Color){.r = 255, .g = 255, .b = 255, .a = 255};break;
    }
}

void plot_ca() {
    for (int r = 0; r < rows ; r++) for (int c = 0 ; c < cols ; c++ ) 
        DrawRectangle( c*pixel_w, r*pixel_h, pixel_w,  pixel_h, color_from(cell[r][c]));
}