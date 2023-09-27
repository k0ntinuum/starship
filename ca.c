void print_symbol(int s) {
	switch (s) {
		case 0: printf("O");break;
		case 1: printf("1");break;
		case 2: printf("2");break;
		case 3: printf("3");break;
		case 4: printf("4");break;
	}
}
void print_block(int code) {
	switch (code) {
        case 0 : set_color(0,0,0);break;
        case 1 : set_color(255,255,255);break;
		case 2 : set_color(255,0,0);break;
		case 3 : set_color(0,255,255);break;
		case 4 : set_color(0,255,0);break;
    }
	printf("\u2588");
}
void seed() {
	for (int c = 0; c < cols; c++) {
		cell[0][c] = rand()%states;
	}
}
int f(int x, int b) {
	int s = 1;
	for (int j = 0; j < x; j++) {
		s *= b;
	}
	return s;
}
int safe_col(int x) {
	if (x < 0) return x + cols;
	if (x > cols - 1) return x - cols;
	return x;
}
int code(int r, int c) {
	int sum = 0;
	int start = c - len/2;
	for (int k = 0; k < len; k++) {
		sum += f(k,states)*cell[r-1][safe_col( start + k)];
	}
	return sum;
}
void calc() {
	for (int r = 1; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			cell[r][c] = rule[code(r,c)];
		}
	}
}
void plot_pixel(int r, int c, int col) {
	switch (display_mode) {
		case 0 : print_block(cell[r][c]);break;
		case 1 : print_symbol(cell[r][c]);break;
		case 2 : printf("%d",cell[r][c]);break;
	}
    
}
void plot_row(int r) {
	cursor_to(r+2,2);
	for (int c = 0 ; c < cols; c++) {
		plot_pixel(r,c, cell[r][c]);
	}
}
void plot() {
	for (int r = rows -1; r > -1; r--) {
		cursor_to(r+2,2);
		plot_row(r);
	}
	set_color(255,255,255);
	cursor_to(rows+3,2);
	for (int i = 0; i  < rule_length; i++ ) {
		cursor_to(rows+3 + i/64,i%64 +2);
		if (current_target == i) start_reverse_text();
		print_symbol(rule[i]);
		if (current_target == i) stop_reverse_text();
	}
	printf("\n");
}
void new_rule() {
	rule_length = f(len,states);
	current_target = 0;
	for (int i = 0; i < rule_length; i++) {
		rule[i] = rand()%states;
	}
}
void cont(int n) {
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0; j < cols; j++) {
			cell[0][j] = cell[rows-1][j];
		}
		calc();
		plot();
	}
}
void mountain() {
	for (int j = 0; j < cols; j++) {
			cell[0][j] = 0;
	}
	cell[0][cols/2] = rand()%states;
	calc();
	plot();
}


