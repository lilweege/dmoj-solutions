??=include <stdio.h>

void Hello() ??< printf(__func__); ??>
void World() ??< printf(__func__); ??>

int main() ??<
	int one = NULL==NULL;
	int two = one << one;
	int four = one << two;
	int eight = two << two;
	int space = two << four;
	int bang = space bitor one;
	int comma = space bitor eight bitor four;
	Hello();
	putchar(comma);
	putchar(space);
	World();
	putchar(bang);
??>